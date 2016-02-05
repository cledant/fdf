/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit_whitespaces_content.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:29:57 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 12:29:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		ft_lstsplit_whitespaces_content(t_list *list)
{
	char	*tmp;
	char	**split;

	while (list != NULL)
	{
		if (list->content_size > 1)
		{
			tmp = list->content;
			split = ft_strsplit_allspace(tmp);
			if (split == NULL)
			{
				ft_lstdel(&list, &ft_bzero);
				return (0);
			}
			list->content = split;
			ft_strdel(&tmp);
		}
		list = list->next;
	}
	return (1);
}
