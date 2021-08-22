NAME		=	philo

# **************************************************************************** #
# *-------------------------PATHS AND DIRECTORIES----------------------------* #
# **************************************************************************** #

include	src.mk
SRC_DIR		=	src
SRC_SUBDIR	=	utils

SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ_DIR		=	obj
OBJ_SUBDIR	=	$(addprefix $(OBJ_DIR)/,$(SRC_SUBDIR))
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC_FILES:%.c=%.o))

INC_DIR		=	include

# **************************************************************************** #
# *---------------------------COMPILERS AND FLAGS----------------------------* #
# **************************************************************************** #

CC			=	gcc
PTHREAD		=	-pthread
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-g3 -fsanitize=address -Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_DIR),-I $(path))
RM			=	rm -f

# **************************************************************************** #
# *-----------------------------------RULES----------------------------------* #
# **************************************************************************** #

$(OBJ_DIR)/%.o:	src/%.c
	@mkdir -p $(OBJ_DIR) $(OBJ_SUBDIR)
	@$(CC) $(PTHREAD) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ) 
	@$(foreach path, $(LIB_DIR), make -C $(path);)
	@$(CC) $(PTHREAD) $(CFLAGS) $(OBJ) -o $@
	@echo "$(basename $(NAME)) built successfully."

all:	$(NAME)

rm_obj:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files for $(basename $(NAME)) removed."

clean:	rm_obj

fclean:	rm_obj
	@$(RM) $(NAME)
	@echo "$(NAME) removed."

re:	fclean all

test: all
	@./$(NAME) 1 2 3 4 5

norm:
		@clear && norminette include/ src/ | nform | grep -v "OK"

.PHONY: all clean fclean re rm_obj norm lib_norm test