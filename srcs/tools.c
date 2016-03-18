/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:38:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/18 19:09:25 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (mlx->bpp / 8) + y * (mlx->size_line);
	while (i < (mlx->bpp / 8))
	{
		mlx->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int		ft_player_init(t_mlx *mlx)
{
	int		i;
	int		j;

	j = 0;
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == 'X')
			{
				mlx->player.xpos = j;
				mlx->player.ypos = i;
				mlx->player.xdir = -1;
				mlx->player.ydir = 0;
				mlx->player.mvspd = 0.2;
				mlx->player.rtspd = 0.05;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

int		ft_instructions(void)
{
	ft_putendl("--- INSTRUCTIONS ---");
	ft_putendl("mouse : rotate camera");
	ft_putendl("< ^ > v : move");
	ft_putendl("SPC : jump");
	ft_putendl("CTRL : crouch");
	ft_putendl("F : activate fog");
	ft_putendl("+/- : increase/decrease FOV");
	ft_putendl("ESC : close");
	return (0);
}

int		ft_linelen(char *buf, int k)
{
	int	len;

	len = 0;
	while (buf[k] != '\n' && buf[k] != '\0')
	{
		k++;
		len++;
	}
	return (len);
}

int		ft_checkchar(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' && buf[i] != '0' && buf[i] != '1'\
				&& buf[i] != 'X' && buf[i] != '\0')
		{
			ft_putendl("error: invalid characters in map");
			return (-1);
		}
		i++;
	}
	return (1);
}
