/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:13:09 by dpark             #+#    #+#             */
/*   Updated: 2022/04/17 17:33:42 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	find_type(va_list ap, const char *str, int *len);
void	ft_putnbr_fd(int n, int fd, int *len);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd, int *len);
void	ft_putstr_fd(char *c, int fd, int *len);
void	ft_unputnbr_fd(unsigned long int n, int fd, int *len);
void	ft_putnbr_base(unsigned long nbr, char *base, int *len);
void	format_c(va_list ap, int *len);
void	format_s(va_list ap, int *len);
void	format_p(va_list ap, int *len);
void	format_d_i(va_list ap, int *len);
void	format_u(va_list ap, int *len);
void	format_x(va_list ap, int *len);
void	format_X(va_list ap, int *len);

#endif
