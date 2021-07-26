NAME = push_swap


file_srcs = push_swap.c help_1.c operations_1.c operations_2.c operations_3.c sorting_algo_1.c


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
