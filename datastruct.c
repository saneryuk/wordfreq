#include "datastruct.h"


void add_word(char c[100])
{
	struct word *newword=(struct word*)malloc(sizeof(struct word));
	newword->str=c;
	newword->count=1;
}
