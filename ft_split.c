/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:01:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/04/07 12:49:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count(char const *src, char sep, int *i)
{
	int	word;

	*i = 0;
	word = 0;
	while (*src)
	{
		while (*src == sep)
			src++;
		if (*src != sep && *src)
			word++;
		while (*src != sep && *src)
			src++;
	}
	return (word);
}

char	**ft_split(char const *src, char sep)
{
	char		**new;
	int			i;
	const int	words = ft_count(src, sep, &i);
	int			len;

	if (!src)
		return (NULL);
	new = ft_calloc(sizeof(char *), (words + 1));
	if (!new)
		return (NULL);
	while (i < words)
	{
		while (*src && *src == sep)
			src++;
		if (ft_strchr(src, sep))
			len = ft_strchr(src, sep) - src;
		else
			len = ft_strlen(src);
		new[i] = ft_substr(src, 0, len);
		if (!new[i])
			return (0);
		src += len;
		i++;
	}
	return (new);
}
