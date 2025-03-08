/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:42:57 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 01:16:52 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_count(t_game *game)
{
	char	*buffer;
	int		x;
	int		y;

	if (game->count_moves)
		mlx_destroy_image(game->mlx, game->count_moves);
	game->count_moves = mlx_xpm_file_to_image(game->mlx, \
	"./assets/count.xpm", &game->img_width, &game->img_height);
	x = 20;
	y = ((game->rows * game->img_height) + 52) - 20;
	mlx_put_image_to_window(game->mlx, \
	game->window, game->count_moves, x + 50, y - 30);
	mlx_string_put(game->mlx, game->window, x, y, 0xFFFFFF, "Moves: ");
	buffer = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->window, x + 55, y, 0xFFFFFF, buffer);
	free(buffer);
}
