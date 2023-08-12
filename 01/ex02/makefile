NAME		= 	brain
CC 			= 	c++

ifneq (,$(findstring Linux,$(shell uname -a)))
	CFLAGS := -Wall -Wextra -Werror -Wno-error=deprecated-copy -Wno-deprecated-copy -std=c++11
else
	CFLAGS := -Wall -Wextra -Werror -std=c++98
endif

INCLUDE 	= 	./include
VPATH 		= 	src

SRC_FILES 	=	main.cpp

# object files
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

# Default build
all: $(OBJ_DIR) $(NAME)

# obj dir
${OBJ_DIR}	:
				mkdir -p ${OBJ_DIR}

# Build 
${NAME}		: 	${OBJ_FILES} 
				$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FILES): 	$(OBJ_DIR)/%.o : %.cpp
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -rf ${OBJ_DIR}

fclean		:	clean
				rm -rf ${NAME}

run			: 	all
				./brain

re 			: 	fclean all

.PHONY 		: 	clean fclean all 