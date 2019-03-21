/*
 ============================================================================
 Name        : mei.c
 Author      : Mark Meadows
 Version     : 00.00.01
 Copyright   : (c) Copyright 2019 FK Security Group, All rights reserved.
 Description : mei validator driver in C, Ansi-style
 ============================================================================
 */


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/types.h>

#include "mei_Constants.h"
#include "reply_from_mei.h"
#include "do_setup.h"
#include "do_monitor.h"
#include "get_stats.h"
#include "process_poll.h"
#include "do_request.h"
#include "session_add.h"
#include "mei_comm.h"
#include "crcxor.h"
#include "set_status.h"
#include "command.h"
#include "session_reset.h"
#include "do_download.h"
#include "detect.h"
#include "log_function.h"
#include "setup_comm_port.h"

volatile int STOP=FALSE;


int main(void) {




		int fd;
		int res;
		struct termios oldtio,newtio;
		char buf[255] = {0};
		int numofcr = 1;
		char USBGPIO_Version[255] = {0};
		/*
		Open GPIO device for reading and writing and not as controlling tty
		because we don't want to get killed if linenoise sends CTRL−C.
		*/
		fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
		if (fd <0)
				{
			    perror(MODEMDEVICE);
			    printf("Could not open Comm port");
			    exit(1);
			   	}
		tcgetattr(fd,&oldtio); /* save current serial port settings */
		bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */
		/*
		BAUDRATE: Set bps rate. You could also use cfsetispeed and cfsetospeed.
		CRTSCTS : output hardware flow control (only used if the cable has
		all necessary lines. See sect. 7 of Serial−HOWTO)
		CS8
		: 8n1 (8bit,no parity,1 stopbit)
		CLOCAL
		CREAD
		: local connection, no modem contol
		: enable receiving characters
		*/
		newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
		/*
		IGNPAR
		ICRNL
		: ignore bytes with parity errors
		: map CR to NL (otherwise a CR input on the other computer
		will not terminate input)
		otherwise make device raw (no other input processing)
		*/
		newtio.c_iflag = IGNPAR | ICRNL;
		/*
		Raw output.
		*/
		newtio.c_oflag = 0;
		/*
		ICANON : enable canonical input
		disable all echo functionality, and don't send signals to calling program
		*/
		newtio.c_lflag = ICANON;
		/*
		initialize all control characters
		default values can be found in /usr/include/termios.h, and are given
		in the comments, but we don't need them here
		*/
		newtio.c_cc[VINTR] = 0;
		newtio.c_cc[VQUIT] = 0;
		newtio.c_cc[VERASE] = 0;
		newtio.c_cc[VKILL] = 0 ;
		newtio.c_cc[VEOF] = 4;
		newtio.c_cc[VTIME] = 0;
		newtio.c_cc[VMIN] = 1;
		newtio.c_cc[VSWTC] = 0;
		newtio.c_cc[VSTART] = 0;
		newtio.c_cc[VSTOP] = 0;
		newtio.c_cc[VSUSP] = 0;
		newtio.c_cc[VEOL] = 0;
		newtio.c_cc[VREPRINT] = 0;
		newtio.c_cc[VDISCARD] = 0;
		newtio.c_cc[VWERASE] = 0;
		newtio.c_cc[VLNEXT] = 0;
		newtio.c_cc[VEOL2] = 0;
		/*
		now clean the modem line and activate the settings for the port r
		*/
		tcflush(fd, TCIFLUSH);
		tcsetattr(fd,TCSANOW,&newtio);
		/*
		terminal settings done, now handle input
		In this example, inputting a 'z' at the beginning of a line will
		exit the program.
		*/

		write(fd,"ver\n",4); //Ask for the Version of USB Firmware


		while (STOP==FALSE) {
		/* loop until we have a terminating condition */
		/* read blocks program execution until a line terminating character is
		input, even if more than 255 chars are input. If the number
		of characters read is smaller than the number of chars available,
		subsequent reads will return the remaining chars. res will be set
		to the actual number of characters actually read */
		res = read(fd,buf,255);
		buf[res]=0;
		                                                  /* set end of string, so we can printf */
		if(numofcr >= 2) {										//This is the data we want
			//printf("%s", buf);                                //Stop printing everything
			strncpy(USBGPIO_Version,buf,strlen(buf)-1);			// Copy our data minus the new line character because we don't want that
		                  }
		                                                        //if (buf[0]=='\n') STOP=TRUE;
		if (buf[0]=='\n'){                                      //if buf has a '\n' new line character increment the line counter
			numofcr = numofcr + 1;								//if there are 2 or more out data is in the buffer so bail out
			if (numofcr >= 3) {
				STOP=TRUE;
			}

						  }
							}

		write(fd,"stuff ffff\n",16);


		close(fd);






}
