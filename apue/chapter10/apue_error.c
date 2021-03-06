#include "../apue.h"
#include <errno.h>
#include <stdarg.h>

static void err_doit(int,int,const char *,va_list);

void err_ret(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
}

void err_sys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
	exit(1);
}

void err_exit(int error, const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(1,error,fmt,ap);
	va_end(ap);
	exit(1);
}

/****************************************************************
*Fatal error related to a system call
*Print a massage,dump core,and terminate.
*******************************************************************/
void err_dump(const char *fmt, ...)
{
	va_list ap;
	
	va_start(ap,fmt);
	err_doit(1,errno,fmt,ap);
	va_end(ap);
	abort();
	exit(1);
}

/************************************************************************
  ***Nonfatal error unrelated to a system call.
  ****Print a message and terminate.
*************************************************************************/

void err_msg(const char *fmt, ...)
{
	va_list ap;

	va_start(ap,fmt);
	err_doit(0,0,fmt,ap);
	va_end(ap);
}

/**************************************************************************
  ****Fatal error unrelated to a system call.
  ****Print a message and terminate.
  *************************************************************************/
void err_quit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	err_doit(0,0,fmt,ap);
	va_end(ap);
	exit(1);
}

/*************************************************************************
  **Print a message and return to caller.
  ***Caller specifies "errnoflag".
  **********************************************************************/

static void err_doit(int errnoflag,int error, const char *fmt, va_list ap)
{
	char buf[MAXLINE];
	vsnprintf(buf,MAXLINE,fmt,ap);
	if(errnoflag)
		snprintf(buf+strlen(buf),MAXLINE-strlen(buf),":%s",strerror(error));
	strcat(buf,"\n");
	fflush(stdout);
	fputs(buf,stderr);
	fflush(NULL);
}
