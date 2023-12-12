CC = gcc

NAME = Bil-Register

BUILD = build
SRC = src

FLAGS = -Wall

SRCFILES = $(wildcard $(SRC)/*.c)
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))

# Skapar nyckelord så att make inte tror att dessa namn är filer
.PHONY: build dirs clean memCheck

build: $(OBJFILES) 
	@echo "Skapar $(NAME)"
	@$(CC) $(FLAGS) $^ -o $(NAME)
	@echo "Klart!"

$(BUILD)/%.o: $(SRC)/%.c | dirs
	@echo "Kompilerar $<"
	@$(CC) -c -o $@ $<

dirs: 
	@mkdir -p $(BUILD)

memCheck:
	-valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=log.txt ./$(NAME)

# Rensar upp filer när de inte längre behövs
clean:
	@rm -f $(OBJFILES) $(NAME)
	@rmdir $(BUILD)