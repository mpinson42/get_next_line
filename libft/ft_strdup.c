/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:14:37 by mpinson           #+#    #+#             */
/*   Updated: 2016/12/06 13:26:25 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (src != 0)
	{
		str = (char*)malloc(sizeof(*str) * i + 1);
		if (str != 0)
		{
			while (src[j] != '\0')
			{
				str[j] = src[j];
				j++;
			}
			str[j] = '\0';
			return (str);
		}
	}
	return (0);
}
