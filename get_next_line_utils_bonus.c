/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:35:44 by dapereir          #+#    #+#             */
/*   Updated: 2023/12/04 11:05:01 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s2;

	s2 = (char *)s;
	while (*s2)
	{
		if (*s2 == (char)c)
			return (s2);
		s2++;
	}
	if ((char)c == '\0')
		return (s2);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		dest[i] = s2[i - len1];
		i++;
	}
	dest[len1 + len2] = '\0';
	return (dest);
}
