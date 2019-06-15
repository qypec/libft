# include "ft_hashtab.h"
# include <unistd.h>

int						checker(void)
{
	write(1, "blalba\n", 6);
	return (1);
}

int						main()
{
	ht_list		**htab;

	htab = ft_htabnew((void*)1, &ft_hashfunc);
	ft_htabadd(htab, "cd", "2");
	ft_htabadd(htab, "asaffaf", "2");
	ft_htabadd(htab, "", "2");
	ft_htabadd(htab, "       ", "2");
	ft_htabadd(htab, "setenv", "2");
	ft_htabadd(htab, "unsetenv", "2");
	ft_htabadd(htab, "echo afaffa", "2");
	ft_htabadd(htab, "ls -la", "2");
	ft_htabadd(htab, "pwd", "2");
	ft_puthtab(htab);
	ft_htabdelone(htab, "unsetenv");
	ft_puthtab(htab);
	ft_htabadd(htab, "unsetenv", "2");
	ft_puthtab(htab);
	ft_htabdelone(htab, "       ");
	ft_puthtab(htab);
	ft_htabadd(htab, "       ", "2");
	ft_puthtab(htab);
	ft_htabdelone(htab, "       ");
	ft_puthtab(htab);
	ft_htabdelone(htab, "pwd");
	ft_puthtab(htab);
	ft_htabadd(htab, "pwd", "2");
	ft_puthtab(htab);
	// ft_htabfree(&htab);
	free(htab);
}