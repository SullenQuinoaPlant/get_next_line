/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:59:22 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/27 08:43:35 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;
	int		diff;

	diff = 0;
	index = 0;
	while (n-- &&\
			!(diff = (0xff & s1[index]) - (0xff & s2[index])) &&\
			s1[index])
	{
		index++;
	}
	return (diff);
}
