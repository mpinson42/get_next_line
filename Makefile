NAME = gnl

SRC = ./srcs/gnl.c

//FLAGS = -Wall -Wextra -Werror

SRC2 = 	gnl.o

all: $(NAME)

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc  -I ./include -L ./lib -lft $(FLAGS) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME) libft/libft.a
	@make -C ./libft fclean

re: fclean all