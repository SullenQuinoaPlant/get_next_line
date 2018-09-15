/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:54:36 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:56:26 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && dst[i])
		i++;
	if (i != size)
	{
		size -= (i + 1);
		while (size-- && *src)
			dst[i++] = *src++;
		dst[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
