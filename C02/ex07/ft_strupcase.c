/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:09:17 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/05 13:49:08 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islow(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (ft_islow(*str))
			*str -= 32;
		++str;
	}
	return (ptr);
}
