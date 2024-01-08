#compilation des fichiers pour le jeu

#fonctions auxiliaires
OBJECTS = main.o dic.o

OPTIONS_TEST = -Wall -Wextra -Wvla -fsanitize=address,undefined -g -O0 
OPTIONS_XP = -Wall -Wextra -Wvla -fsanitize=address,undefined -O2 



all: main

%.o: %.c %.h
		gcc -c $< $(OPTIONS_TEST) $^ -lm -lrt

main: $(OBJECTS)
		gcc -o $@ $(OPTIONS_XP) $^ -lm -lrt -g

clean:
		rm $(OBJECTS) main
