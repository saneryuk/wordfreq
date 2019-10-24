#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
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

	printf("%s\n", buf2);
//        print_words();
	printf("Number of words: %i", wordcount);
        
	char word=(char*)malloc(1000);
	for(int i=0;i<strlen(buf2);i++)
	{
		if(strcmp(buf2[i], ' ')!=0||strcmp(buf2[i], '\0')!=0 || strcmp(buf2[i], '\n')!=0)
			strcat(word, buf2[i]);
		else 
		{
			add_word(word);
			wordcount++;
			for(int j=0;j<100;j++)
				word[j]=NULL;
		}		
	}
	printf("\nWordcount: %i\n", wordcount);
	free(buf); free(buf2);   
        int closecode=close(openfile);
        if(closecode==-1)
                return 0;
        return 1;
}
