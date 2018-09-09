/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:58:40 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:02:09 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (dest[i])
		i++;
	while (n-- && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
