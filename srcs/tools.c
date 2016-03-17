/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 18:38:26 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/17 19:01:04 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
