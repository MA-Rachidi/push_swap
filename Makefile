NAME = push_swap
NAME1 = checker

file_srcs = push_swap.c help_1.c help_2.c help_3.c help_4.c operations_1.c operations_2.c operations_3.c sorting_algo_1.c

file_obj =  $(file_srcs:.c=.o)

file_srcsbns = checker.c help_bonus.c help_bonus_2.c help_bonus_3.c libft.c operations_1.c operations_2.c operations_3.c

file_objbns =  $(file_srcsbns:.c=.o)

all : $(NAME)


$(NAME) : $(file_obj)
		@gcc -Wall -Wextra -Werror $^ -o $@

%.o : %.c
		@gcc -Wextra -Werror -Wall -c $<

clean :
		@rm -f $(file_obj)
		@rm -f $(file_objbns)

fclean : clean
		@rm -f $(NAME)
		@rm -f $(NAME1)

re : fclean all

bonus: $(NAME1)

$(NAME1) : $(file_objbns)
		@gcc -Wall -Wextra -Werror $^ -o $(NAME1)

%bns.o : %bns.c
		@gcc -Wall -Wextra -Werror -c $<	

.PHONY : all re clean fclean bonus
