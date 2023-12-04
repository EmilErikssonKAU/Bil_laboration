CC = gcc

NAME = program

BUILD = build
SRC = src

SRCFILES = $(wildcard $(SRC)/*.c)
OBJFILES = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCFILES))

# Skapar nyckelord så att make inte tror att dessa namn är filer
.PHONY: build dirs clean

<<<<<<< HEAD
# Skapar objektfiler
%.o: $(DIR)/%.c
	@echo "Kompilerar $<"
	$(CC) $(Flags) $< -o $(BUILD)/$@

# Skapar den körbara filen
build: $(OBJFILES)
	@echo "Skapar $(NAME)"
	$(CC) $(addprefix $(BUILD)/,$^) -o $(NAME)
=======
build: $(OBJFILES)
	@echo "Skapar $(NAME)"
	@$(CC) $^ -o $(NAME)
>>>>>>> 364fc6c130f73e4d064b1ab605d907c78201cd64
	@echo "Klart!"

$(BUILD)/%.o: $(SRC)/%.c | dirs
	@echo "Kompilerar $<"
	@$(CC) -c -o $@ $<

dirs: 
	@mkdir -p $(BUILD)

# Rensar upp filer när de inte längre behövs
clean:
	rm -f $(OBJFILES) $(NAME)