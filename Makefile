CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lSDL2 -lSDL2_image
LFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf #Library flags

SRC = main.c 
OBJ = $(SRC:.c=.o)
EXEC = ddm

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIBS) $(LFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
