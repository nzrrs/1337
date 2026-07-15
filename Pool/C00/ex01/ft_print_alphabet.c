#include <unistd.h>

void ft_print_alphabet(void)
{
	int	i;

	i = 97;
	while ( i <= 'z' ){
		write (1, &i, 1);
		i++;
	}
}
