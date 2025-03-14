/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:07:25 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/14 21:05:40 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)&str[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

void	ft_check_files(t_game *game)
{
	if (!game->frames[0] || !game->frames[1] || !game->frames[2]
			|| !game->frames[3] || !game->frames[4] || !game->ground
			|| !game->closedexit || !game->right_player || !game->left_player
			|| !game->wall || !game->count_moves || !game->collectible
			|| !game->enemies)
	{
		ft_printf("Invalid map components");
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
		exit(0);
	}
	return (0);
}
