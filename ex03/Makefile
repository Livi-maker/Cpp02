NAME = bsp

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: re all clean fclean
