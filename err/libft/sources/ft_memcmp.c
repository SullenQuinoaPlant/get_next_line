/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:43:36 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/27 08:16:31 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *((char*)s1) == *((char*)s2))
	{
		s1 = (char*)s1 + 1;
		s2 = (char*)s2 + 1;
	}
	return ((int)(*(unsigned char*)s1 - *(unsigned char*)s2));
}
