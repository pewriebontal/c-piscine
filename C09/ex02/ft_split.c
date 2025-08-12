/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:14:43 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/12 17:36:19 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_separator(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset))
			str++;
		count++;
		while (*str != '\0' && !check_separator(*str, charset))
			str++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !check_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		i;
	int		len_word;
	char	*word;

	i = 0;
	len_word = ft_strlen(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**string;

	i = 0;
	string = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, charset))
			str++;
		if (*str != '\0')
		{
			string[i] = ft_word(str, charset);
			i++;
		}
		while (*str != '\0' && !check_separator(*str, charset))
			str++;
	}
	string[i] = 0;
	return (string);
}
