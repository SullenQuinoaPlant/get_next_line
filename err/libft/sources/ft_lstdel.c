/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:38:16 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/15 08:36:59 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst)
	{
		while (*alst)
		{
			next = (*alst)->next;
			if (del)
				del((*alst)->content, (*alst)->content_size);
			**alst = (t_list){0, 0, 0};
			free(*alst);
			*alst = next;
		}
		*alst = 0;
	}
}
