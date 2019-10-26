#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "datastruct.h"
#include<unistd.h>

int main(int argc, char *argv[])
{
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
	print_words();
	free(buf); free(buf2);   
        int closecode=close(openfile);
        if(closecode==-1)
                return 0;
        return 1;
}
