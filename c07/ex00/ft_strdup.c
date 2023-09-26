/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:11:29 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:11:29 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
	{
		return (0);
	}
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*hel;
	char	*str;

	hel = "Yo Man";
	str = ft_strdup(hel);
	ft_putstr(str);
	return (0);
}
*/
