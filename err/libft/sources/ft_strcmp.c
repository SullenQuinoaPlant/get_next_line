/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:52:19 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:56:26 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;
	int		diff;

	index = 0;
	while (!(diff = (0xff & s1[index]) - (0xff & s2[index])) && s1[index++])
		;
	return (diff);
}
