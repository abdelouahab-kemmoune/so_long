/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:55 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/04 00:24:04 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keys_util1(t_game *game)
{
	if (is_exit_valid(game) == 0)
	{
		ft_printf("You won!\n");
		close_window(game);
	}
	else if (!game->exit_message_displayed)
	{
		ft_printf("You must collect all diamonds before exiting!\n");
		game->exit_message_displayed = 1;
		return (0);
	}
	return (0);
}

int	handle_keys_util2(t_game *game)
{
	t_npos	pos;

	game->has_collected = 1;
	game->map[pos.n_ypos][pos.n_xpos] = '0';
	game->count++;
	ft_printf("Moves: %d\n", game->count);
	return (0);
}

int	handle_keys_util3(t_game *game)
{
	t_npos	pos;

	game->map[game->p_ypos][game->p_xpos] = '0';
	game->map[pos.n_ypos][pos.n_xpos] = 'P';
	map_render(game, game->map, game->img_width, game->img_height);
	game->p_xpos = pos.n_xpos;
	game->p_ypos = pos.n_ypos;
	game->count++;
	ft_printf("Moves: %d\n", game->count);
	game->exit_message_displayed = 0;
	return (0);
}
