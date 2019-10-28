#include <string.h>
#include "linkedlist.h"

struct word *words[2000];
struct word *head,*tail;
int ind=0, wordcount=0;
void add_word(char *ch)
{
  if(strcmp(ch, "")==0||strcmp(ch, " ")==0||strcmp(ch,"\n")==0)
    return;
	if(head==NULL)
  {
    head=(struct word*)malloc(sizeof(struct word));
    head->st=ch;
    tail=head;
    wordcount++;
    return;
  }
 //else words[ind++]=newword;
  struct word *temp=(struct word*)malloc(sizeof(struct word));
  temp->st=ch;
  tail->next=temp;
  wordcount++;
  tail=temp;
}

void print_words(struct word *ptr)
{
	ptr=head;
  while(ptr!=NULL)
  {
      printf("%s\n", ptr->st);
      ptr=ptr->next;
  }

  printf("Wordcount: %i\n", wordcount);
}
