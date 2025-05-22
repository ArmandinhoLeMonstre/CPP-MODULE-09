NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g

RM = rm -rf

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;33m\nCOMPILING PmergeMe...\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;32m./PmergeMe created\n"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) btc

re: fclean all