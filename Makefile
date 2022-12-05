SRCS ?= program/tester_parsing_map.c \
		program/search_files.c \
		program/check_output.c \
		program/check_valgrind.c \
		program/utils.c \
		program/functions_tab.c \
		program/launch_test.c 

OBJS ?= ${SRCS:.c=.o}

NAME ?= tester_parsing_map

COMPILER ?= clang

RM		?= @rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= -Lprogram/libft -lft \
		  -Lprogram/libft/ft_fdprintf -lftfdprintf

FILES	?= stdout.txt \
		   valgrind_output.txt

.c.o:		${OBJS}
	@(${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} || (clear; printf "\033[0;91;1mcompilation failed\n\033[0;97;1m"; ${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} ; exit 1))


all: 	 	${NAME}

${NAME}:	clear compiling ${OBJS}
			@make -C program/libft
			@${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBRARY}
			@clear
			@printf '\033[0;92;1mCompilation finished\n'

clear:
			@clear

compiling:
			@printf "\033[93;1;5mCompiling ...\n"

cleaning:
			@printf "\033[93;1;5mCleaning ...\n"

clean:		clear cleaning
			${RM} ${OBJS} ${FILES}
			@make -C program/libft clean
			@clear
			@printf '\033[0;92;1mCleaning finished\n'

fclean: 	clear clean cleaning
			${RM} ${NAME}
			@make -C program/libft fclean
			@clear
			@printf '\033[0;92;1mCleaning finished\n'

re: 		fclean all

.PHONY: 	all clean fclean re
