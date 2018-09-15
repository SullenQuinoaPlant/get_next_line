/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:57:39 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/15 08:39:20 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	size_t	l;

	if (!(s && f))
		return (0);
	l = 0;
	while (s[l])
		l++;
	if ((ss = malloc(l + 1)))
	{
		ss[l] = '\0';
		while (l--)
			ss[l] = f((unsigned int)l, s[l]);
	}
	return (ss);
}
