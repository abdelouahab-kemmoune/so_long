/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:10:55 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 21:22:01 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int handle_keys(t_game *game)
{
	t_npos pos = {game->p_xpos, game->p_ypos};

	mvt(&pos, game);
	if (game->map[pos.n_ypos][pos.n_xpos] == '1')
		return (0);
	if (handle_special_cases(game, &pos))
		return (0);
	if ((game->p_xpos != pos.n_xpos || game->p_ypos != pos.n_ypos)
		&& game->map[pos.n_ypos][pos.n_xpos] != 'E')
	{
		update_player_position(game, &pos);
		map_render(game, game->map, game->img_width, game->img_height);
		game->count++;
		ft_printf("Moves: %d\n", game->count);
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
	handle_keys(game);
	return (1);
}
