#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
	char *st;
	int count;
  struct word *next;
};

void add_word(char *ch);

void print_words();

struct word *exists(char *c);


