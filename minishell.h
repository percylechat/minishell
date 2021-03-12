#ifndef MINISHELL_H

# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*
**Liste chainee for termcap
*/
typedef struct s_list t_list;
struct s_list{
    char *line;
    void *next;
    void *prec;
};

/*
**echo
*/
void    ft_echo_stdin(char *str, int option, int i);
void    ft_echo_doc(char *str, int option, int i);
void    ft_echo(char *str);

/*
**minishell_utils.c
*/
int check_word(char *str, char *to_find, int i);
int search_word(char *str, char *to_find);

/*
**GNL
*/
char    *line_cpy(char *str, char *line);
int     get_next_line(char **line);

/*
**libft_utils
*/
int     ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(char *str1, char *str2);

#endif