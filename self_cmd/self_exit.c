/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:07:33 by tkirihar          #+#    #+#             */
/*   Updated: 2022/03/03 22:56:51 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "self_cmd.h"
#include "common.h"

bool	is_num(char *str)
{
	size_t	i;

	if (!(str[0] == '+' || str[0] == '-' || ft_isdigit(str[0])))
		return (false);
	if ((str[0] == '+' || str[0] == '-') && ft_strlen(str) == 1)
		return (false);
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	exit_failure(unsigned int exit_status, char *error_message)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(exit_status);
}

char	*make_arg_error_message(char *arg, char *error)
{
	char	*error_message;
	char	*tmp_str;
	char	*tmp_arg;

	if (arg == NULL || error == NULL)
		exit (EXIT_FAILURE);
	tmp_arg = ft_strjoin(arg, ": ");
	if (tmp_arg == NULL)
		exit(EXIT_FAILURE);
	tmp_str = ft_strjoin("bash: exit: ", tmp_arg);
	if (tmp_str == NULL)
		exit(EXIT_FAILURE);
	free(tmp_arg);
	error_message = ft_strjoin(tmp_str, error);
	if (error_message == NULL)
	{
		exit(EXIT_FAILURE);
	}
	free(tmp_str);
	return (error_message);
}

char	*make_dfl_error_message(char *error)
{
	char	*error_message;

	if (error == NULL)
		exit(EXIT_FAILURE);
	error_message = ft_strjoin("bash: exit: ", error);
	if (error_message == NULL)
		exit(EXIT_FAILURE);
	return (error_message);
}

char	*get_arg1(t_cmd *cmd)
{
	char	*arg1;
	t_list	*arg1_lst;

	arg1_lst = cmd->args->next;
	if (arg1_lst == NULL)
		return (cmd->args->content);
	arg1 = arg1_lst->content;
	return (ft_strtrim(arg1, " "));
}

int	exec_self_exit(t_cmd *cmd, t_exec_attr *ea)
{
	unsigned int	exit_status;
	int				argc;
	char			*arg1;
	long			arg1_num;
	char			*error_message;

	(void)ea;
	ft_putendl_fd("exit", STDERR_FILENO);
	argc = ft_lstsize(cmd->args);
	if (argc == 1)
		exit(g_exit_status);
	arg1 = get_arg1(cmd);
	if (arg1 == NULL)
		exit(EXIT_FAILURE);
	if (!is_num(arg1) || !ft_atol(arg1, &arg1_num))
	{
		ft_put_arg_error("exit", arg1, "numeric argument required");
		free(arg1);
		exit(255);
	}
	free(arg1);
	if (argc > 2)
	{
		error_message = make_dfl_error_message("too many arguments");
		ft_putendl_fd("exit", STDERR_FILENO);
		ft_putendl_fd(error_message, STDERR_FILENO);
		return (1);
	}
	exit_status = arg1_num;
	if (exit_status > 255)
		exit(exit_status % 256);
	else
		exit(exit_status);
	return (exit_status);
}
