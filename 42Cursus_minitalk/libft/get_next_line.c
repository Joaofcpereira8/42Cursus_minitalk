/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:43:50 by jofilipe          #+#    #+#             */
/*   Updated: 2023/02/15 13:21:09 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_next_line(char *str, int fd)
{
	char	*content_read;
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	content_read = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while ((bytes_read != 0) && !ft_strchr(content_read, '\n'))
	{
		bytes_read = read(fd, content_read, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (str)
				free (str);
			free (content_read);
			return (NULL);
		}
		content_read[bytes_read] = '\0';
		temp = ft_strjoin(str, content_read);
		free (str);
		str = temp;
	}
	free (content_read);
	return (str);
}

static char	*ft_clear_next_line(char *str)
{
	int		i;
	char	*linha;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	linha = ft_calloc(sizeof(char), (i + 1 + 1));
	if (!linha)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		linha[i] = str[i];
		i++;
	}
	linha[i] = str[i];
	i++;
	linha[i] = '\0';
	return (linha);
}

static char	*ft_get_the_next_line(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	temp = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	if (!temp)
		return (NULL);
	i++;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	free (str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*str[MAX_FILES];
	char			*linha;

	if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE < 1)
		return (NULL);
	str[fd] = ft_read_next_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	linha = ft_clear_next_line (str[fd]);
	str[fd] = ft_get_the_next_line (str[fd]);
	return (linha);
}

/* int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("sample.txt", O_RDONLY);
	fd3 = open("sample1.txt", O_RDONLY);
	i = 1;
	while (i <= 15)
	{
		printf("%d\n", fd1);
		str1 = get_next_line(fd1);
		printf("[%d]: %s", i, str1);
		free(str1);
		printf("%d\n", fd2);
		str2 = get_next_line(fd2);
		printf("[%d]: %s", i, str2);
		free(str2);
		printf("%d\n", fd3);
		str3 = get_next_line(fd3);
		printf("[%d]: %s", i, str3);
		free(str3);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
