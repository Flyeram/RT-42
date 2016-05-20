#include <libft.h>
#include <get_next_line.h>

int main(int ac, char **av)
{
	(void)ac;
	char *line;
	int fd = open (av[1], O_RDONLY);

	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free (line);
	}
	return (0);
}
