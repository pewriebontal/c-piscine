/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:57 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:04:57 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
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

	src_len = str_len(src);
	dest_len = str_len(dest);
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
