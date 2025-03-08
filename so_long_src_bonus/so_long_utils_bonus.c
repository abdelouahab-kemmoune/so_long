/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:49:25 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 20:56:01 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_map(int fd)
{
	char	*file;
	char	*temp;
	char	*line;

	file = ft_strdup("");
	while ((line = get_next_line(fd)))
	{
		if (!line)
			return (free(file), NULL);
		temp = file;
		file = ft_strjoin(file, line);
		free(temp);
		free(line);
		if (!file)
			return (NULL);
	}
	return (file);
}

char	**get_map(char *name, t_game *game)
{
	int		fd;
	char	*file;
	char	**map;

	fd = open(name, O_RDWR);
	if (fd < 0)
	{
		ft_printf("ERROR:\nCannot open file!");
		close_window(game);
	}
	file = read_map(fd);
	close (fd);
	if (!file)
		close_window(game);
	map = ft_split(file, '\n');
	free(file);
	close(fd);
	return (map);
}

int	file_check(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
		return (0);
	return (1);
}

void	find_player(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->p_xpos = j;
				game->p_ypos = i;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_files(t_game *game)
{
	if (!(game->frames[0] || game->frames[1] || game->frames[2]
			|| game->frames[3] || game->frames[4] || game->ground
			|| game->closedexit || game->right_player || game->left_player
			|| game->wall || game->count_moves || game->collectible
			|| game->enemies))
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
		// (void)game;
		close_window(game);
		exit (0);
	}
	return (0);
}
