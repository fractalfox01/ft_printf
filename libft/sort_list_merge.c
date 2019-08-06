/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:48:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/08/04 20:27:27 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstxlen(t_list *lst, int i)
{
    int l;
    int a;

    a = 0;
    l = ft_lst_len(lst);
    while (i < l)
    {
        a++;
        i++;
    }
    return (a);
}

t_list	*int_merge_sort_list(t_list *lst, int l, int r, int (*cmp)(int, int))
{
    int mid;

    l = 0;
    r = ft_lstxlen(lst, r);
    mid = ((r % 2) == 0) ? (r / 2) : ((r / 2) + 1);
    if (l < r)
        int_merge_sort_list(lst, l, r, cmp);
    return (lst);
}
