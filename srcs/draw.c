/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:36:22 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/22 15:19:17 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_wall_color(t_mlx *mlx)
{
	int		color;

	if (mlx->draw.side == 0 && mlx->cam.xdir >= 0)
		color = RED;
	else if (mlx->draw.side == 0 && mlx->cam.xdir < 0)
		color = YELLOW;
	else if (mlx->draw.side == 1 && mlx->cam.ydir >= 0)
		color = BLUE;
	else
		color = ORANGE;
	if (mlx->draw.side == 1)
		color = color / 2;
	return (color);
}

static void	ft_draw_init(t_mlx *mlx)
{
	mlx->cam.x = 2 * mlx->draw.x / (double)WIN_W - 1;
	mlx->draw.side = 0;
	mlx->draw.hit = 0;
	mlx->cam.xpos = mlx->player.xpos;
	mlx->cam.ypos = mlx->player.ypos;
	mlx->cam.xdir = mlx->player.xdir + mlx->cam.xplane * mlx->cam.x;
	mlx->cam.ydir = mlx->player.ydir + mlx->cam.yplane * mlx->cam.x;
	mlx->draw.xmap = (int)mlx->cam.xpos;
	mlx->draw.ymap = (int)mlx->cam.ypos;
	mlx->draw.xdelta_dist = sqrt(1 + pow(mlx->cam.ydir / mlx->cam.xdir, 2));
	mlx->draw.ydelta_dist = sqrt(1 + pow(mlx->cam.xdir / mlx->cam.ydir, 2));
}

static void	ft_draw_slice(t_mlx *mlx)
{
	int		y;
	int		color;

	y = 0;
	while (y < WIN_H)
	{
		if (y < mlx->draw.start)
			color = BLACK;
		else if (y > mlx->draw.end)
			color = GRAY;
		else
		{
			if (mlx->draw.hit == 1)
				color = ft_wall_color(mlx);
		}
		ft_put_pixel(mlx, mlx->draw.x, y, color);
		y++;
	}
}

void		ft_draw(t_mlx *mlx)
{
	mlx->draw.x = 0;
	while (mlx->draw.x < WIN_W)
	{
		ft_draw_init(mlx);
		ft_raycast(mlx);
		ft_draw_slice(mlx);
		mlx->draw.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
