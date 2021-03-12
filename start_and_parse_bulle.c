#include "minishell.h"

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

// trouve la fonction qui correspond a la commande.
// Problemes : ici trouve le mot cle sans difference de s'il est intégré a une autre commande ou pas.
// exemple: echo "pwd" > file pourrait trouver echo en premier.
// need parsing plus precis en lettre par lettre

void    dispatch(char *str)
{
    if (search_word(str, "pwd") == 1)
        ft_pwd(str);
    else if (search_word(str, "echo") == 1)
        ft_echo(str);    
    else
        printf("nope");
}

// pour l'instant, ne prend qu'une commande. La commande doit etre enregistrée (pas fait), découpée (fait mais 
// rien n'est fait pour la suite de la commande) et envoyée a dispatch pour parsing.
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