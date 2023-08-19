NAME        := PmergeMe
CC          := c++

ifneq (,$(findstring Linux,$(shell uname -a)))
	CFLAGS := -Wall -Wextra -Werror -Wpedantic -Wno-error=deprecated-copy -Wno-deprecated-copy -std=c++11
else
	CFLAGS := -Wall -Wextra -Werror -Wpedantic -std=c++11
endif

# CFLAGS += -std=c++98
SRC_FILES   := main.cpp PmergeMe.cpp SortVect.cpp SortDeque.cpp

# object files
OBJ_DIR 	:= obj
OBJ_FILES 	:= $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

# Default build
all: $(OBJ_DIR) $(NAME)

# obj dir
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

# Build
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_FILES): $(OBJ_DIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -rf $(NAME)

run: 	re
		./$(NAME) `jot -r 3000 1 1000 | tr '\n' ' '`
	
test: 	clean
		@$(MAKE) CFLAGS="-DTESTS=1" 
		@$(MAKE) all

re: 	fclean all

.PHONY: clean fclean all run test re
