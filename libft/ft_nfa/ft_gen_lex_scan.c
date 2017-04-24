#include "ft_lexer.h"

char	**s_scan(void)
{
	static char		*scan;

	return (&scan);
}

int		*s_offset(void)
{
	static int		offset;

	return (&offset);
}

void	ft_lex_start_scan(char *scan)
{
	*s_scan() = scan;
	*s_offset() = 0;
}
