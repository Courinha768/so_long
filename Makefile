NAME		=	so_long

SRCS		=	$(shell find srcs/ -name '*.c') $(shell find get_next_line/ -name '*.c')
BSRCS		=	$(shell find bonus/ -name '*.c') $(shell find get_next_line/ -name '*.c')
OBJS		=	${SRCS:.c=.o}
BOBJS		=	${BSRCS:.c=.o}

LD_FLAGS	=	-L libft -L mlx
MLX_FLAGS	=	-lm -lmlx -lXext -lX11
HEAD		=	-I includes -I libft -I mlx
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address

.c.o		:
	@${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)		:	${OBJS}
	@make -s -C libft
	@make -s -C mlx
	@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all			:	${NAME}

bonus		:	${BOBJS}
	@make -s -C libft
	@make -s -C mlx
	@${CC} ${CFLAGS} ${LD_FLAGS} ${BOBJS} -o ${NAME} -lft ${MLX_FLAGS}

# val			:	${NAME}
# 	@valgrind \
# 	--leak-check=full --tool=memcheck \
# 	--show-reachable=yes \
# 	--track-fds=yes \
# 	--errors-for-leak-kinds=all \
# 	--show-leak-kinds=all ./so_long	maps/map1.ber

clean		:
	@make -s clean $@ -C libft
	@make -s clean $@ -C mlx
	@rm -rf ${OBJS}
	@rm -rf ${BOBJS}
	@echo "object files removed."

fclean		:	clean
	@make -s fclean $@ -C libft
	@rm -rf ${NAME}
	@echo "binary file removed."

re			:	fclean all

.PHONY		:	all clean fclean re
