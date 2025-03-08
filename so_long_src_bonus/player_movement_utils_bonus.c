/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:51:02 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 22:32:54 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_special_cases(t_game *game, t_npos *pos)
{
	if (game->map[pos->n_ypos][pos->n_xpos] == 'X')
		close_window(game);
	else if (game->map[pos->n_ypos][pos->n_xpos] == 'E')
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
			return (1);
		}
	}
	else if (game->map[pos->n_ypos][pos->n_xpos] == 'C')
	{
		game->has_collected = 1;
		game->map[pos->n_ypos][pos->n_xpos] = '0';
		game->count++;
		put_count(game);
	}
	return (0);
}

void	update_player_position(t_game *game, t_npos *pos)
{
	game->map[game->p_ypos][game->p_xpos] = '0';
	game->map[pos->n_ypos][pos->n_xpos] = 'P';
	game->p_xpos = pos->n_xpos;
	game->p_ypos = pos->n_ypos;
}
