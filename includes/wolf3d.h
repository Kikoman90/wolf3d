/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:23:56 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/17 18:45:09 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <../libft/libft.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>

# define WIN_W 800
# define WIN_H 800

# define BUFF_SIZE 100

typedef struct	s_mlx
{
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

int				ft_checkchar(char *buf);
int				ft_linelen(char *buf, int k);

#endif
