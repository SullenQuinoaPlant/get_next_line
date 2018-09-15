/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:52:48 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 08:46:50 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	length;

	length = ft_strlen(s);
	if ((new_s = malloc(++length)))
		while (length--)
			new_s[length] = s[length];
	return (new_s);
}
