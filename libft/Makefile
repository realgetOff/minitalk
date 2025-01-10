CC      = clang
NAME    = libft.a
OBJ_DIR = obj
SRCS    = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
          ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
          ft_memmove.c ft_memset.c ft_onepercent.c ft_printf.c ft_ptr.c ft_putchar.c \
          ft_putchar_fd.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunbr.c ft_split.c \
          ft_strlen.c ft_strvlen.c get_contents.c get_next_line.c get_next_line_utils.c \
          has_prefix.c has_suffix.c ft_count.c ft_putnbr_base.c ft_putnbr_bits.c ft_perror.c
HEADER  = libft.h
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CFLAGS  = -Wall -Wextra -Werror
all: $(NAME)

########################################################################
#               Création de la bibliothèque                            #
########################################################################
$(NAME): $(OBJS)
	@echo "\033[1;96mCréation de $(NAME)...\033[m"
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[1;92m$(NAME) a été créé avec succès !\033[m"

########################################################################
#               Compilation des fichiers .o                            #
########################################################################
$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;93mCompilation de $< -> $@\033[m"

########################################################################
#               Nettoyage                                              #
########################################################################
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;91mSuppression des fichiers objets.\033[m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;91mSuppression de $(NAME).\033[m"

########################################################################
#               Recompilation complète                                 #
########################################################################
re: fclean all
	@echo "\033[1;96mRecompilation complète terminée.\033[m"

.PHONY: all clean fclean re

