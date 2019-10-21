#include "datastruct.h"

struct word *words[2000];
int ind=0;
void add_word(char *c)
{
	struct word *newword=(struct word*)malloc(sizeof(struct word));
	newword->count=1;
	newword->st=(char *)malloc(sizeof(char*));
	words[ind++]=newword;
}

void print_words()
{
	for(int i=0;i<2000;i++)
		if(words[i]!=NULL) printf("%s : %i  \n", words[i]->st, words[i]->count);
}
