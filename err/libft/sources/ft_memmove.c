/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 06:29:12 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 08:43:58 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		next;
	size_t	pos;

	if (dest > src && dest < (src + n))
	{
		pos = n - 1;
		next = -1;
	}
	else
	{
		pos = 0;
		next = 1;
	}
	while (n--)
	{
		((char*)dest)[pos] = ((char*)src)[pos];
		pos += next;
	}
	return (dest);
}
