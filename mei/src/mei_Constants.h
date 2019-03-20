/*
 * mei_Constants.h
 *
 *  Created on: Mar 20, 2019
 *      Author: mark
 */

#ifndef MEI_CONSTANTS_H_
#define MEI_CONSTANTS_H_



#endif /* MEI_CONSTANTS_H_ */



/* MEI Constants */

	// Byte 0 Status
	unsigned MEI_ACCEPTING = 0x02;
	unsigned MEI_ESCROW    = 0x04;
	unsigned MEI_STACKING  = 0x08;
	unsigned MEI_STACKED   = 0x10;
	unsigned MEI_RETURNING = 0x20;
	unsigned MEI_RETURNED  = 0x40;
	// Byte 1 Status
	unsigned MEI_CHEATED   = 0x01;
	unsigned MEI_REJECTED  = 0x02;
	unsigned MEI_JAM	   = 0x04;
	unsigned MEI_FULL	   = 0x08;
	unsigned MEI_CASSETTE  = 0x10;
	// Byte 2 Status
	unsigned MEI_POWERUP   = 0x01;
	unsigned MEI_FAILURE   = 0x04;
	// Byte 3 Status
	unsigned MEI_DOWNLOADING = 0x02;
	// Commands
	unsigned MEI_POLL      = 0x10;
	unsigned MEI_STACK     = 0x30;
	unsigned MEI_RETURN    = 0x50;
	// Command Types
	unsigned MEI_CMD       = 0x10;
//	unsigned MEI_REPLY     = 0x20;
	unsigned MEI_DOWNLOAD  = 0x50;
	unsigned MEI_AUX       = 0x60;
	// Auxiliary command sub-types
	unsigned MEI_GETMODEL  = 0x04;
	unsigned MEI_GETSERIAL = 0x05;
	unsigned MEI_GETBOOTVER	= 0x06;
	unsigned MEI_GETAPPVER = 0x07;
	unsigned MEI_GETVARNAME	= 0x08;
	unsigned MEI_GETVERSION	= 0x09;
	unsigned MEI_GETQP		= 0x0B;
	unsigned MEI_GETPERF   =  0x0C;
	unsigned MEI_GETBNF		= 0x10;
	unsigned MEI_RESET		= 0x7F;
	unsigned MEI_EXT       =  0x70;
	// Extension command sub-types
	unsigned MEI_GETBILLS  =  0x02;
	unsigned MEI_RETRIEVE  =  0x0B;
	unsigned MEI_BOOKMARK  =  0x0D;
