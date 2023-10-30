/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:16:13 by dpark             #+#    #+#             */
/*   Updated: 2022/12/12 18:58:02 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	terminate(t_vaild status, t_data *data, char *msg)
{
	int	i;

	i = 0;
	if (data)
	{
		while (i < data->num_of_philo)
			pthread_mutex_destroy(&data->forks[i++]);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dining);
	}
	if (msg)
		printf("%s", msg);
	if (status == INVAILD)
		return (INVAILD);
	return (VAILD);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (terminate(INVAILD, NULL, "argc error"));
	if (!init_parse(&data, argv))
		return (terminate(INVAILD, &data, "parsing error"));
	return (terminate(VAILD, &data, NULL));
}
