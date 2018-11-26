CC = clang
CFLAGS = -Wall -Werror
OBJ = $(patsubst %.c, %.o, $(wildcard *.c))
DEP = $(patsubst %.c, %.dep, $(wildcard *.c))

essai_fap : $(OBJ)

-include $(DEP) # dépendences des fichiers .o construites automatiquement

%.dep : %.c
	@$(CC) -MM $< > $@

.PHONY: clean
clean :
	@rm -f essai_fap *.o *.dep
