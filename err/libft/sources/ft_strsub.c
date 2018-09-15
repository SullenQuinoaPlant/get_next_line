/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:00:57 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/30 05:14:30 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	check_input(char const *s, unsigned int start, size_t const *len)
{
	size_t	available;

	available = ft_strlen(s);
	if (start + *len > available)
		return (0);
	return (1);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	ss = 0;
	if (s)
	{
		if (check_input(s, start, &len) && (ss = malloc(len + 1)))
		{
			ss[len] = '\0';
			while (len--)
				ss[len] = s[(size_t)start + len];
		}
	}
	return (ss);
}
