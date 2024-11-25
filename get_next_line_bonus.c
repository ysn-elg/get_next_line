/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-guad <yel-guad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:05:13 by yel-guad          #+#    #+#             */
/*   Updated: 2024/11/23 12:15:58 by yel-guad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_linee(int fd, char *res)
{
	char	*buff;
	char	*tmp;
	int		i;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(buff), NULL);
		if (i == 0)
			break ;
		buff[i] = '\0';
		tmp = res;
		res = ft_strjoin(res, buff);
		if (!res)
			return (free(buff), NULL);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_the_line(char *buff)
{
	char	*res;
	size_t	i;

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

char	*get_rest(char *buff)
{
	char	*res;
	size_t	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (NULL);
	res = ft_strdup(buff + i + 1);
	if (!res)
		return (NULL);
	if (!*res)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buff[fd] = get_linee(fd, buff[fd]);
	if (!buff[fd])
		return (free(buff[fd]), NULL);
	line = get_the_line(buff[fd]);
	tmp = buff[fd];
	buff[fd] = get_rest(buff[fd]);
	free(tmp);
	return (line);
}
