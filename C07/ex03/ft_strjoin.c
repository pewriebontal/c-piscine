/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:11:49 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/11 14:51:48 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	return_length(int size, char **strs, int sep_len)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			len += sep_len;
		}
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*result;

	if (size == 0)
	{
		result = malloc(1);
		return (result);
	}
	len = return_length(size, strs, ft_strlen(sep));
	i = 0;
	result = malloc(len + 1);
	if (NULL == result)
		return (0);
	while (i < size)
	{
		result = ft_strcpy(result, strs[i]);
		if (i + 1 < size)
			result = ft_strcpy(result, sep);
		i++;
	}
	*result = '\0';
	return (result - len);
}

// int	main(void)
// {
// 	char	*result;
// 	char	*strs[] = {"Hello","world","How are you?"};
// 	int	size;
// 	char	*sep;

// 	size = 3;
// 	sep = ", ";
// 	result = ft_strjoin(size, strs, sep);
// 	printf("Concatenated string: %s\n", result);
// 	free(result);
// 	return (0);
// }