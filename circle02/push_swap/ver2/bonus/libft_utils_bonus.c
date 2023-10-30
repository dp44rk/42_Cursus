/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpark <dpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:16:29 by dpark             #+#    #+#             */
/*   Updated: 2022/11/26 08:16:31 by dpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *str)
{
	const char	*origin;

	origin = str;
	while (*str)
		str++;
	return ((size_t)(str - origin));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = (size_t)ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;
	size_t	off;
	ssize_t	res;

	len = ft_strlen(s);
	off = 0;
	while (off < len)
	{
		res = write(fd, s + off, len - off);
		if (res < 0)
			exit(EXIT_FAILURE);
		off += res;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ptr++ = uc;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	if (count == 0 || size == 0 || size > ((size_t)(-1)) / count)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	ft_memset(ret, 0, count * size);
	return (ret);
}
