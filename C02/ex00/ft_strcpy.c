/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:59:18 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/25 08:30:44 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	// Test 1:
	char dest1[20] = "Hello World!";
	char src1[20] = "";
	ft_strcpy(dest1, src1);
	write(1, "\nTest1, Src: ", 14);
	write(1, "\nDest: ", 8);
	write(1, &dest1, sizeof(dest1));
	// Test 2:
	char dest2[20] = "Hey 42, Yo!";
	char src2[20] = "Hello 42, Yo!";
	ft_strcpy(dest2, src2);
	write(1, "\nTest2, Src: Hello 42, Yo!", 27);
	write(1, "\nDest: ", 8);
	write(1, &dest2, sizeof(dest2));
}
*/
