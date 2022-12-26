/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:51:57 by frgojard          #+#    #+#             */
/*   Updated: 2022/05/11 12:17:17 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*desti;
	const char	*s;

	i = 0;
	desti = dest;
	s = src;
	while (i < n)
	{
		desti[i] = s[i];
		i++;
	}
	return (dest);
}
