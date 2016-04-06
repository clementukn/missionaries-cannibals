CC = g++
CFLAGS = -Wall -std=c++14
NAME = cnm
SRC = src

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)/*.cpp

clean:
	rm $(NAME)
