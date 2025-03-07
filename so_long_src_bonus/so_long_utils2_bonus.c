/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:37:56 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/07 02:46:13 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	load_all_sprites2(t_game *game)
// {
// 	game->frames[0] = game->collectible;
// 	game->frames[1] = mlx_xpm_file_to_image(game->mlx, "./assets/diamond2.xpm",
// 			&game->img_width, &game->img_height);
// 	game->frames[2] = mlx_xpm_file_to_image(game->mlx, "./assets/diamond3.xpm",
// 			&game->img_width, &game->img_height);
// 	game->frames[3] = mlx_xpm_file_to_image(game->mlx, "./assets/diamond4.xpm",
// 			&game->img_width, &game->img_height);
// 	game->frames[4] = mlx_xpm_file_to_image(game->mlx, "./assets/diamond5.xpm",
// 			&game->img_width, &game->img_height);
// }

// void	free_all2(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (game->frames[i])
// 		{
// 			mlx_destroy_image(game->mlx, game->frames[i]);
// 			game->frames[i] = NULL;
// 			i++;
// 		}
// 	}
// }

// int	close_window2(t_game *game)
// {
// 	if (game->window)
// 	{
// 		mlx_destroy_window(game->mlx, game->window);
// 		game->window = NULL;
// 	}
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 	}
// 	return (0);
// }
