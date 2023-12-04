CC = gcc

NAME = program

BUILD = build
SRC = src

SRCFILES = $(wildcard $(SRC)/*.c)
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))

# Skapar nyckelord så att make inte tror att dessa namn är filer
.PHONY: build dirs clean

build: $(OBJFILES)
	@echo "Skapar $(NAME)"
	@$(CC) $^ -o $(NAME)
	@echo "Klart!"

$(BUILD)/%.o: $(SRC)/%.c | dirs
	@echo "Kompilerar $<"
	@$(CC) -c -o $@ $<

dirs: 
	@mkdir -p $(BUILD)

# Rensar upp filer när de inte längre behövs
clean:
	rm -f $(OBJFILES) $(NAME)