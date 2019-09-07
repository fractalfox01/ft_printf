/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:09:59 by tvandivi          #+#    #+#             */
/*   Updated: 2019/09/05 21:56:39 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

# define FT_BLACK			"\033[0;30m"
# define FT_RED				"\033[0;31m"
# define FT_GREEN			"\033[0;32m"
# define FT_BROWN			"\033[0;33m"
# define FT_BLUE			"\033[0;34m"
# define FT_PURPLE			"\033[0;35m"
# define FT_CYAN			"\033[0;36m"
# define FT_LIGHTGRAY		"\033[0;37m"
# define FT_DARKGRAY    	"\033[1;30m"
# define FT_LIGHT_RED		"\033[1;31m"
# define FT_LIGHTGREEN		"\033[1;32m"
# define FT_YELLOW			"\033[1;33m"
# define FT_LIGHTBLUE		"\033[1;34m"
# define FT_LIGHTPURPLE		"\033[1;35m"
# define FT_LIGHTCYAN		"\033[1;36m"
# define FT_WHITE			"\033[1;37m"
# define FT_CLEAR_SCREEN	"\033[d"
# define FT_BOLD			"\033[1m"
# define FT_UNDERLINE		"\033[4m"
# define FT_END_ATTR		"\033[0m"

char					*ft_lftoa(long double flt, int afterpoint);
long long				ft_lltoo(long long nbr);
long long				ft_atoll(char *str);
char				    *ft_lltoa(long long n);
char					*ft_ftoa(long double flt, int afterpoint);
char					*ft_strrev(char *str);
int						ft_otoi(char *str);
char					*ft_itoo(int nbr);
int						ft_ltoo(long nbr);
char					*ft_ltoh(long n);
char	                *ft_lltoh(long long n);
char					*ft_itoh(unsigned int n);
char                    *ft_ustoh(unsigned short n);
char					*ft_ctoh(unsigned char n);
char					*ft_ltoa(long n);
char            		*ft_uctoa(unsigned char n);
char            		*ft_ustoa(unsigned short c);
char            		*ft_uitoa(unsigned int c);
char            		*ft_ultoa(unsigned long n);
char            		*ft_ulltoa(unsigned long long n);
int						ft_numlen(int i);
int						get_n_char(int fd, char **line, int size);
int						ft_hex_to_int(char *hex);
int						ft_abs(int nbr);
void					ft_putchar(long c);
void					ft_putstr(char *str);
void					ft_putnbr(int nb);
void					ft_bzero(void *s, size_t n);
long					ft_power(long n, int base);
size_t					ft_strlen(char *str);
int						ft_strnlen(char *str, size_t n);
int						ft_whitespace(int c);
int						ft_strxlen(const char *str, char c);
char					*ft_worditoa(char *ptr, long nbr, long len, long b);
char					*ft_strnew(size_t size);
char					*ft_strcpy(char *dest, char *src);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strdup(const char *s);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *h, const char *n, size_t ln);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strcat(char *dest, char *src);
char					*ft_itoa(int n);
int						ft_atoi(char *str);
int						ft_isascii(int nbr);
int						ft_isdigit(int c);
int						ft_toupper(int nb);
void					*ft_memset(void *s, int c, size_t n);
void                	*ft_memalloc(size_t size);
void                   	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void					ft_strdel(char **as);
char                	*ft_strncpy(char *dst, const char *src, size_t n);
int                     ft_isalpha(int c);

#endif
