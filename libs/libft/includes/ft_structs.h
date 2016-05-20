#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

#include "libft.h"

struct		s_array
{
	void	*array;
	size_t	element_size;
	size_t	bytes_size;
	size_t	count;
};

struct		s_filebuffer
{
	int	fd;
	size_t	stock;
	char	*buffer;
};

#endif
