#ifndef GNL_C
# define GNL_C

# define BUFF_SIZE 1
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
