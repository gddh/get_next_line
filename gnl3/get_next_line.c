/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 07:48:38 by delin             #+#    #+#             */
/*   Updated: 2018/05/10 11:28:25 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			readin(const int fd, char *buf)
{
	int bytes_read;

	if ((bytes_read = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	return (bytes_read);
}

char		*ft_realloc1(char *line, size_t new_size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * new_size)))
		return (NULL);
	if (ft_strcmp(line, "") != 0)
	{
		str = ft_strcpy(str, line);
		free(line);
	}
	else
		bzero(str, new_size);
	return (str);
}

int			process_buf(char **line, char *buf)
{
	*line = ft_realloc1(*line, ft_strlen(*line) + ft_strlen(buf) + 1);
	ft_strncat(*line, buf, ft_strlen(buf));
	ft_bzero(buf, BUFF_SIZE);
	return(1);
}

int			process_split(char **line, char *split_pt, char *buf)
{
	int bytes_left;

	*line = ft_realloc1(*line, ft_strlen(*line) + split_pt - buf + 1);
	ft_strncat(*line, buf, split_pt - buf);
	bytes_left = ft_strlen(buf) - (split_pt - buf) - 1;
	ft_memmove(buf, buf + (split_pt - buf) + 1, bytes_left);
	ft_bzero(buf + bytes_left, BUFF_SIZE - bytes_left);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	char		*split_pt;
	int			transferred;
	int			read_bytes;

	if (!line)
		return (-1);
	*line = "";
	transferred = 0;
	while (!ft_strchr(buf, '\n'))
	{
		if (!ft_strlen(buf) && !(read_bytes = readin(fd, buf)))
			return (transferred);
		if (read_bytes == -1)
			return (-1);
		if (!ft_strchr(buf, '\n'))
			transferred = process_buf(line, buf);
	}
	if ((split_pt = ft_strchr(buf, '\n')))
		transferred = process_split(line, split_pt, buf);
	return (transferred);
}

int		main(int argc, char **argv)
{
	int fd;
	char *str;
	int i;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &str))
		{
			printf("%d: len: %d, |%s|\n",i++,ft_strlen(str), str);
			free(str);
		}
		close(fd);
	}
	else
	{
		printf("type file name\n");
	}
}
