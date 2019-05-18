####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

CC = g++
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf
CFLAGS = -W -Wall
EXEC = d-mineur

INCLUDE_CLASS = $(wildcard include/class/*.hpp)
INCLUDE = $(wildcard include/*.hpp)

SRC_CLASS = $(wildcard src/class/*.cpp)
SRC = $(wildcard src/*.cpp)

OBJ_CLASS = $(SRC_CLASS:src/class/%.cpp = obj/class/%.o)
OBJ = $(SRC:src/%.cpp = obj/%.o)

LINK_CLASS = $(SRC_CLASS:src/class/%.cpp = obj/class/%.o)
LINK = $(SRC:src/%.cpp = obj/%.o)

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ_CLASS) $(OBJ)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS) '-I/obj/class/partie.o'
	@echo "Création de l'éxecutable : OK"

#obj/main.o	: $(OBJ_CLASS) $(OBJ)

obj/class/%.o : src/class/%.cpp
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

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

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################
