/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curreg <curreg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:17:29 by curreg            #+#    #+#             */
/*   Updated: 2020/10/31 23:37:24 by curreg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_list_size(t_list *lst);
int					ft_list_push_front(t_list **begin_list, void *data);

#endif
