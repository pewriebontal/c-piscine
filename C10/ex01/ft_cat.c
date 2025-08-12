/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:26:17 by mikhaing          #+#    #+#             */
/*   Updated: 2025/08/12 18:10:52 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void ft_stdin(void)
{
	char	buffer;

	while (read(0, &buffer, 1) > 0)
		write(1, &buffer, 1);
}

int	main(int argc, char **argv)
{
	char	buffer;
	int		fd;

	if (argc == 1)
		ft_stdin();
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 19);
		while (read(fd, &buffer, 1) > 0)
			write(1, &buffer, 1);
	}
	else
		write(1, "Too many arguments.\n", 20);
	close(fd);
}
