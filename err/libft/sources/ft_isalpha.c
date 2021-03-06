/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:31:00 by nmauvari          #+#    #+#             */
/*   Updated: 2018/01/28 06:48:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if ((c >= 0101 && c <= 0132) ||
	(c >= 0141 && c <= 0172))
		return (1);
	else
		return (0);
}
