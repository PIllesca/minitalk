/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:38:03 by pillesca          #+#    #+#             */
/*   Updated: 2024/10/02 19:44:28 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * Función que imprime mensaje de uso y el PID del servidor
 */
static void	ft_print_pid(int pid)
{
	ft_putstr("Usage: ./client [PID] [Message]\nServer PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
}

/**
 * Función que imprime un mensaje de confirmación de recepción de mensaje y
 * envía una señal de confirmación al cliente
 * 
 * @param[in] pid PID del cliente
 * @return 0
 */
static int	ft_print_respond(int pid)
{
	ft_putstr("\nMessage received from PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	kill(pid, SIGUSR1);
	return (0);
}

/**
 * Función que recibe caracteres de un cliente usando señales
 * para enviar un mensaje bit a bit, lo decodifica y lo imprime
 * 
 * @param[in] signum Número de la señal
 * @param[in] info Información de la señal
 * @param[in] context Contexto de la señal
 */
static void	ft_receive_sig(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static unsigned long	i = 0;
	static pid_t			pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
			pid = ft_print_respond(pid);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

/**
 * Función principal
 * Imprime el PID del servidor y espera señales de los clientes
 * 
 * @return EXIT_SUCCESS
 */
int	main(void)
{
	int					pid;
	struct sigaction	s_sa;

	pid = getpid();
	ft_print_pid(pid);
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = ft_receive_sig;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	while (1)
	{
		pause();
	}
	exit(EXIT_SUCCESS);
}
