#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include "linkedlist.h"

struct word *words[2000];
struct word *head,*tail;
int ind=0, wordcount=0;

void add_word(char *ch)
{
    if(strcmp(ch, "")==0||strcmp(ch, " ")==0||strcmp(ch,"\n")==0||strcmp(ch,"\n\n")==0)
        return;
    if(head==NULL)
    {
        head=(struct word*)malloc(sizeof(struct word));
        head->st=ch;
        head->count=1;
        tail=head;
        wordcount++;
        return;
    }
    struct word *ex=exists(ch);
    if (ex!=NULL)
    {
        (ex->count)++;
        wordcount++;
        return;
    }
    struct word *temp=(struct word*)malloc(sizeof(struct word));
    temp->st=ch;
    temp->count=1;
    tail->next=temp;
    wordcount++;
    tail=temp;
}

void print_words()
{
    struct word *ptr=head;
    while(ptr!=NULL)
    {
        char buffer[50];
        char *outstring=ptr->st;
      /*  for(int i=1;i<=(11-(int)strlen(ptr->st));i++)
           outstring=strcat(outstring, " ");
        outstring=strcat(outstring, ": \n");*/
       sprintf(buffer,"%15s : %i \n", outstring, ptr->count);
        write(STDOUT_FILENO, buffer, strlen(buffer)+1);
        //printf("%s: %i\n", ptr->st, ptr->count);
        ptr=ptr->next;
    }
}

struct word *exists(char *c)
{
    struct word *ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->st, c)==0)
            return ptr;
        ptr=ptr->next;
    }
    return NULL;
}
