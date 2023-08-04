NAME		= 	phonebook
CC 			= 	g++

CFLAGS 		= 	-Wall -Wextra -Werror 
CFLAGS		+=	-std=c++98
INCLUDE 	= 	./include
VPATH 		= 	src

SRC_FILES 	=	main.cpp PhoneBook.cpp Contacts.cpp

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
				./phonebook

re 			: 	fclean all

.PHONY 		: 	clean fclean all 