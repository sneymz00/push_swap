###############################################################################
#								STANDARS	 								  #
###############################################################################
NAME 		= 		push_swap
RM 			= 		rm -rf
LIBFT		=		libreries/libft/libft.a
LIBFT_DIR	=		lbreries/libft/
OBJS		= 		obj/
SRC_DIR		=		src/

###############################################################################
#								COMPILER	  								  #
###############################################################################

CC 			= 		gcc
CCFLAGS		= 		-Wall -Wextra -Werror 

###############################################################################
#									SRC    									  #
###############################################################################

SRC 		= 		$(SRC_DIR)main.c\
								$(SRC_DIR)init_node.c\
								$(SRC_DIR)aux_stacks.c\
								$(SRC_DIR)init_stacks.c\
								$(SRC_DIR)my_error.c\
								$(SRC_DIR)mains_stack.c\
								$(SRC_DIR)my_split.c\
								$(SRC_DIR)push.c\
								$(SRC_DIR)reverse_rotate.c\
								$(SRC_DIR)rotates.c\
								$(SRC_DIR)swap.c\
								$(SRC_DIR)utils_stacks.c

###############################################################################
#								INLUDES	      								  #
###############################################################################

INCLUDE  = push_swap.h
OBJ_DIR = $(patsubst $(SRC_DIR)%.c, $(OBJS)%.o, $(SRC))

###############################################################################
#								RULES	      								  #
###############################################################################

all:
	@make -C libreries/libft --no-print-directory
	@make $(NAME) --no-print-directory

$(NAME):: $(OBJ_DIR) $(LIBFT)
	@echo "Compiling $<"
	@$(CC) $(CCFLAGS) $(LIBFT) $(OBJ_DIR) -o $(NAME)
$(NAME)::
	@echo "$(NAME) compiled"

$(OBJS)%.o: $(SRC_DIR)%.c Makefile $(INCLUDE) $(LIBFT) 
	@echo "Compiling $<"
	@mkdir -p $(OBJS)
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@$(RM) $(OBJS)
	@make -C libreries/libft clean --no-print-directory

fclean: clean
	@echo "Cleaning file..."
	@$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
