/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:09:09 by akemmoun          #+#    #+#             */
/*   Updated: 2025/02/25 19:09:12 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handle(t_data data)
{
	if (data.exit > 1)
		return (ft_printf("Error:\nExtra exit\n"), 0);
	else if (data.exit == 0)
		return (ft_printf("Error:\nNo exit\n"), 0);
	if (data.player > 1)
		return (ft_printf("Error:\nExtra starting position\n"), 0);
	else if (data.player == 0)
		return (ft_printf("Error:\nNo starting position\n"), 0);
	if (data.collectibles < 1)
		return (ft_printf("Error:\nNo collectibles"), 0);
	return (1);
}

int	map_rectangular(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (i == 0)
			data->cols = ft_strlen(map[i]);
		else if ((int)ft_strlen(map[i]) != data->cols)
			return (0);
		data->rows++;
		i++;
	}
	return (1);
}

int	check_components(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (map[i][j] == 'P')
				data->player++;
			else if (map[i][j] == 'E')
				data->exit++;
			else if (map[i][j] == 'C')
				data->collectibles++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X'
				&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C')
				return (ft_printf("Error:\nExtra obj"), 0);
			j++;
		}
		i++;
	}
	if (error_handle(*data) == 0)
		return (0);
	return (1);
}

int	surrounded_bywalls(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if ((i == 0 || i == data->rows - 1 || j == 0 || j == data->cols - 1)
				&& map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	game_manager(char **map, t_data *data)
{
	data->rows = 0;
	data->cols = 0;
	data->player = 0;
	data->exit = 0;
	data->collectibles = 0;
	if (map_rectangular(map, data) == 0)
		return (ft_printf("ERROR:\nMap is not rectangular"), 0);
	if (surrounded_bywalls(map, data) == 0)
		return (ft_printf("Error:\nNot surrounded by walls"), 0);
	if (check_components(map, data) == 0)
		return (0);
	return (1);
}
