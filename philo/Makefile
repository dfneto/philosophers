# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifern <davifern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 11:04:27 by davifern          #+#    #+#              #
#    Updated: 2024/03/14 11:51:36 by davifern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


########################## VARIABLES DEFINITIONS ###############################
NAME = philo
MAKE = make
HEADER = philo.h
SRC = main.c utils.c parser.c time.c routine.c create_destroy.c stop_conditions.c
CC = gcc
CFLAGS += -Wextra -Werror -Wall #-g -fsanitize=thread #Compile flags
LDFLAGS += -fsanitize=thread
LIBS	=	-lpthread

# This line itself doesn't actually generate the object files; it just sets up the 
# names that will be used when the object files are generated
OBJ = $(SRC:.c=.o)

################################# RULES ####################################### 
all: 
	$(MAKE) $(NAME)

# This is a pattern rule that specifies how to build an object file (.o) from a 
# corresponding source file (.c). It also depends on the $(HEADER) file, meaning the
# object files will be recompiled if the header file changes.
# $(CC) $(CFLAGS) -c $< -o $@: This is the command that actually compiles each .c 
# file into an .o file. $< is the first dependency (the .c file in this case) and $@ 
# is the target (the .o file).
%.o : %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)
# $(CC) $(OBJ) $(LDFLAGS) -O3 -o $(NAME)

clean:
	rm -f *.out *.o 
	rm -rf *.dSYM

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re