#ifndef PIPEX_H
#define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <errno.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	countwords(char *s, char c);

#endif