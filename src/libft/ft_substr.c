/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cha <aben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:43:24 by aben-cha          #+#    #+#             */
/*   Updated: 2024/07/09 11:30:10 by aben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	s_length;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length)
		return (ft_strdup(""));
	if (len > (s_length - start))
		len = s_length - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
