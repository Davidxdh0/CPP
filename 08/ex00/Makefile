NAME        := easy
CC          := c++

ifneq (,$(findstring Linux,$(shell uname -a)))
	CFLAGS := -Wall -Wextra -Werror -Wno-error=deprecated-copy -Wno-deprecated-copy
else
	CFLAGS := -Wall -Wextra -Werror -Wpedantic
endif

CFLAGS += -std=c++98 -std=c++11
SRC_FILES   := main.cpp

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
		./$(NAME)
	
test: 	clean
		@$(MAKE) CFLAGS="-DTESTS=1" 
		@$(MAKE) all

re: 	fclean all

.PHONY: clean fclean all run test re
