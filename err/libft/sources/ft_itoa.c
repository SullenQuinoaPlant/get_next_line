/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:32:34 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 06:37:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	here_recursion(int n, unsigned int rank, unsigned int *b10_sz,\
							char **buff)
{
	if (n)
	{
		here_recursion(n / 10, rank + 1, b10_sz, buff);
		if (*buff)
			(*buff)[*b10_sz - 1 - rank] =\
				'0' + (n > 0 ? n % 10 : -(n % 10));
	}
	else
	{
		*b10_sz += rank;
		if ((*buff = malloc(*b10_sz + 1)))
			(*buff)[*b10_sz] = '\0';
	}
}

char		*ft_itoa(int n)
{
	char			*a;
	unsigned int	b10_sz;

	b10_sz = n <= 0 ? 1 : 0;
	a = (void*)0;
	here_recursion(n, 0, &b10_sz, &a);
	if (n < 0)
		a ? a[0] = '-' : (1);
	if (n == 0)
		a ? a[0] = '0' : (1);
	return (a);
}
