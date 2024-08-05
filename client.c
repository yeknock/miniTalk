#include "ft_printf/ft_printf.h"
#include <signal.h>

void	passBits(int pid, char *str)
{
	int	shift;
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("wrong amount of arguments\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	passBits(pid, argv[2]);
	return (0);
}