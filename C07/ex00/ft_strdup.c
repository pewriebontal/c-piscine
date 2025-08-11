/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:11:29 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/11 14:42:36 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	int		i;
	size_t	len;
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

// int	main(void)
// {
// 	char	*hel;
// 	char	*str;

// 	hel = "Yo Man";
// 	str = ft_strdup(hel);
// 	ft_putstr(str);
// 	return (0);
// }
