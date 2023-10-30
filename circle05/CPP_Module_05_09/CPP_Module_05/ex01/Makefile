NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC_FILES = Bureaucrat.cpp \
			Form.cpp \
			main.cpp

SRC_OBJ = $(SRC_FILES:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

$(NAME): $(SRC_OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re