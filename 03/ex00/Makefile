NAME		= 	clap
CC 			= 	c++

ifneq (,$(findstring Linux,$(shell uname -a)))
	CFLAGS := -Wall -Wextra -Werror -Wno-error=deprecated-copy -Wno-deprecated-copy -std=c++11
else
	CFLAGS := -Wall -Wextra -Werror -std=c++98
endif

SRC_FILES 	=	main.cpp ClapTrap.cpp

# object files
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

# Default build
all: $(OBJ_DIR) $(NAME)

# obj dir
${OBJ_DIR}	:
				@mkdir -p ${OBJ_DIR}

# Build 
${NAME}		: 	${OBJ_FILES} 
				@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FILES): 	$(OBJ_DIR)/%.o : %.cpp
				@$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -rf ${OBJ_DIR}

fclean		:	clean
				rm -rf ${NAME}

run			: 	all
				./${NAME}

re 			: 	fclean all

.PHONY 		: 	clean fclean all 

# .DEFAULT_GOAL:=run