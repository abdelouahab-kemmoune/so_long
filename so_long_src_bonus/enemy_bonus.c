/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:44:09 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/04 00:25:30 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_enemy(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'X')
				count++;
			j++;
		}
		i++;
	}
}

int	put_enemy(t_game *game)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			x_pos = i * game->img_width;
			y_pos = j * game->img_height;
			if (game->map[i][j] == 'X')
				mlx_put_image_to_window(game->mlx, game->window, game->enemies,
					x_pos, y_pos);
			j++;
		}
		i++;
	}
	return (0);
}
