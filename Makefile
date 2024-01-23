NAME = philo
INCLUDE = includes
CFLAGS = -Wall -Wextra -Werror -O3 -I$(INCLUDE) #-pthread
SRC = srcs/main.c \
	srcs/checker.c \
	srcs/eat.c \
	srcs/filler.c \
	srcs/mutex_things.c \
	srcs/philos.c \
	srcs/utils.c \
	srcs/utils2.c \
	srcs/utils3.c
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE) 
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:: fclean
re:: all

asan:: CFLAGS += -fsanitize=address -g3
asan:: LDFLAGS += -fsanitize=address -g3
asan:: re

tsan:: CFLAGS += -fsanitize=thread -g3
tsan:: LDFLAGS += -fsanitize=thread -g3
tsan:: re

normi:
	@norminette srcs includes

.PHONY: all clean fclean re asan tsan normi