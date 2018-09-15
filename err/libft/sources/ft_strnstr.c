/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:01:04 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 08:55:05 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char*)haystack);
	while (len && *haystack)
	{
		i = 0;
		while (len - i && haystack[i] == needle[i] && haystack[i])
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
		len--;
		haystack++;
	}
	return (0);
}
