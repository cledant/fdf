/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:01:34 by cledant           #+#    #+#             */
/*   Updated: 2015/11/25 10:00:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*cpy_b;
	size_t	counter;

	counter = 0;
	cpy_b = b;
	while (counter < len)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
		counter++;
	}
	return (cpy_b);
}
