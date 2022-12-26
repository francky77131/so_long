/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:18:20 by frgojard          #+#    #+#             */
/*   Updated: 2022/06/01 11:34:54 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j])
		j++;
	while (src[len] && (i + len + 1) < size)
	{
		dst[i + len] = src[len];
		len++;
	}
	if (i != size)
		dst[i + len] = '\0';
	return (i + j);
}
