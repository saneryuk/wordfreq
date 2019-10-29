#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "linkedlist.h"
#include<unistd.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
    int openfile;
    
    if(argc>=1)
        if(strcmp(argv[1], "-")==0)
            openfile=STDIN_FILENO;
        else
            openfile =open(argv[1], O_RDONLY);
    struct stat st;
    stat(argv[1], &st);
    printf("args: %i", argc);

    off_t size = st.st_size;
    
    char *buf=(char*)malloc(size);
    char *word=(char*)malloc(100);

    if(openfile==-1)
        return 0;
    while(read(openfile, buf, 1)>0)
    {
        char c=buf[0];
        if(isalpha(c)==0)
    	{ 
            add_word(word);
            word=(char*)malloc(100);
		}
        else word=strcat(word,buf);
    }
    add_word(word);

	print_words();

    printf("\nFILESIZE: %jd\n", size);

	free(buf); free(word);
    int closecode=close(openfile);

    if(closecode==-1)
        return 0;
    return 1;
}

