/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akemmoun <akemmoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:42:48 by akemmoun          #+#    #+#             */
/*   Updated: 2025/03/08 21:21:47 by akemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC_KEY 65307

# include "../ft_printf/ft_printf.h"
# include "../mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_game
{
	int		p_xpos;
	int		p_ypos;
	int		img_width;
	int		img_height;
	int		count;
	int		keypress;
	int		flag;
	int		rows;
	int		cols;
	int		exit_message_displayed;
	int		ignore_exit;
	int		has_collected;
	int		curr_frame;
	void	*mlx;
	void	*window;
	void	*ground;
	void	*wall;
	void	*right_player;
	void	*left_player;
	void	*collectible;
	void	*closedexit;
	void	*count_moves;
	void	*frames[5];
	char	**map;
}			t_game;

typedef struct s_data
{
	int		rows;
	int		cols;
	int		exit;
	int		player;
	int		collectibles;
}			t_data;

typedef struct s_npos
{
	int		n_ypos;
	int		n_xpos;
}			t_npos;

typedef struct s_sprite
{
	void	*img;
	int		width;
	int		height;
}			t_sprite;

void		put_count(t_game *game);
// void	load_frame(t_game *game);
void		*ft_memset(void *str, int c, size_t len);
void		map_render(t_game *game, char **map, int img_height, int img_width);
void		find_player(char **map, t_game *game);
void		put_digit(t_game *game, int digit, int x, int y);
char		*read_file_to_buffer(int fd);
void		ft_check_files(t_game *game);
void		free_all(t_game *game);
void update_player_position(t_game *game, t_npos *pos);
// void		set_zero(t_game *game);

char		*ft_strncpy(char *dest, char const *src, int n);
char		**ft_copy(char const *s, char c, int words, char **array);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		**copy_map(t_game *game, char **map);
char		**get_map(char *name, t_game *game);
char		*ft_strchr(const char *str, int c);

int			is_map_empty(char **map, t_game *game);
int			is_exit_valid(t_game *game);
int handle_special_cases(t_game *game, t_npos *pos);
// int			handle_keys_util1(t_game *game);
// int			handle_keys_util2(t_game *game);
// int			handle_keys_util3(t_game *game);
int			file_check(char *filename);
int			is_path_to_exit(char **map, t_game *game);
int			is_path_to_collect(char **map, t_game *game);
int			handle_keys(t_game *game);
int			keycode(int keycode, t_game *game);
int			loop(t_game *game);
int			close_window(t_game *game);
int			check_components(char **map, t_data *data);
int			game_manager(char **map, t_data *data);
int			surrounded_bywalls(char **map, t_data *data);
int			map_rectangular(char **map, t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);

#endif