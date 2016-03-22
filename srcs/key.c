/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:11:42 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/22 18:47:14 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_rotate(int keycode, double tmp_dir, double tmp_plane, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		mlx->player.xdir = mlx->player.xdir * cos(mlx->player.rtspd)
			- mlx->player.ydir * sin(mlx->player.rtspd);
		mlx->player.ydir = tmp_dir * sin(mlx->player.rtspd)
			+ mlx->player.ydir * cos(mlx->player.rtspd);
		mlx->cam.xplane = mlx->cam.xplane * cos(mlx->player.rtspd)
			- mlx->cam.yplane * sin(mlx->player.rtspd);
		mlx->cam.yplane = tmp_plane * sin(mlx->player.rtspd)
			+ mlx->cam.yplane * cos(mlx->player.rtspd);
	}
	if (keycode == 124)
	{
		mlx->player.xdir = mlx->player.xdir * cos(-mlx->player.rtspd)
			- mlx->player.ydir * sin(-mlx->player.rtspd);
		mlx->player.ydir = tmp_dir * sin(-mlx->player.rtspd)
			+ mlx->player.ydir * cos(-mlx->player.rtspd);
		mlx->cam.xplane = mlx->cam.xplane * cos(-mlx->player.rtspd)
			- mlx->cam.yplane * sin(-mlx->player.rtspd);
		mlx->cam.yplane = tmp_plane * sin(-mlx->player.rtspd)
			+ mlx->cam.yplane * cos(-mlx->player.rtspd);
	}
	return (0);
}

int			key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
	{
		if (mlx->map[(int)(mlx->player.xpos + mlx->player.xdir
					* mlx->player.mvspd)][(int)(mlx->player.ypos)] != '1')
			mlx->player.xpos += mlx->player.xdir * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xpos)][(int)(mlx->player.ypos
					+ mlx->player.ydir * mlx->player.mvspd)] != '1')
			mlx->player.ypos += mlx->player.ydir * mlx->player.mvspd;
	}
	if (keycode == 125)
	{
		if (mlx->map[(int)(mlx->player.xpos - mlx->player.xdir
					* mlx->player.mvspd)][(int)(mlx->player.ypos)] != '1')
			mlx->player.xpos -= mlx->player.xdir * mlx->player.mvspd;
		if (mlx->map[(int)(mlx->player.xpos)][(int)(mlx->player.ypos
					- mlx->player.ydir * mlx->player.mvspd)] != '1')
			mlx->player.ypos -= mlx->player.ydir * mlx->player.mvspd;
	}
	if (keycode == 78)
		mlx->dh = (mlx->dh < 120) ? mlx->dh + 0.5 : mlx->dh;
	if (keycode == 69)
		mlx->dh = (mlx->dh > 0.5) ? mlx->dh - 0.5 : mlx->dh;
	ft_rotate(keycode, mlx->player.xdir, mlx->cam.xplane, mlx);
	ft_draw(mlx);
	return (0);
}
