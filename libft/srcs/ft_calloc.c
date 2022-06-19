/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:43:18 by root              #+#    #+#             */
/*   Updated: 2021/05/20 14:41:06 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = (void *)malloc(size * nmemb);
	if (!mem)
	{
		printf("Error\nThe malloc failed\n");
		return (NULL);
	}
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
