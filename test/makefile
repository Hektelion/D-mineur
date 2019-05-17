####################################################
################## MAKEFILE TEST ###################
####################################################

CC = gcc
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf
CFLAGS = -W -Wall
EXEC = d-mineur

INCLUDE = $(wildcard include/*.c)
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c = obj/%.o)

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

main.o	: $(INCLUDE)

obj/%.o : src/%.c
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

####################################################

clean	:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

.PHONY	: clean mrproper

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################
