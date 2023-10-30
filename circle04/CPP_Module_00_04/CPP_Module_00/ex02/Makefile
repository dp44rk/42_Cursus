NAME = Account

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = Account.cpp tests.cpp
SRC_OBJ = $(SRC_FILES:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
