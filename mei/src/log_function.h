/*
 * log_function.h
 *
 *  Created on: Mar 21, 2019
 *      Author: mark
 */

#ifndef LOG_FUNCTION_H_
#define LOG_FUNCTION_H_



#endif /* LOG_FUNCTION_H_ */
void log_function(char *log_message){


			struct timespec ts;
		    timespec_get(&ts, TIME_UTC);
		    char buff[100];
		    strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

			FILE *mei_log = NULL; //declare File Pointer
			mei_log = fopen("/var/log/mei.log", "a");

			//printf("\nlog_message = %s\n",log_message);
			char *Mytime_fmt = " %s.%09ld ";
			char MyTime[27];
			sprintf(MyTime, Mytime_fmt, buff,ts.tv_nsec); //Format and apply data

			int MyTimeLen = 0;
			MyTimeLen = strlen(MyTime);

			fwrite(MyTime,1,MyTimeLen,mei_log);
			fwrite(log_message,1,strlen(log_message),mei_log);
			fwrite("\n",1,2,mei_log);
			fclose(mei_log);


return;
}
