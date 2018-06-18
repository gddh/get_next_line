#include "get_next_line.h"

char	*ft_realloc1(char **ptr, size_t old_size, size_t new_size)
{
	char *tmp;

	if (new_size == 0)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if ((tmp = ft_strnew(sizeof(char) * new_size)))
	{
		if (*ptr)
		{
			if (old_size < new_size)
				ft_memcpy(tmp, *ptr, old_size);
			else
				ft_memcpy(tmp, *ptr, new_size);
			free(*ptr);
		}
		*ptr = tmp;
		return (tmp);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	char		*split_point;
	int			bytes_left;
	int			cont;
	int			valid_bytes;
	int			transfer;

	cont = 2;
	if(!line)
		return (-1);
	*line = NULL;
	transfer = 0;
	while (cont != 1 && cont != 0)
	{
		if ((bytes_left = ft_strlen(buf)) == 0)
		{
			if ((bytes_left = read(fd, buf, BUFF_SIZE)) < 0)
			{
				return (-1);
			}
			if (bytes_left == 0 && !transfer)
			{
				return (0);
			}
			if (bytes_left == 0)
				return(1);
			buf[bytes_left] = '\0';
			if (bytes_left < BUFF_SIZE)
				cont = 1;
		}
		split_point = ft_memchr(buf, '\n', bytes_left);
		if (split_point && cont)
		{
			valid_bytes = split_point - buf;
			cont = 1;
		}
		else
		{
			valid_bytes = bytes_left;
		}
		ft_realloc1(line, ft_strlen(*line), ft_strlen(*line) + valid_bytes + 1);
		ft_strncat(*line, buf, valid_bytes);
		transfer = 1;
		if (split_point && bytes_left - valid_bytes - 1)
		{
			ft_memmove(buf, buf + valid_bytes + 1, bytes_left - valid_bytes - 1);
			buf[bytes_left - valid_bytes - 1] = '\0';
		}
		else
		{
			bzero(buf, BUFF_SIZE);
		}
	}
	return (cont);
}

//int		main(int argc, char **argv)
//{
//	int fd;
//	char *str;
//	int i;
//	
//	get_next_line(-99, NULL);
//	if (argc > 1)
//	{
//		while (--argc > 0)
//		{
//			str = NULL;
//			fd = fileno(fopen(argv[argc], "r"));
//			while ((i = get_next_line(fd, &str)))
//			{
//				printf("----------ITERATION START -----------\n");
//				printf("|%s| %d\n", str, i);
//				free(str);
//				str = NULL;
//				printf("----------ITERATION END ------------\n");
//			}
//			close(fd);
//		}
//	}
//}
