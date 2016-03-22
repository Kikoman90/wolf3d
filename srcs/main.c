/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:52:46 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/22 15:19:47 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_start(const char *s, int argc, int *fd)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./wolf3d input_file\n", 2);
		return (-1);
	}
	if (BUFF_SIZE < 1)
	{
		ft_putstr_fd("error: BUFF_SIZE must be greater than 0\n", 2);
		return (-1);
	}
	if ((*fd = open(s, O_RDONLY)) == -1)
	{
		ft_putendl(ft_strjoin("error: ", strerror(errno)));
		return (-1);
	}
	return (1);
}

static char		*ft_getbuf(int argc, const char *s, int *nbl)
{
	int		fd;
	char	*buf;
	char	*line;

	buf = ft_strnew(1);
	if (ft_start(s, argc, &fd) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0 && (*nbl)++ > -1)
		buf = ft_strjoin(ft_strjoin(buf, line), "\n");
	if (get_next_line(fd, &line) < 0)
	{
		ft_putendl("error: get_next_line returned -1");
		free(buf);
		return (NULL);
	}
	if (ft_checkchar(buf) == -1)
		return (NULL);
	if (close(fd) == -1)
	{
		ft_putendl(ft_strjoin("error: ", strerror(errno)));
		return (NULL);
	}
	return (buf);
}

static char		**ft_getmap(char *buf, int nbl, int j)
{
	int		i;
	int		k;
	char	**map;

	k = 0;
	if (!buf)
		return (NULL);
	if (!(map = (char **)malloc(sizeof(char *) * nbl)))
		return (NULL);
	while (buf[k] != '\0' && j < nbl)
	{
		i = 0;
		if (!(map[j] = (char *)malloc(sizeof(char) * ft_linelen(buf, k))))
			return (NULL);
		while (buf[k] != '\n' && buf[k] != '\0')
			map[j][i++] = buf[k++];
		map[j][i] = '\0';
		k++;
		j++;
	}
	return (map);
}

static t_mlx	*init_mlx(int argc, const char *s)
{
	t_mlx	*mlx;
	char	*buf;
	char	*name;

	name = ft_strjoin("wolf3d: ", s);
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->nbl = 0;
	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, name);
	mlx->d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, \
			&mlx->endian);
	buf = ft_getbuf(argc, s, &(mlx->nbl));
	if ((mlx->map = ft_getmap(buf, mlx->nbl, 0)) == NULL)
		return (NULL);
	if (ft_player_init(mlx) == -1)
	{
		ft_putendl("error : player not found in map");
		return (NULL);
	}
	mlx->cam.xplane = 0.0;
	mlx->cam.yplane = 0.6;
	return (mlx);
}

int				main(int argc, char **argv)
{
	t_mlx	*mlx;

	if ((mlx = init_mlx(argc, argv[1])) != NULL)
	{
		ft_instructions();
		ft_draw(mlx);
		mlx_hook(mlx->win, KEYPRESS, KEYPRESSMASK, key_hook, mlx);
		mlx_loop(mlx->mlx);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}
