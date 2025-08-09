/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:02:01 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/09 22:10:45 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str, int apply_space)
{
	int	len;

	if (!str)
		return ;
	if (apply_space)
		write(1, " ", 1);
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && (*s1 && *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}