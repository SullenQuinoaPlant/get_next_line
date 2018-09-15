/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:57:13 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:02:09 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*s;

	if (!(s1 && s2))
		return (0);
	l = ft_strlen(s1) + ft_strlen(s2);
	if ((s = malloc(l + 1)))
	{
		l = 0;
		while (*s1 || *s2)
			s[l++] = *s1 ? *s1++ : *s2++;
		s[l] = '\0';
	}
	return (s);
}
