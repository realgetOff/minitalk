/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:13:18 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/10 21:13:20 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*****************************************************************************/
/*                               > INCLUDES <                                */
/*****************************************************************************/

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

/*****************************************************************************/
/*                            > STRUCTURES <                                 */
/*****************************************************************************/

/**
 * @struct s_server
 * Stocke les informations du serveur lors de la réception des signaux.
 */
typedef struct s_server
{
	pid_t			client_pid;		/**< PID du client envoyant les données */
	pid_t			server_pid;		/**< PID du serveur (processus actuel) */
	char			*string;		/**< Chaîne en cours de reconstruction */
	size_t			allocated_size;	/**< Taille allouée de 'string' */
	size_t			string_i;		/**< Indice d'écriture dans 'string' */
	int				number;			/**< Variable utilisée pour le decrypt */
	unsigned char	bits[9];	/**< Buffer de stockage pour les bits */
}				t_server;

/**
 * @var g_server
 * Variable globale du serveur permettant de gérer la réception des signaux.
 */
extern t_server	g_server;

/*****************************************************************************/
/*                        > FONCTIONS DU SERVEUR <                           */
/*****************************************************************************/

/**
 * @brief Initialise la chaîne de réception du serveur.
 */
void			init_server_string(void);

/**
 * @brief Agrandit dynamiquement la mémoire de la chaîne de réception.
 */
void			expand_server_string(void);

/**
 * @brief Extrait un caractère à partir d'un buffer de bits.
 * @param buffer Tableau contenant 8 bits + '\0'
 * @return Le caractère correspondant aux bits reçus.
 */
char			get_bit(unsigned char buffer[9]);

/**
 * @brief Décode les bits reçus et affiche le message complet.
 */
void			decode_and_print(void);

/**

* @brief Gère la réception des signaux SIGUSR1/2 pour reconstituer les bits.
 * @param signum Le signal reçu (SIGUSR1 ou SIGUSR2)
 * @param info Informations sur le signal et l'expéditeur
 * @param context Contexte d'exécution (non utilisé)
 */
void			receive_bits(int signum, siginfo_t *info, void *context);

/*****************************************************************************/
/*                        > FONCTIONS DU CLIENT <                            */
/*****************************************************************************/

/**
 * @brief Gère la réception d'un accusé de réception du serveur.
 * @param signum Le signal reçu (utilisé pour synchronisation)
 */
void			handle_ack(int signum);

/**
 * @brief Envoie un bit unique au serveur sous forme de signal.
 * @param pid PID du serveur
 * @param bits Tableau de 8 bits représentant le caractère
 * @return 0 si succès, 1 en cas d'erreur.
 */
int				sent_bits(pid_t pid, unsigned char *bits);

/**
 * @brief Convertit une chaîne en signaux et les envoie au serveur.
 * @param pid PID du serveur
 * @param str Chaîne à envoyer
 * @return 0 si succès, 1 en cas d'erreur.
 */
int				encrypt(pid_t pid, char *str);

#endif
