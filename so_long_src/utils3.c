/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:07:25 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 21:36:58 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	d;

	i = 0;
	ptr = (unsigned char *)str;
	d = (unsigned char)c;
	while (i < len)
	{
		ptr[i] = d;
		i++;
	}
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_check_files(t_game *game)
{
	if (!(game->ground || game->closedexit || game->right_player
			|| game->left_player || game->wall || game->count_moves
			|| game->collectible))
	{
		close_window(game);
		free_all(game);
	}
}

int	is_map_empty(char **map, t_game *game)
{
	if (!map || !map[0])
	{
		ft_printf("ERROR:\nMap is empty!");
		close_window(game);
		return (1);
	}
	return (0);
}
