SRCS	= ft_fdprintf.c \
		  ft_putnbr_base.c \
		  ft_iterative_power.c \
		  ../ft_putchar_fd.c \
		  ../ft_putstr_fd.c \
		  ../ft_strchr.c \
		  ../ft_strlen.c

OBJS 	= ${SRCS:.c=.o}

NAME 	= libftfdprintf.a

CC	 	= clang

RM		= @rm -f

CFLAGS 	= -Wall -Werror -Wextra -g

all: 		${NAME}

.c.o:		${OBJS}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	clear compiling ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			@clear
			@printf '\033[0;92;1mcompilation finished\n'

clear:
			@clear

compiling:
			@printf "\033[93;1;5mcompiling ...\n"

cleaning:
			@printf "\033[93;1;5mcleaning ...\n"

clean:		clear cleaning 
			${RM} ${OBJS} 
			@clear
			@printf '\033[0;92;1mcleaning finished\n'

fclean: 	clear clean cleaning
			${RM} ${NAME}
			@clear
			@printf '\033[0;92;1mcleaning finished\n'

re: 		fclean all

.PHONY: 	all clean fclean re
