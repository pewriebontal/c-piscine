/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:04:21 by mkhaing           #+#    #+#             */
/*   Updated: 2023/09/20 16:04:21 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while ((*s1 || *s2) && i < n)
		{
			if (*s1 != *s2)
				return (*s1 - *s2);
			s1++;
			s2++;
			i++;
		}
		if (i == n)
			return (0);
		else
			return (*s1 - *s2);
	}
	else
		return (0);
}
