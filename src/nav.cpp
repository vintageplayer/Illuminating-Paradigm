#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
using namespace std;

void show_about()
{
	int pid;
	if((pid=fork())<0)
	{
		perror("fork");
		exit(1);
	}
	else if(pid==0)
	{
		execl("./about",NULL);
	}
	else
	{
		int status;
		waitpid(pid,&status,0);
		if(WEXITSTATUS(status)!=0)
		{
			cout<<"Error Occurred. Exiting..."<<endl;
			exit(1);
		}
	}	
}

void show_work_window()
{
	int pid;
	if((pid=fork())<0)
	{
		perror("fork");
		exit(1);
	}
	else if(pid==0)
	{
		execl("./work",NULL);
	}
	else
	{
		int status;
		waitpid(pid,&status,0);
		if(WEXITSTATUS(status)!=0)
		{
			cout<<"Error Occurred. Exiting..."<<endl;
			exit(1);
		}
	}	
}

int main()
{
	int pid;

	while(1)
	{
		if((pid=fork())<0)
		{
			perror("fork");
			exit(1);
		}
		else if(pid==0)
		{
			execl("./nav",NULL);
		}
		else
		{
			int status;
			waitpid(pid,&status,0);
			cout<<"Child returned with status : "<<WEXITSTATUS(status)<<endl;
			switch(WEXITSTATUS(status))
			{
				case 5:
					// cout<<"Work Window."<<endl;
					show_work_window();
					break;

				case 10:
					// cout<<"About Window."<<endl;
					show_about();
					break;

				case 15:
					cout<<"Exiting... BYE."<<endl;
					exit(0);
					break;
				default:
					cout<<"Invalid return status. Exiting..."<<endl;
					exit(0);
			}
		}
	}
}