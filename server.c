#include "ft_printf/ft_printf.h"

void	getBits(int b)
{
	static int	c = 0;
	static int	count = 0;

	c += (b & 1) << count;
	count++;
	if (count == 7)
	{
		ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, getBits);
		signal(SIGUSR2, getBits);
		pause();
	}
	return (0);
}