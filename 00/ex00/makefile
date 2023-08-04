NAME		= 	megaphone
CC 			= 	g++

CFLAGS 		= 	-Wall -Wextra -Werror 
CFLAGS		+=	-std=c++98
INCLUDE 	= 	./include
VPATH 		= 	src

SRC_FILES 	=	megaphone.cpp

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
				./megaphone "string" " spaces " "DOTs.. .. .."

re 			: 	fclean all

.PHONY 		: 	clean fclean all 