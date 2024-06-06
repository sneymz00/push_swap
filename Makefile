###############################################################################
#				STANDARS				      #
###############################################################################
NAME 		= 		push_swap
RM 			= 		rm -rf
LIBFT		=		libreries/libft/libft.a
OBJS		= 		obj/

###############################################################################
#				COMPILER				      #
###############################################################################

CC 		= 		gcc -g
CCFLAGS	= 		-Wall -Wextra -Werror 

###############################################################################
#				SRC					      #
###############################################################################

SRC 	= 	main.c init_node.c aux_stacks.c\
			init_stacks.c my_error.c mains_stack.c my_split.c\
			push.c reverse_rotate.c rotates.c swap.c utils_stacks.c

###############################################################################
#				SRC BONUS	   	     		      #
###############################################################################



###############################################################################
#				INLUDES					      #
###############################################################################

INCLUDE  = push_swap.h
OBJ_DIR = $(patsubst %.c, $(OBJS)%.o, $(SRC))

###############################################################################
#				RULES					      #
###############################################################################

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ_DIR) $(LIBFT) -o $(NAME)  

$(OBJS)%.o: %.c Makefile push_swap.h
	@mkdir -p $(OBJS)
	@make -C libreries/libft
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@make -C libreries/libft clean --no-print-directory

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
