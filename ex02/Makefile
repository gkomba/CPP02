NAME=fixed_point
SRC=main.cpp\
	Fixed.cpp

OBJS=${SRC:.cpp=.o}
CXX=c++
CXXFLAGS=-std=c++98
FLAGS=-Wall -Wextra -Werror
RM= rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${FLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re