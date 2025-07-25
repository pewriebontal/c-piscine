/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:59:25 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 15:59:25 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*

#include <unistd.h>

int	main(void)
{
	// Test 1:
	char dest1[20] = "Hello World!";
	char src1[20] = "Yo! Man";
	ft_strncpy(dest1, src1, 5);
	write(1, "\nTest1, Src: ", 14);
	write(1, "\nDest: ", 8);
	write(1, "\nExpected: Yo! M World!\n", 25);
	write(1, &dest1, sizeof(dest1));
	// Test 2:
	char dest2[20] = "Hey 42, Yo!";
	char src2[20] = "Hello 42, Yo!";
	ft_strncpy(dest2, src2, 5);
	write(1, "\nTest2, Src: Hello 42, Yo!", 27);
	write(1, "\nDest: ", 8);
	write(1, "\nExpected: Hello2, Yo!\n", 24);
	write(1, &dest2, sizeof(dest2));
}
*/
