SRC	=	linkedlist.h	linkedlist.c	main.c
OBJ	=	linkedlist.o	main.o
PROG	=	wordfreak

$(PROG):	$(OBJ)
	gcc $(OBJ)	-o	$(PROG)
$(OBJ):	$(SRC)
