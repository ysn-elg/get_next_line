/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:05:13 by yel-guad          #+#    #+#             */
/*   Updated: 2024/11/21 11:05:15 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_line(int fd, char *res)
{
    char    *buff;
    char    *tmp;
    int     i;

    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (1)
    {
        i = read(fd, buff, BUFFER_SIZE);
        if (i == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[i] = '\0';
        tmp = res;
        res = ft_strjoin(res, buff);
        free(tmp);
        if (ft_strchr(buff, '\n'))
            break ;
    }
    free(buff);
    return (res);
}

char    *get_res_line(char *buff)
{
    char    *res;
    size_t     i;

    i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    if (buff[i] == '\n')
        i++;
    res = ft_substr(buff, 0, i);
    if (!res)
        return (NULL);
    return (res);
}

char    *get_rest(char *buff)
{
    char    *res;
    size_t     i;

    i = 0;
    while (buff[i] && buff[i] != '\n')
        i++;
    if (!buff[i])
        return (NULL);
    res = ft_substr(buff, i + 1, ft_strlen(buff) - i - 1);//qwerty\n\niiio
    if (!res)
        return (NULL);
    return (res);
}

char	*get_next_line(int fd)
{
    static char *buff;
    char        *line;
    char        *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buff = get_line(fd, buff);
    if (!buff)
        return (NULL);
    line = get_res_line(buff);
    if (!line)
        return (NULL);
    tmp = buff;
    buff = get_rest(buff);
    free(tmp);
    return (line);
}
#include <fcntl.h>
#include <stdio.h>

int main ()
{   
    int fd;
    int i = 0;
    fd = open("text.txt", O_RDONLY);
    while (i < 5)
        printf("line %d ->%s|", ++i, get_next_line(fd));
    return 0;
}