NAME = checker


file_srcs = checker.c


file_obj =  $(file_srcs:.c=.o)


all : $(NAME)


$(NAME) : $(file_obj)
		@gcc -Wall -Wextra -Werror $^ -o $@

%.o : %.c
		@gcc -Wextra -Werror -Wall -c $<

clean :
		@rm -f $(file_obj)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean
