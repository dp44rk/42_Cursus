/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:54 by dpark             #+#    #+#             */
/*   Updated: 2023/03/06 17:12:55 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// 벡터
typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

/* 식별자 매크로 */
typedef int				t_bool;
typedef unsigned int	t_size;

// gnl
# define BUFFER_SIZE 100

// canvas size
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define FALSE 0
# define TRUE 1

typedef enum e_object_type
{
	SP = 0,
	LIGHT_POINT,
	PL,
	CY,
	CN
}	t_object_type;

# define EPSILON 1e-6 // 0.000001
# define LUMEN 3  // 이 값을 조절하여 장면의 밝기를 조절할 수 있다.
/* for specular */
# define SHININESS_VALUE 64
# define SPECULAR_STRENGTH 0.5
// for mlx
// event mapping
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_CLOSE 17

// key mapping
# define KEY_ESC 53

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

// 광선
typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

/*오브젝트*/
typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
	t_color3	albedo;
}	t_sphere;

typedef struct s_plane
{
	t_point3	x;
	t_vec3		normal;
	t_color3	albedo;
}	t_plane;

typedef struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		radius;
	double		height;
	t_color3	albedo;
}	t_cylinder;

typedef struct s_cone
{
	double		theta;
	double		height;
	t_vec3		center;
	t_vec3		v;
	t_color3	albedo;
	double		cos_theta;
	double		cos_theta2;
	double		radius;
}	t_cone;

typedef struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
}	t_light;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
}	t_hit_record;

typedef struct s_camera
{
	t_point3	origin;
	t_vec3		dir;
	double		fov;
	t_vec3		right_normal;
	t_vec3		up_normal;
	t_point3	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
}	t_canvas;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			primary_ray;
	t_hit_record	rec;
	int				num_of_camera;
	int				num_of_ambient;
}	t_scene;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;

	t_vec3	*pixels;

	int		w;
	int		h;

	int		line_length;
	int		bits_per_pixel;
	int		endian;

	char	*addr;

}	t_data;

typedef enum e_comparison_mode
{
	Nothing = 0,
	Left,
	Right,
	Both
}	t_comparison_mode;

#endif
