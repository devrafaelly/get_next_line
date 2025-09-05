/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:14:08 by rafaoliv          #+#    #+#             */
/*   Updated: 2025/09/05 16:29:19 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	ft_memcpy(sub_s, &s[start], len);
	sub_s[len] = '\0';
	return (sub_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	s1_len;
	size_t	s2_len;
	size_t	str_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	str_len = s1_len + s2_len;
	strjoin = ft_calloc(str_len + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_memcpy(strjoin, s1, s1_len);
	ft_memcpy(strjoin + s1_len, s2, s2_len);
	return (strjoin);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*address;
	size_t	address_size;
	size_t	i;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	address_size = (nmemb * size);
	if (address_size == 0)
		address_size = 1;
	address = malloc(address_size);
	if (!address)
		return (NULL);
	i = 0;
	while (i < address_size)
	{
		address[i] = '\0';
		i++;
	}
	return (address);
}
