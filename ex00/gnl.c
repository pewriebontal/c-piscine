/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:25:26 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/10 22:13:12 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//                   _oo0oo_
//                  o8888888o
//                  88" . "88
//                  (| -_- |)
//                  0\  =  /0
//                ___/`---'\___
//              .' \\|     |// '.
//             / \\|||  :  |||// |
//            / _||||| -:- |||||- |
//           |   | \\\  -  /// |   |
//           | \_|  ''\---/''  |_/ |
//           \  .-\__  '-'  ___/-. /
//         ___'. .'  /--.--\  `. .'___
//      ."" '<  `.___\_<|>_/___.' >' "".
//     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//     \  \ `_.   \_ __\ /__ _/   .-` /  /
// =====`-.____`.___ \_____/___.-`___.-'=====
//                   `=---='
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           佛祖保佑         永无BUG

#include "rush02.h"

char	*find_new_line(char **temp_box)
{
	char	*withline;
	char	*leftovers;
	int		len;

	len = 0;
	while ((*temp_box)[len] != '\n' && (*temp_box)[len] != '\0')
		len++;
	if ((*temp_box)[len] == '\n')
	{
		withline = ft_substr(*temp_box, 0, (len + 1));
		leftovers = ft_substr(*temp_box, (len + 1), ft_strlen(*temp_box));
		if (!withline || !leftovers)
		{
			free(withline);
			free(leftovers);
			return (NULL);
		}
		free(*temp_box);
		*temp_box = leftovers;
		return (withline);
	}
	return (NULL);
}

char	*do_read(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, GNL_BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*do_get_next_line(char **temp_box, int fd)
{
	char	*second_temp_box;
	char	*buffer;
	char	*processed_sentence;

	processed_sentence = find_new_line(temp_box);
	if (processed_sentence)
		return (processed_sentence);
	buffer = do_read(fd);
	if (!buffer)
	{
		if (*temp_box && **temp_box)
			processed_sentence = ft_strdup(*temp_box);
		else
			processed_sentence = NULL;
		free(*temp_box);
		*temp_box = NULL;
		return (processed_sentence);
	}
	second_temp_box = ft_strjoin(*temp_box, buffer);
	free(*temp_box);
	*temp_box = second_temp_box;
	free(buffer);
	return (do_get_next_line(temp_box, fd));
}

char	*get_next_line(int fd)
{
	static char	*temp_box[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || GNL_BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (fd >= 0 && fd < MAX_FD && temp_box[fd])
		{
			free(temp_box[fd]);
			temp_box[fd] = NULL;
		}
		return (NULL);
	}
	if (!temp_box[fd])
		temp_box[fd] = ft_strdup("");
	return (do_get_next_line(&temp_box[fd], fd));
}
