/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:10:10 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/07 23:46:03 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_exit_valid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	mvt(t_npos *npos, t_game *game)
{
	if (game->keypress == ESC_KEY)
		close_window(game);
	if (game->keypress == 'w')
		npos->n_ypos--;
	else if (game->keypress == 's')
		npos->n_ypos++;
	else if (game->keypress == 'a')
	{
		game->flag = 1;
		npos->n_xpos--;
	}
	else if (game->keypress == 'd')
	{
		npos->n_xpos++;
		game->flag = 2;
	}
}

int	handle_keys(t_game *game)
{
	t_npos	pos;

	pos.n_xpos = game->p_xpos;
	pos.n_ypos = game->p_ypos;
	mvt(&pos, game);
	if (game->map[pos.n_ypos][pos.n_xpos] == '1')
		return (0);
	else if (game->map[pos.n_ypos][pos.n_xpos] == 'X')
		close_window(game);
	else if (game->map[pos.n_ypos][pos.n_xpos] == 'E')
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
	}
	else if (game->map[pos.n_ypos][pos.n_xpos] == 'C')
	{
		game->has_collected = 1;
		game->map[pos.n_ypos][pos.n_xpos] = '0';
		game->count++;
		put_count(game);
	}
	if ((game->p_xpos != pos.n_xpos || game->p_ypos != pos.n_ypos)
		&& game->map[pos.n_ypos][pos.n_xpos] != 'E')
	{
		game->map[game->p_ypos][game->p_xpos] = '0';
		game->map[pos.n_ypos][pos.n_xpos] = 'P';
		map_render(game, game->map, game->img_width, game->img_height);
		game->p_xpos = pos.n_xpos;
		game->p_ypos = pos.n_ypos;
		game->count++;
		put_count(game);
		game->exit_message_displayed = 0;
	}
	game->keypress = 0;
	return (0);
}

int	keycode(int keycode, t_game *game)
{
	game->keypress = keycode;
	return (1);
}

int	loop(t_game *game)
{
	static int	frame_counter = 0;

	if (frame_counter++ >= 10)
	{
		game->curr_frame = (game->curr_frame + 1) % 5;
		update_collectibles(game);
		frame_counter = 0;
	}
	handle_keys(game);
	put_count(game);
	return (1);
}
