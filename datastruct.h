#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
	char str[100];
	int count;
	struct word *next;
};

void add_word(char c[100]);
