#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "linkedlist.h"
#include<unistd.h>

int main(int argc, char *argv[])
{
    int openfile=open(argv[1], O_RDONLY), ind=0, temp=0;
    char *buf=(char*)malloc(sizeof(openfile));
    char *buf2=(char*)malloc(200);
    char *wrd=(char *)malloc(100);

	if(openfile==-1)
    return 0;
  int x;
  while(read(openfile, buf, 1)>0)
  {
    if(strcmp(buf, " ")==0||strcmp(buf, "\n")==0||strcmp(buf, "\0")==0)
  	{ 
			add_word(buf2);
      printf("\nword read as: '%s' \n",buf2);
      buf2=(char*)malloc(200);
		}
    else
      buf2=strcat(buf2,buf);
  }
 add_word(buf2);
	print_words();
	free(buf); free(buf2);   
        int closecode=close(openfile);
        if(closecode==-1)
                return 0;
        return 1;
}
