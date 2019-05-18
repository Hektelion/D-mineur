####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

CC = g++
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf
CFLAGS = -W -Wall
EXEC = d-mineur

INCLUDE = $(wildcard include/*.hpp)
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:src/%.c = obj/%.o)

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

#obj/main.o	: $(OBJ)

obj/%.o : src/%.cpp
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

####################################################

.PHONY	: clean mrproper

clean	:
	rm -f obj/*.o

mrproper: clean
	rm -rf $(EXEC)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################
