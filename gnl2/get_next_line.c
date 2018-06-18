/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 07:20:29 by delin             #+#    #+#             */
/*   Updated: 2018/05/05 09:47:30 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		transfer_buf(char **line, char *buf, int valid_bytes)
{
	int old_size;

	if (!*line)
	{
		if ((*line = (char *)ft_memalloc(sizeof(char) * valid_bytes + 1)))
			ft_strncat(*line, buf, valid_bytes);
	}
	else
	{
		old_size = ft_strlen(*line);
		ft_realloc((void **)line, old_size, old_size + valid_bytes + 1);
		ft_strncat(*line, buf, valid_bytes);
	}
	return (1);
}

int		process_buffer(char *buf, int bytes_left, char **line, int *transferred)
{
	char		*split_pt;
	int			found_nl;

	split_pt = ft_memchr(buf, '\n', bytes_left); /* Either find a split point or no split point. */
	found_nl = 0;
	if (split_pt)
		found_nl = 1;
	if (!split_pt && bytes_left) 	/* If no split point, buffer is emptied into the line */
	{
		*transferred = transfer_buf(line, buf, bytes_left); 
		ft_bzero(buf, BUFF_SIZE);
	}
	else if (bytes_left) /* If split point, move elements from buf to line and shift buf */
	{
		*transferred = transfer_buf(line, buf, split_pt - buf);
		ft_memmove(buf, split_pt + 1, bytes_left - (split_pt - buf + 1));
		buf[bytes_left - (split_pt - buf + 1)] = '\0';
	}
	return (found_nl);
}

int		get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE];
	int			eof;
	int			bytes_left;
	int			transferred;
	int			found_nl;

	if (!line)
		return (-1);
	*line = NULL;
	eof = 0;
	found_nl = 0;
	transferred = 0;
	while (!eof && !found_nl) /* while not end of file and have not found a next line */
	{	
		if ((bytes_left = ft_strlen(buf)) == 0) /* If the buffer is empty, then we need to read */
		{
			if ((bytes_left = read(fd, buf, BUFF_SIZE)) < 0)
				return (-1);
			if (bytes_left == 0)
				eof = 1;
		}
		found_nl = process_buffer(buf, bytes_left, line, &transferred);
	}
	return (transferred);
}

//int		main(int argc, char **argv)
//{
//	int fd;
//	char *str;
//	int i;
//
//	if (argc > 1)
//	{
//		while (--argc > 0)
//		{
//			str = NULL;
//			fd = open(argv[argc], O_RDONLY);
//			while ((i = get_next_line(fd, &str)))
//			{
//				printf("----------ITERATION START -----------\n");
//				printf("|%s| %d\n", str, i);
//				free(str);
//				printf("----------ITERATION END ------------\n");
//			}
//			close(fd);
//		}
//	}
//}
