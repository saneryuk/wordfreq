#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
<<<<<<< HEAD
#include "linkedlist.h"
=======
#include "datastruct.h"
>>>>>>> 7ea407a848c7c5351de65b0da4e5124770aff31f
#include<unistd.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
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
=======
    int openfile=open(argv[1], O_RDONLY);
    char *buf=(char*)malloc(250000);
    char *buf2=(char*)malloc(250000);
	int wordcount=0;
       
	 if(openfile==-1)
                return 0;
        while(read(openfile, buf, 1)>0)
       		buf2=strcat(buf2,buf);

//	printf("%s\n", buf2);
     
	char *wrd=(char *)malloc(100);
	int ind=0; int temp=0;
	for(int i=0;i<strlen(buf2);i++)
	{
//		printf("%c", buf2[i]);
		wrd[ind]=buf2[i];
		ind++;
		if(buf2[i]== ' '||buf2[i] == '\n'||buf2[i]=='\0')
  		{ 
			//if word exists, increment counter, else add
			ind=0;
			printf("%i. %s\n",temp++,wrd);   
			add_word(wrd);
			wordcount++;
			wrd=calloc(1000, sizeof(char));
		}
	}

//	print_words();
	printf("\nWordcount: %i\n", wordcount);
>>>>>>> 7ea407a848c7c5351de65b0da4e5124770aff31f
	print_words();
	free(buf); free(buf2);   
        int closecode=close(openfile);
        if(closecode==-1)
                return 0;
        return 1;
}
