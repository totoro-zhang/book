#include "../apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t	pid;
	pid_t	childpid;
	int 	status;

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid == 0)
		exit(7);
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid == 0)
		abort();
	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);


	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid == 0)
	{
		printf("getpid:%d,getppid:%d\n",getpid(),getppid());
		status/=0;
		
	}
	printf("pid:%d getpid:%d\n",pid,getpid());
	if((childpid=wait(&status)) != pid)
		err_sys("wait error");
	printf("childpid:%d\n",childpid);
	pr_exit(status);
	exit(0);

}
