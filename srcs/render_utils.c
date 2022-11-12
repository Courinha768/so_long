#include "../includes/so_long.h"

int	w(char c)
{
	return (c == 49);
}

void	*chose_grass(t_all *all, int k)
{
	if (k % 2)
		return (all->field.grass3.img);
	else if (k % 3)
		return (all->field.grass2.img);
	else
		return (all->field.grass1.img);
}