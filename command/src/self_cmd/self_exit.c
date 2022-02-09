/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:33 by tkirihar          #+#    #+#             */
/*   Updated: 2022/02/09 14:35:31 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

void	exec_self_exit(t_exec_attr *ea)
{
	(void)ea;
	exit(0);
}