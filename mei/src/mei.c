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
#include <stdbool.h>

#include "close.h"
#include "command.h"
#include "crcxor.h"
#include "detect.h"
#include "download.h"
#include "do_setup.h"
#include "do_monitor.h"
#include "do_request.h"
#include "do_download.h"
#include "do_sleep.h"
#include "get_stats.h"
#include "get_status.h"
#include "get_info.h"
#include "log_function.h"
#include "mei_comm.h"
#include "mei_Constants.h"
#include "process_poll.h"
#include "session_add.h"
#include "session_reset.h"
#include "set_status.h"
#include "setup_comm_port.h"
#include "reply_from_mei.h"


volatile int STOP=FALSE;


int main(void) {

	int MEI_detected = 0;
	char *MEI_Status = {0};

	if (setup_comm_port() == 0){ //lets setup the comm port and if it fails we
		exit(1);                 // will bail out with an error
	}


	if (detect(MEI_detected) == 0){  //detect the MEI unit and get all info
		exit(1);                 //Just like above if it fails bail with error
	}
	MEI_detected = 1;                //ok we are talking to the MEI lets set the connected flag

	MEI_Status = get_status(); //lets get the current status of the MEI

/*
==============================================================================
This is the main loop of the program. If we get through the Comm port setup
and the detection of the MEI unit and the setup of the MEI unit.
we will look for commands or responses from the MEI unit ad process them
Until a request for termination.
==============================================================================
 */

while(1){



}

exit(0);

}
