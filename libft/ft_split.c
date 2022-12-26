/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franckgojard <franckgojard@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:07:44 by frgojard          #+#    #+#             */
/*   Updated: 2022/06/02 18:40:54 by franckgojar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char sep)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			words++;
			while (str[i] != 0 && str[i] != sep)
				i++;
		}
	}
	return (words);
}

static void	ft_countchar(const char *str, char sep, int *tab)
{
	int	nbchr;
	int	i;
	int	k;

	i = 0;
	k = 0;
	nbchr = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] != sep && str[i])
		{
			while (str[i] && str[i] != sep)
			{
				i++;
				nbchr++;
			}
			tab[k] = nbchr;
			k++;
			nbchr = 0;
		}
	}
}

static char	**ft_print(char const *s, char **str, int nbwords, char c)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int *) * nbwords);
	if (!tab)
		return (NULL);
	ft_countchar(s, c, tab);
	while (i < nbwords)
	{
		while (s[j] == c && s[j])
			j++;
		str[i] = ft_substr(s, j, tab[i]);
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	free(tab);
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nbwords;

	if (!s)
		return (NULL);
	nbwords = ft_countwords(s, c);
	str = malloc(sizeof(char *) * (nbwords + 1));
	if (!str)
		return (NULL);
	ft_print(s, str, nbwords, c);
	return (str);
}
