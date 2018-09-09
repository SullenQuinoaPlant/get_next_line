/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:01:46 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/15 08:42:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] && haystack[i])
	{
		if (i > 0)
		{
			haystack++;
			i = 0;
		}
		while (*haystack != *needle && *haystack)
			haystack++;
		while (haystack[i] == needle[i] && haystack[i])
			i++;
	}
	return (!needle[i] ? (char*)haystack : 0);
}
