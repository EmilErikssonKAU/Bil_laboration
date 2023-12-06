# The compiles that is used
CC = gcc

# Name of the executeables
NAME = Bil-Register
DEBUGNAME = DEBUG

# Name of some directories
BUILD = build
SRC = src


# Flags that are used when compiling the program
FLAGS = 
DEBUGFLAGS = -Wall -ggdb3


# Relative path to source and object files
SRCFILES = $(wildcard $(SRC)/*.c)
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))



# Keywords so make does not get confused
.PHONY: build dirs clean debug



# Builds the exeuteable file from object files
build: $(OBJFILES)
	@echo "Skapar $(NAME)"
	@$(CC) $(FLAGS) $^ -o $(NAME)
	@echo "Klart!"

# Rule for object files that runs for each file
$(BUILD)/%.o: $(SRC)/%.c | dirs
	@echo "Kompilerar $<"
	@$(CC) -c -o $@ $<

# Creates build directory in case there is none
dirs: 
	@mkdir -p $(BUILD)



# Builds the exeuteable file from object files, this function is used with memCheck
debug: $(OBJFILES)
	@echo "Skapar $(DEBUGNAME)"
	@$(CC) $(DEBUGFLAGS) $^ -o $(DEBUGNAME)
	@echo "Klart!"

# Funtion that you can use too check for memory leaks
memCheck: debug
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(DEBUGNAME)

# Cleans up compiled files
clean:
	rm -f $(OBJFILES) $(NAME)