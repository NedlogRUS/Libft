/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:43:59 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/01 21:01:02 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*sd;

	i = 0;
	if (!s)
		return (0);
	sd = ft_strdup((char *)(s));
	while (sd[i])
	{
		sd[i] = f(i, sd[i]);
		i++;
	}
	return (sd);
}
