/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:13:48 by apanikov          #+#    #+#             */
/*   Updated: 2023/02/08 21:46:16 by apanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (j);
}

char	*ft_putword(const char *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (0);
	i -= j;
	j = 0;
	while (s[i] && s[i] !=c)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

void	ft_free(int i, char **new)
{
	while (i > 0)
	{
		free(new[i - 1]);
		i--;
	}
	free(new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		wc;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	wc = ft_wordcount(s, c);
	new = malloc(sizeof(char *) * wc + 1) ;
	if (!new)
		return (new);
	while (i < wc)
	{
		while(s[j] && s[j] == c)
			j++;
		new[i] = ft_putword(&s[j], c);
		if (!new[i])
			ft_free(i, new);
		while (s[j] && s[j] !=c)
			j++;
		i++;
	}
	new[i] = 0;
	return (new);

}

/*
int	main(void)
{
	ft_split(" i don't want to set the world on fire ! ", ' ');
	return (0);
}
*/
