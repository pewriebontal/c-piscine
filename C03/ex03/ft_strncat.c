/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:08:08 by mikhaing          #+#    #+#             */
/*   Updated: 2025/07/30 14:21:51 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*stupid;
	unsigned int	i;

	stupid = dest;
	i = 0;
	while (*dest)
		dest++;
	while (i < nb && *src)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (stupid);
}
