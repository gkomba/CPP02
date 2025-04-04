NAME=fixed_point
SRC=main.cpp\
	Fixed.cpp

OBJS=$(SRC:.cpp=.o)
CXX=c++
CXXFLAGS=-std=c++98
FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re