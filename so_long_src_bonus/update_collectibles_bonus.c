/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collectibles_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:50:45 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 01:44:02 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_collectibles(t_game *game)
{
	static int	frame = 0;
	static int	counter = 0;

	counter++;
	if (counter >= 10)
	{
		counter = 0;
		frame++;
		if (frame >= 5)
			frame = 0;
		game->collectible = game->frames[frame];
	}
	map_render(game, game->map, game->img_height, game->img_width);
}
