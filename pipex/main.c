#include "libft/libft.h"
#include <string.h>
int main()
{
	char *wtv = "diogo";
	char *smt = "bea";
	while (strcmp(wtv, smt))
	{
		smt = get_next_line(0);
	}
}