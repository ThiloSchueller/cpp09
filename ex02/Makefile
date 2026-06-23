NAME = PmergeMe
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++17 -g -fsanitize=address
SRCS = main.cpp PmergeMe.cpp Node.cpp
OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re