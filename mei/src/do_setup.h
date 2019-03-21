/*
 * do_setup.h
 *
 *  Created on: Mar 21, 2019
 *      Author: mark
 */

#ifndef DO_SETUP_H_
#define DO_SETUP_H_



#endif /* DO_SETUP_H_ */

do_setup(){

	int fd;
	fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
	write(fd,MEI_GETMODEL,2);
	write(fd,MEI_GETBOOTVER,2);
	write(fd,MEI_GETAPPVER,2);
	write(fd,MEI_GETVERSION,2);
	write(fd,MEI_GETSERIAL,2);
	write(fd,MEI_GETVARNAME,2);

	return(0);
}
