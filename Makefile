NAME = pipex
BNAME = pipexb
LIBRARY = pipex.h
CFLAGS= -Wall -Wextra -Werror
CC = cc

RED     =   \033[38;5;161m
GREEN   =   \033[38;5;154m
YELLOW  =   \033[38;5;227m
BLUE	=   \033[38;5;81m
PURPLE  =   \033[38;5;93m
PINK	=	\033[38;5;219m
NC      =   \033[0m

SRC = pipex.c parseargs.c err_handling.c

all: makelib $(NAME)

$(NAME): $(LIBRARY) Makefile $(SRC) libft/libft.a
	@$(CC) $(CFLAGS) $(SRC) -L./libft -lft -L./printf -lftprintf -o $(NAME) #-fsanitize="address,undefined" -g
	@printf "${PURPLE}== PIPEX COMPILED SUCCESSFULLY ==\n${NC}"

makelib:
	@$(MAKE) -C ./libft bonus --no-print-directory -silent
	@printf "${GREEN}Libft ok👍\n${NC}"
	@$(MAKE) -C ./printf all --no-print-directory -silent
	@printf "${GREEN}Printf ok👍\n${NC}"

clean:
	@$(MAKE) -C ./libft clean --no-print-directory -silent

fclean: clean
	@printf "${RED}....EXTERMINATING....\n${NC}"
	@$(MAKE) -C ./libft fclean --no-print-directory -silent
	@sleep 0.5
	@printf "${PINK}🧨\tLIBFT\n${NC}"
	@$(MAKE) -C ./printf fclean --no-print-directory -silent
	@sleep 0.5
	@printf "${PINK}🧨\tPRINTF\n${NC}"
	@rm -f $(NAME)
	@sleep 0.5
	@printf "${PINK}🧨\tPIPEX\n${NC}"
	@sleep 0.5
	@printf "${RED}.......DONE.......\n${NC}"

re: fclean all

.PHONY: all clean fclean re