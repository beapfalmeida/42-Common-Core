#include "get_next_line.h"

int	ft_strclen(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
char	*ft_strdup(char *src, int size)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	while (src && src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	tlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tlen = ft_strclen((char *)s1, '\0') + ft_strclen((char *)s2, '\0');
	new = malloc((tlen + 1) * sizeof(char));
	if (!new)
		return (0);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
