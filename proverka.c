#include <unistd.h>

void main(void)
{
    static int	i;
	static char	buf[8];

	if (buf == NULL)
	{
		i = 0;
	}
    buf[0] += '1';
    buf[1] += '0';
    printf("%s\n", buf);
}