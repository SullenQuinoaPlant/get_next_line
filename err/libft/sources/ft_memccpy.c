/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:44:21 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 09:38:28 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((char*)dest) = *((char*)src);
		dest = (char*)dest + 1;
		if (*((char*)src) == (char)c)
			return (dest);
		src = (char*)src + 1;
	}
	return (0);
}
