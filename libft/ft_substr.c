/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franckgojard <franckgojard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 07:15:06 by frgojard          #+#    #+#             */
/*   Updated: 2022/06/02 18:43:15 by franckgojar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = -1;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) - start < len)
		str = malloc(sizeof(char) * (ft_strlen(s) + 1 - start));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	str[j] = 0;
	return (str);
}
