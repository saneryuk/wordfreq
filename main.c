#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
        int openfile=open(argv[1], O_RDONLY);
        char *buf=(char*)malloc(250000);
        char *buf2=(char*)malloc(250000);
        if(openfile==-1)
                return 0;
        while(read(openfile, buf, 1)>0)
        {	if((strcmp(buf, " ")==0)||(strcmp(buf, "\n")==0))
		{
			
		}
	        buf2=strcat(buf2,buf);
        }
	printf("%s\n", buf2);
        free(buf); free(buf2);
        int closecode=close(openfile);
        if(closecode==-1)
                return 0;
        return 1;
}
