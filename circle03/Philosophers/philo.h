/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:16:27 by dpark             #+#    #+#             */
/*   Updated: 2022/12/12 19:17:52 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define EPSILON	10	
# define MILLI		1000

typedef enum e_vaild
{
	INVAILD,
	VAILD
}	t_vaild;

typedef enum e_status
{
	PICKUP,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	COMPLETE
}	t_status;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				eat_cmplt;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dining;
}	t_data;

typedef struct s_philo
{
	pthread_t	philo_t;
	int			id;
	int			l;
	int			r;
	int			eat_cnt;
	int			remain_time;
	long long	cur;
	long long	start;
	t_data		*data;
}	t_philo;

//utils.c
void	*ft_calloc(size_t cnt, size_t size);
bool	bool_atoi(int *dst, const char *str);
bool	wait_interval(int time, long long start_time);
bool	init_mutex(t_data *data);

//init
bool	init_parse(t_data *data, char **argv);
void	*routine(void *arg);

// print.c
bool	print_status(t_status status, int id, t_data *data);
bool	get_timestamp(long long *ret);

// action.c
void	_sleep(t_philo *philo, t_data *data);
void	_eating(t_philo *philo, t_data *data);
void	_thinking(t_philo *philo, t_data *data);

#endif