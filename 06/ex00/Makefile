NAME        := convert
CC          := c++

CFLAGS      := -Wall -Wextra -Werror 
CFLAGS		+= -std=c++11
SRC_FILES   := main.cpp ScalarConverter.cpp Type.cpp Tester.cpp

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

run: 	all
		./$(NAME)
	
test: 	clean
		@$(MAKE) CFLAGS+="-DTESTS=1" 
		@$(MAKE) all

test2: 	clean
		@$(MAKE) CFLAGS+="-DTESTS=2"
		./$(NAME)

coverage: 	clean
		@$(MAKE) CFLAGS="-DTESTS=3 --coverage -g -O0 -DTESTS=3"
		./$(NAME)
		gcovr --html-details coverage.html
		"/mnt/c/Program Files/Mozilla Firefox/firefox.exe" file://///wsl.localhost/Ubuntu/home/daaf/Documents/CPP/06/ex00/coverage.html
		sleep 1
		$(MAKE) fclean
		rm coverage.*

re: 	fclean all

.PHONY: clean fclean all run test re
