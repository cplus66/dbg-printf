#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <strings.h>
#include <stdarg.h>

#define BUF_SIZE 128

void dbg_printf(const char *fmt , ...)
{
	va_list arg_ptr;
	char buf[BUF_SIZE];
	struct timeval myTime;
	struct tm *time_st;
	int len;

	gettimeofday( &myTime, NULL );
	time_st = localtime( &myTime.tv_sec );

	len = sprintf(buf,"%d/%02d/%02d %02d:%02d:%02d.%06d ", time_st->tm_year+1900, time_st->tm_mon+1,time_st->tm_mday,
		time_st->tm_hour,time_st->tm_min,time_st->tm_sec,(int)myTime.tv_usec);

	va_start (arg_ptr, fmt);
	vsprintf (buf+len, fmt, arg_ptr);
	va_end (arg_ptr);

	printf("%s",buf);
	fflush(NULL);
}
