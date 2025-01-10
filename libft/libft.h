/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:49:29 by mforest-          #+#    #+#             */
/*   Updated: 2025/01/07 22:14:04 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

typedef struct s_list
{
	char			*element;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_onepercent(void);
int					ft_printf(const char *str, ...);
size_t				ft_ptr(void *adress);
size_t				ft_putchar(const char c);
size_t				ft_putchar_fd(const char c, int fd);
size_t				ft_hex(unsigned int num, const char format);
size_t				ft_putnbr(const int n);
size_t				ft_putstr(const char *str);
size_t				ft_putunbr(const unsigned int n);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*concat(char *s1, char *s2, int len);
char				*get_contents_from_fd(int fd);
void				ft_perror(char *string);
char				*get_contents(const char *filename);
char				*ft_putnbr_base(int nbr, char *base);
void				ft_putnbr_bits(unsigned char c, unsigned char bits[8]);
char				*get_next_line(int fd);
void				ft_read(int fd, t_list **tmp);
void				add_to_tmp(t_list **tmp, char *buffer, int count);
void				extract_line(t_list *tmp, char **line);
void				clean(t_list **tmp);
int					ft_nl(t_list *tmp);
t_list				*get_last(t_list *tmp);
void				gen_line(char **line, t_list *tmp);
void				free_tmp(t_list *tmp);
size_t				ft_strlen(const char *s);
int					has_prefix(const char *filename, char *str);
int					has_suffix(const char *filename, char *str);
int					ft_strvlen(void **tab);
int					ft_count(const char *str, char c);
#endif
