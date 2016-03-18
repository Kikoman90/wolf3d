/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:44:32 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/18 19:47:13 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_step(t_mlx *mlx)
{
	if (mlx->cam.xdir < 0)
	{
		mlx->draw.xstep = -1;
		mlx->draw.xside_dist = (mlx->cam.xpos - (double)mlx->draw.xmap) \
								* mlx->draw.xdelta_dist;
	}
	else
	{
		mlx->draw.xstep = 1;
		mlx->draw.xside_dist = ((double)mlx->draw.xmap + 1.0 - mlx->cam.xpos)\
								* mlx->draw.xdelta_dist;
	}
	if (mlx->cam.ydir < 0)
	{
		mlx->draw.ystep = -1;
		mlx->draw.yside_dist = (mlx->cam.xpos - (double)mlx->draw.ymap) \
								* mlx->draw.ydelta_dist;
	}
	else
	{
		mlx->draw.ystep = 1;
		mlx->draw.yside_dist = ((double)mlx->draw.ymap + 1.0 - mlx->cam.ypos)\
								* mlx->draw.ydelta_dist;
	}
}

static void	ft_hit(t_mlx *mlx)
{
	while (mlx->draw.hit != 1 && mlx->draw.ymap > 0 && \
			mlx->draw.ymap < ft_linelen(mlx->map[mlx->draw.xmap], 0) && \
			mlx->draw.xmap > 0 && mlx->draw.xmap <= mlx->nbl)
	{
		if (mlx->draw.xside_dist < mlx->draw.yside_dist)
		{
			mlx->draw.side = 0;
			mlx->draw.xmap += mlx->draw.xstep;
			mlx->draw.xside_dist += mlx->draw.xdelta_dist;
		}
		else
		{
			mlx->draw.side = 1;
			mlx->draw.ymap += mlx->draw.ystep;
			mlx->draw.yside_dist += mlx->draw.ydelta_dist;
		}
		if (mlx->map[mlx->draw.xmap][mlx->draw.ymap] > '0')
			mlx->draw.hit = 1;
	}
}

static void	ft_wall_dist(t_mlx *mlx)
{
	if (mlx->draw.side == 0)
		mlx->cam.wall_dist = fabs((mlx->draw.xmap - mlx->cam.xpos + \
		(1 - mlx->draw.xstep) / 2) / mlx->cam.xdir);
	else
		mlx->cam.wall_dist = fabs((mlx->draw.ymap - mlx->cam.ypos + \
		(1 - mlx->draw.ystep) / 2) / mlx->cam.ydir);
	if (mlx->cam.wall_dist < 0.005)
		mlx->cam.wall_dist = 0.005;
}

void		ft_raycast(t_mlx *mlx)
{
	ft_step(mlx);
	ft_hit(mlx);
	ft_wall_dist(mlx);
	mlx->draw.height = fabs(WIN_H / mlx->cam.wall_dist);
	if ((mlx->draw.start = -(mlx->draw.height) / 2 + WIN_H / 2) < 0)
		mlx->draw.start = 0;
	if ((mlx->draw.end = mlx->draw.height / 2 + WIN_H / 2) >= WIN_H)
		mlx->draw.end = WIN_H - 1;
}
