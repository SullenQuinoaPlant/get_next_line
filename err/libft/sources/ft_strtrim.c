/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 06:21:17 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/04 06:46:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*ss;
	size_t	l;

	if (!s)
		return (0);
	while (!(*s ^ ' ' && *s ^ '\t' && *s ^ '\n'))
		s++;
	l = 0;
	while (s[l])
		l++;
	if (l)
	{
		l--;
		while (l && !(s[l] ^ ' ' && s[l] ^ '\t' && s[l] ^ '\n'))
			l--;
		l++;
	}
	if ((ss = malloc(l + 1)))
	{
		ss[l] = '\0';
		while (l--)
			ss[l] = s[l];
	}
	return (ss);
}
