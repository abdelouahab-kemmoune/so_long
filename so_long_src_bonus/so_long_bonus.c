/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:10:10 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/14 21:05:49 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_all(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->left_player)
		mlx_destroy_image(game->mlx, game->left_player);
	if (game->right_player)
		mlx_destroy_image(game->mlx, game->right_player);
	if (game->closedexit)
		mlx_destroy_image(game->mlx, game->closedexit);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->enemies)
		mlx_destroy_image(game->mlx, game->enemies);
	if (game->count_moves)
		mlx_destroy_image(game->mlx, game->count_moves);
	free_all2(game);
}

int	close_window(t_game *game)
{
	int	i;

	free_all(game);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
	i = 0;
	close_window2(game);
	exit(0);
}

void	load_all_sprites(t_game *game)
{
	game->ground = mlx_xpm_file_to_image(game->mlx, "./assets/ground.xpm",
			&game->img_width, &game->img_height);
	game->closedexit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&game->img_width, &game->img_height);
	game->right_player = mlx_xpm_file_to_image(game->mlx,
			"./assets/right_steve.xpm", &game->img_width, &game->img_height);
	game->left_player = mlx_xpm_file_to_image(game->mlx,
			"./assets/left_steve.xpm", &game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->img_width, &game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"./assets/diamond1.xpm", &game->img_width, &game->img_height);
	game->count_moves = mlx_xpm_file_to_image(game->mlx,
			"./assets/count.xpm", &game->img_width, &game->img_height);
	game->enemies = mlx_xpm_file_to_image(game->mlx, "./assets/enemy.xpm",
			&game->img_width, &game->img_height);
	load_all_sprites2(game);
	ft_check_files(game);
}

void	init_game(t_game *game, char *av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("ERROR: Failed to initialize mlx.\n");
		exit(1);
	}
	game->map = get_map(av, game);
	if (!game->map || is_map_empty(game->map, game))
	{
		ft_printf("ERROR: Failed to load map.\n");
		close_window(game);
	}
	game->cols = ft_strlen(game->map[0]);
	while (game->map[game->rows] != NULL)
		game->rows++;
	load_all_sprites(game);
	game->window = mlx_new_window(game->mlx, game->cols * game->img_width,
			game->rows * game->img_height + 52, "minecraft");
	if (!game->window)
	{
		ft_printf("ERROR: Failed to create window.\n");
		close_window(game);
	}
}

int	main(int ac, char **av)
{
	t_game	game;
	t_data	data;

	if (ac == 2)
	{
		init_game(&game, av[1]);
		if (file_check(av[1]) == 0)
		{
			ft_printf("ERROR:\nWrong file format!!");
			close_window(&game);
		}
		find_player(game.map, &game);
		is_path_to_collect(game.map, &game);
		is_path_to_exit(game.map, &game);
		if (game_manager(game.map, &data) == 0)
			close_window(&game);
		map_render(&game, game.map, game.img_height, game.img_width);
		mlx_hook(game.window, 2, 1L << 0, keycode, &game);
		mlx_loop_hook(game.mlx, loop, &game);
		mlx_hook(game.window, 17, 0, close_window, &game);
		mlx_loop(game.mlx);
		close_window(&game);
	}
	return (0);
}
