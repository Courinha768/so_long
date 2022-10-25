NAME		=	so_long

SRCS		=	$(shell find srcs/ -name '*.c') $(shell find get_next_line/ -name '*.c')
OBJS		=	${SRCS:.c=.o}

LD_FLAGS	=	-L libft -L mlx
MLX_FLAGS	=	-lm -lmlx -lXext -lX11
HEAD		=	-I includes -I libft -I mlx
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra #-g -fsanitize=address

MAP			=	"maps/map2.ber"
EXC			=	./${NAME} ${MAP}

.c.o		:
	@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)		:	${OBJS}
	@make -C libft
	@make -C mlx
	@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all			:	${NAME}

val			:	${NAME}
	@valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ${EXC}

exc			:	${NAME}
	@${EXC}


clean		:
	@make clean -C libft
	@make clean -C mlx
	@rm -rf ${OBJS}

fclean		:	clean
	@make fclean -C libft
	@rm -rf ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re
