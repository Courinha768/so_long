#include "../includes/so_long.h"

int	key_hook(int keycode, t_all all)
{
	if (keycode == ESCAPE)
		destroy_win(all);
	// if (keycode == W)
	// 	move_up(map);
	printf("%d\n", keycode);
	return (0);
}