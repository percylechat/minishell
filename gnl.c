#include "minishell.h"

/*
**classic GNL to get input from user. WARNING: gets characters one by one, may be a bit slow!
*/

char    *line_cpy(char *str, char *line)
{
    int len;
    int i;

    len = ft_strlen(str);
    i = 0;
    if (!(line = malloc(sizeof(char) * len)))
        return (NULL);
    while (str[i])
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

int     get_next_line(char **line)
{
    char buf[2];
    static char *lo;
    int res;

    res = 1;
    if (!line)
        return (-1);
    while (res == 1 && buf[0] != '\n')
    {
        if((res = read(0, buf, 1)) == -1)
            return (-1);
        buf[1] = '\0';
        lo = ft_strjoin(lo, buf);
    }
    *line = line_cpy(lo, *line);
    free(lo);
    if (res == 1)
        return (1);
    else
        return (0);
}