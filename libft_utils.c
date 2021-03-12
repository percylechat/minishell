#include "minishell.h"

/*
**Useful functions from the libft. They may be modified to suit specific needs so beware.
*/

int     ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	to_find;
	int		i;

	i = 0;
	to_find = c;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*
**WARNING: no control beforehand for existence of str1 and str2
*/
char    *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    int len;
    char *ret;

    i = 0;
    j = 0;
    len = ft_strlen(str1) + ft_strlen(str2);
    if (!(ret = malloc(sizeof(char) * len + 1)))
        return (NULL);
    if (str1)
    {
        while (str1[i])
            ret[i] = str1[i++];
    }
    if (str2)
    {
        while (str2[j])
            ret[i++] = str2[j++];
    }
    ret[len] = '\0';
    return (ret);
}