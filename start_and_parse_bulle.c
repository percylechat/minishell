#include "minishell.h"

typedef struct s_list t_list;
struct s_list{
    char *line;
    void *next;
    void *prec;
}

int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (i);
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    char *ret;

    // if (!&str1 && !str2)
        // return (NULL);
    int len = ft_strlen(str1) + ft_strlen(str2);
    if (!(ret = malloc(sizeof(char) * len + 1)))
        return (NULL);
    if (str1)
    {
        while (str1[i])
        {
            ret[i] = str1[i];
            i++;
        }
    }
    if (str2)
    {
        while (str2[j])
        {
            ret[i] = str2[j];
            i++;
            j++;
        }
    }
    ret[len] = '\0';
    return (ret);
}

char *line_cpy(char *str, char *line)
{
    int len = ft_strlen(str);

    if (!(line = malloc(sizeof(char) * len)))
        return (NULL);
    int i = 0;
    while (str[i])
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

int get_next_line(char **line)
{
    char buf[2];
    static char *lo;
    int res;

    if (!line)
        return (-1);
    res = 1;
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

int check_word(char *str, char *to_find, int i)
{
    int j;

    j = 0;
    while (to_find[j])
    {
        if (str[i + j] == to_find[j])
            j++;
        else
            return (0);
    }
    return (1);
}

int search_word(char *str, char *to_find)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == to_find[0])
        {
            if (check_word(str, to_find, i) == 1)
                return (1);
        }
        i++;
    }
    return (0);
}

char *getcommand(char *str)
{
    int i;
    int j;
    char *ret;

    i = 0;
    j = 0;
    while (str[i] != '|' && str[i] != ';' && str[i] != ':')
        i++;
    if (i == 0)
        return (NULL);
    if (!(ret = malloc(sizeof(char) * i + 1)))
        return (NULL);
    while(j < i)
        ret[j] = str[j++];
    ret[j] = '\0';
    return (ret);
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

void    redir_file(char *str, char *output)
{

}

void    check_redir(char *command, char *output)
{
    char *ret;

    if ((ret = strchr(str, '<')) != NULL)
        redir_ext(command, output);
    else if ((ret = strchr(str, '>')) != NULL)
    {
        if (ret++ == '>')
            redir_EOF(command, output);
        redir_file(command, output);
    }
}

void    ft_pwd(char *str)
{
    char *path;

    // path = NULL;
    // getcwd(path, 0);
    // version linux: oath alloué par appel de commande via malloc si size est 0 et buff null. Need free apres
    
    if (!(path = malloc(sizeof(char) * 1000)))
        return ;
    getcwd(path, 1000);
    check_redir(str, path);
    // printf("%s", path);
    free(path);
}

void    ft_echo_stdin(char *str, int option, int i)
{
    // add difference single double quote
    i++;
    while (str[i] != '\'' && str[i] != '\"')
    {
        write(1, &str[i], 1);
        i++;
    }
    if (option == 0)
        write(1, "\n", 1);
    // check if EOF print
    write(1, "\0", 1);
}

void    ft_echo_doc(char *str, int option, int i)
{
    write(1, "here", 4);
    return;
}

void    ft_echo(char *str)
{
    // tester linux echo sans guillements
    int option;
    int i;

    i = 0;
    option = search_word(str, "-n");
    while (str[i])
    {
        if (str[i] == '<' || str[i] == '>')
        {
            ft_echo_doc(str, option, i);
            return ;
        }
        else if (str[i] == '\"' || str[i] == '\'')
        {
            ft_echo_stdin(str, option, i);
            return ;
        }
        i++;
    }
}

void    dispatch(char *str)
{
    if (search_word(str, "pwd") == 1)
        ft_pwd(str);
    else if (search_word(str, "echo") == 1)
        ft_echo(str);    
    else
        printf("nope");
}

int main(void)
{
    char *line;
    int end;
    int res;
    char *command;

    end = 0;
    while (end == 0)
    {
        res = get_next_line(&line);
        printf("test:%s", line);
        // while ((command = getcommand(line)) != NULL)
        // {
            command = getcommand(line);
            dispatch(command);
        // }
        end = 1;
    }
}