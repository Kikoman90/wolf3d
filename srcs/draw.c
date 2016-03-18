/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:36:22 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/18 17:08:45 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	mlx->draw.xdelta_dist = sqrt(1 + pow(mlx->cam.ydir, 2) \
								/ pow(mlx->cam.xdir, 2));
	mlx->draw.ydelta_dist = sqrt(1 + pow(mlx->cam.xdir, 2) \
								/ pow(mlx->cam.ydir, 2));
}

void		ft_draw(t_mlx *mlx)
{
	mlx->draw.x = 0;
	while (mlx->draw.x < WIN_W)
	{
		ft_draw_init(mlx);
		mlx->draw.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
