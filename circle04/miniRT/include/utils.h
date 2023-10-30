/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:13:00 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:13:08 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "structures.h"

// vec_utils.c
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlength2(t_vec3 vec);

// vec_utils2.c
double		vlength(t_vec3 vec);
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec, double t);
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);

// vec_utils3.c
t_vec3		vdivide(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);

// vec_utils3.c
t_vec3		vmax(t_vec3 vec1, t_vec3 vec2);

// 오브젝트 유틸리티
void		oadd(t_object **list, t_object *obj);
t_object	*olast(t_object *list);

// utils1.c
t_size		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
t_bool		is_within(double value, double min_value,
				double max_value, t_comparison_mode mode);
void		ft_memset(void *ptr, int value, t_size n);
char		*ft_strchr(const char *s, char ch);

// utils2.c
t_bool		ft_ext_cmp(const char *ext, const char *path);

// ft_alert1.c
void		*ft_alert_calloc(t_size n);
void		*ft_alert_malloc(t_size n);
char		*ft_alert_strndup(const char *origin, t_size n);

// ft_2d_char_arr.c
void		ft_2d_char_arr_free(char **arr2);
t_size		ft_2d_char_arr_len(const char **arr);

// ft_split.c
char		**ft_alert_split(const char *origin, char delimiter);

// ft_atod.c
t_bool		ft_atod(const char *str, double *dest);

// ft_exit.c
void		aterr_exit(const char *s1, const char *s2);

// gnl.c
char		*get_next_line(int fd);

// on_mlx_loop.c
int			on_key_press(int keycode, void *x);
int			on_close(void *some_struct);

// draw_image.c
void		draw_image(t_data *x);

// render.c
void		render(t_scene *scene, t_vec3 **pixels, int h, int w);

#endif