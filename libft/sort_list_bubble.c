/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:54:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/04 20:25:53 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *sort_help1(char *tmp, t_list *first, t_list *second)
{
    int nd;

    nd = 0;
    tmp = ft_strnew(first->content_size);
    tmp = ft_strcat((char *)tmp, (char *)first->content);
    ft_memset(first->content, 0, first->content_size);
    ft_memdel((void **)&first->content);
    first->content = ft_strnew(second->content_size);
    first->content = ft_memcpy(first->content, second->content, second->content_size);
    ft_memset(second->content, 0, second->content_size);
    ft_memdel((void **)&second->content);
    second->content = ft_strnew(first->content_size);
    second->content = ft_memcpy(second->content, tmp, first->content_size);
    nd = first->content_size;
    first->content_size = second->content_size;
    second->content_size = nd;
    second = second->next;
    return (tmp);
}

char *sort_help2(char *tmp, t_list *first, t_list *second)
{
    int nd;

    nd = 0;
    tmp = ft_strnew(second->content_size);
    tmp = ft_strcat((char *)tmp, (char *)second->content);
    ft_memset(second->content, 0, second->content_size);
    ft_memdel((void **)&second->content);
    second->content = ft_strnew(first->content_size);
    second->content = ft_memcpy(second->content, first->content, second->content_size);
    ft_memset(first->content, 0, first->content_size);
    ft_memdel((void **)&first->content);
    first->content = ft_strnew(second->content_size);
    first->content = ft_memcpy(first->content, tmp, second->content_size);
    nd = second->content_size;
    second->content_size = first->content_size;
    first->content_size = nd;
    second = second->next;
    return (tmp);
}

t_list  *handler(t_list *head, int i, int j)
{
    t_list  *first;
    t_list  *second;
    int     len;

    if (head)
    {
        len = ft_lst_len(head);
        first = &*head;
        second = first->next;
        while (i++ < len && first)
        {
            while (j++ < (len - 1) && second)
            {
                if (ft_memcmp((char *)first->content, (char *)second->content, first->content_size) == 0)
                    second = second->next;
                else if (ft_memcmp(first->content, second->content, first->content_size) > 0)
                    sort_help1((char *)NULL, first, second);
                else if (ft_memcmp((char *)first->content, (char *)second->content, first->content_size) < 0)
                    sort_help2((char *)NULL, first, second);
            }
            first = first->next;
            j = i;
        }
        head = first;
    }
    return (head);
}

t_list  *sort_list_bubble(t_list *head)
{
    return (handler(head, 0, 0));
}
