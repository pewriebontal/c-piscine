/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:11:11 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/05 13:48:59 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isup(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		if (ft_isup(*str))
			*str += 32;
		++str;
	}
	return (ptr);
}
