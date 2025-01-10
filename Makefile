CC         = clang
NAME       = client
NAME_B     = server
SRCS_client = srcs/client.c
SRCS_server = srcs/server.c srcs/minitalk_utils.c
HEADER     = includes/minitalk.h
OBJ_DIR    = srcs/obj
OBJS_client = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS_client))
OBJS_server = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS_server))
CFLAGS     = -Wall -Wextra -Werror -Iincludes
LIBFT      = libft/libft.a
LDFLAGS    = $(LIBFT)

all: $(LIBFT) $(NAME) $(NAME_B)

########################################################################
#               Compilation de la libft                                #
########################################################################

$(LIBFT):
	@$(MAKE) -C libft > /dev/null

########################################################################
#               Règles pour les exécutables                            #
########################################################################

$(NAME): $(OBJS_client) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_client) $(LDFLAGS) -o $(NAME)
	@echo "[Makefile] \033[1;96mCompilation de $(NAME) terminée.\033[m"

$(NAME_B): $(OBJS_server) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_server) $(LDFLAGS) -o $(NAME_B)
	@echo "[Makefile] \033[1;96mCompilation de $(NAME_B) terminée.\033[m"

########################################################################
#               Compilation des .o dans srcs/obj/                      #
########################################################################

$(OBJ_DIR)/%.o: srcs/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[Makefile] \033[1;93mCompilation de $< -> $@\033[m"

########################################################################
#               Nettoyage                                              #
########################################################################

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[Makefile] \033[1;91mNettoyage des .o client/server.\033[m"
	@$(MAKE) clean -C libft > /dev/null

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@echo "[Makefile] \033[1;91mSuppression des exécutables et du dossier srcs/obj.\033[m"
	@$(MAKE) fclean -C libft > /dev/null

re: fclean all

########################################################################
#               Règles pratiques                                       #
########################################################################

run: all
	./$(NAME) $(ARGS)

runator:
	echo $(ARGS)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re run run2
