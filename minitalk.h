/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:26 by pillesca          #+#    #+#             */
/*   Updated: 2024/10/02 18:05:50 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 199309L
# define _XOPEN_SOURCE 500
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_error_exit(char *s);

#endif