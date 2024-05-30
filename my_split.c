/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camurill <camurill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:22:20 by camurill          #+#    #+#             */
/*   Updated: 2024/05/30 15:58:52 by camurill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char const *s, char c)
{
	int	inter;
	int	count;

	inter = 0;
	count = 0;
	if (s[0] != c && s[0])
	{
		count++;
		inter++;
	}
	while (s[inter])
	{
		while (s[inter] == c && s[inter + 1])
			inter++;
		if (s[inter] != c && s[inter - 1] && s[inter])
			count++;
		inter++;
	}
	return (count);
}

static char	**my_free(char **s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char *my_dupchar(char const *s, char c, int *pos)
{
	int		i;
	int 	len;
	char	*dup;

	i = 0;
	len  = 0;
	while (*s == c)
	{
		s++;
		(*pos)++;
	}
	while(s[len] && s[len] != c)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = *s;
		i++;
		s++;
	}
	dup[i] = '\0';
	*pos += i;
	return (dup);
}

char	**ft_mysplit(char const *s, char c)
{
	int 	word_count;
	char	**split;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	word_count = ft_count_word(s, c);
	split = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!split)
		return (NULL);
	split[i++] = ft_strdup("./push_swap");
	while (i < word_count + 1)
	{
		split[i] = my_dupchar(s + pos, c, &pos);
		if (!split)
			return (my_free(split, i));
		i++;
	}
	split[i] =  NULL;
	return(split);
}

/*
int main(void)
{
	char const *p = "hello!    222";
	char t = ' ';
	int i = 0;
	char **split;
	split = ft_mysplit(p, t);
	printf("%s", split[1]);
	i++;
	return (0);
}*/