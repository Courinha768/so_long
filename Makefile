CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -fsanitize=address -g
RM			= 	/bin/rm -f
NAME		= 	so_long
INCLUDES	= 	-Iheaders/

SRCS		=   so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c $(shell find srcs/ -name '*.c') libft/libft.a 
OBJS		= 	$(SRCS:.c=.o)


MLX_LIB_DIR = mlx_linux/
LIBFT_INCLUDE = -ILIBFT/include
MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME) 

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED cub3D EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

v:
	@make re && make clean && clear && valgrind --leak-check=full --log-file="logfile.out" -v ./so_long
r:
	@make re && make clean && clear && ./so_long map/map3.car map/map1.car map/map2.car

rr:
	@make re && make clean && clear && ./so_long map/map1.car


.PHONY: all re clean fclean m