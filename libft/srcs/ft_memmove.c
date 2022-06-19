/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:47:48 by root              #+#    #+#             */
/*   Updated: 2021/05/23 15:40:03 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*td;
	unsigned char	*ts;
	size_t			i;

	if (dest == src)
		return (dest);
	td = (unsigned char *)dest;
	ts = (unsigned char *)src;
	i = 0;
	if (td > ts)
		while (n-- > 0)
			td[n] = ts[n];
	else
	{	
		while (i < n)
		{
			td[i] = ts[i];
			i++;
		}
	}
	return (dest);
}
