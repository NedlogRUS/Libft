/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:05:45 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/01 16:15:52 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*res;
	char			*d;

	i = start;
	i = ft_strlen(&s[i]);
	res = (char *)malloc((i + 1) * sizeof(char));
	d = res;
	j = 0;
	i = start;
	if (ft_strlen(&s[i]) > start)
	{
		while (s[i] != '\0' && j < len)
		{
			d[j] = s[i];
			i++;
			j++;
		}
	}
	d[j] = '\0';
	return (d);
}
