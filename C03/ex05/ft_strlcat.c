/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:08:57 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/31 16:08:16 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	total_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	total_len = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	while (*src && dest_len + 1 < size)
	{
		dest[dest_len] = *src;
		dest_len++;
		src++;
	}
	dest[dest_len] = '\0';
	return (total_len);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	char *dest = NULL;
// 	// char dest[20] = "Hello, ";
// 	char src[] = "World!";
// 	unsigned int size = 20;

// 	unsigned int result = ft_strlcat(dest, src, size);

// 	// Output the result
// 	printf("Resulting string: %s\n", dest);
// 	printf("Total length: %u\n", result);

// 	return (0);
// }
