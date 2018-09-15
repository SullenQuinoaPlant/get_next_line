/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:00:46 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 08:57:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	count_strings(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (!(*s ^ c) && *s)
			s++;
		count += *s ? 1 : 0;
		while (*s ^ c && *s)
			s++;
	}
	return (count);
}

static void		fill_splits_ar(char **ar, char const *s, char c)
{
	size_t	l;
	size_t	ll;

	while (*s)
	{
		while (!(*s ^ c) && *s)
			s++;
		l = 0;
		while (s[l] ^ c && s[l])
			l++;
		if ((*ar = l ? malloc(l + 1) : 0))
		{
			ll = 0;
			while (l--)
				(*ar)[ll++] = *s++;
			(*(ar++))[ll] = '\0';
		}
	}
	*ar = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**ar;

	if (!s)
		return (0);
	count = count_strings(s, c);
	if ((ar = malloc(++count * sizeof(char*))))
		fill_splits_ar(ar, s, c);
	return (ar);
}
