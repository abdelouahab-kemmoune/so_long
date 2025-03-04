/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:11:46 by akemmoun          #+#    #+#             */
/*   Updated: 2025/02/28 18:00:15 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_image(t_game *game, int xpos, int ypos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, xpos,
			ypos);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->ground, xpos,
			ypos);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->closedexit, xpos,
			ypos);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible,
			xpos, ypos);
	else if (c == 'P')
	{
		if (game->flag == 1)
			mlx_put_image_to_window(game->mlx, game->window, game->left_player,
				xpos, ypos);
		else
			mlx_put_image_to_window(game->mlx, game->window, game->right_player,
				xpos, ypos);
	}
}

void	map_render(t_game *game, char **map, int img_height, int img_width)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			x_pos = j * img_width;
			y_pos = i * img_height;
			map_image(game, x_pos, y_pos, map[i][j]);
			j++;
		}
		i++;
	}
}
