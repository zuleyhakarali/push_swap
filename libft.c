/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:19:45 by zkarali           #+#    #+#             */
/*   Updated: 2025/10/18 18:37:50 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *nptr)
{
	long	i;
	long	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*alloc_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = word_len(s, c);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **result, int i)
{
	while (i--)
		free(result[i]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = alloc_word(s, c);
			if (!result[i])
				return (free_all(result, i), NULL);
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

t_list *ft_lstnew(long content)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

void ft_lstclear(t_list **lst)
{
    t_list *last;
    if ((lst == NULL) || (*lst == NULL))
        return ;
    last = *lst;
    while (*lst)
    {
        last = (*lst)->next;
        free(*lst);
        *lst = last;
    }
    *lst = NULL;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;

    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = *lst;
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (new == NULL)
        return ;
    new->next = *lst;
    *lst = new;
}

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}