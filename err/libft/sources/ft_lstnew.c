/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 06:41:13 by nmauvari          #+#    #+#             */
/*   Updated: 2017/12/06 07:58:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))))
	{
		new->next = 0;
		new->content_size = content ? content_size : 0;
		if ((new->content = new->content_size ? malloc(new->content_size) : 0))
			ft_memcpy(new->content, content, content_size);
	}
	return (new);
}
