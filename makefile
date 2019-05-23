####################################################
################ MAKEFILE PRINCIPAL ################
####################################################

#EXECUTION
CC = g++
LDFLAGS = `sdl2-config --libs --cflags` -lSDL_ttf -lSDL2_image
CFLAGS = -W -Wall
EXEC = d-mineur

#CHEMIN FICHIER INCLU
include_class_dir = include/class/
include_dir = include/

#CHEMIN FICHIER SOURCE
src_class_dir = src/class/
src_dir = src/

#CHEMIN FICHIER OBJET
obj_class_dir = obj/class/
obj_dir = obj/

#LISTE FICHIER INCLU
INCLUDE_CLASS = $(wildcard include/class/*.hpp)
INCLUDE = $(wildcard include/*.hpp)

#LISTE FICHIER SOURCE
SRC_CLASS = $(wildcard src/class/*.cpp)
SRC = $(wildcard src/*.cpp)

#LISTE FICHIER OBJET
OBJ_CLASS = $(SRC_CLASS:src/class/%.cpp=obj/class/%.o)
OBJ = $(SRC:src/%.cpp=obj/%.o)

####################################################

all	: $(EXEC)
	@echo "DONE"

$(EXEC)	: $(OBJ_CLASS) $(OBJ) $(INCLUDE_CLASS) $(INCLUDE) $(SRC_CLASS) $(SRC)
	@echo "Création de l'éxecutable"
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Création de l'éxecutable : OK"

obj/main.o:

obj/class/%.o:src/class/%.cpp
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

obj/%.o:src/%.cpp
	@echo Création de $*.o
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo Création de $*.o : OK

####################################################

.PHONY	: clean mrproper

clean	:
	rm -f obj/*.o
	rm -f obj/class/*.o

mrproper: clean
	rm -rf $(EXEC)

print-%  : ; @echo $* = $($*)

####################################################
# Crée par BESSAI Sofiane ##########################
# Projet D-mineur ##################################
####################################################
