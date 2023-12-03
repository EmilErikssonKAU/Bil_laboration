# The kompilator used
CC = gcc

# Namnet på filen
NAME = Bil-Register

# Källkodskatalog
DIR = src

# Buildfolder
BUILD = build

Flags = -c

# Lista över källkodsfiler och objektfiler
# wildcard används för att * ska fungera
SRCFILES = $(wildcard $(DIR)/*.c)
OBJFILES = $(patsubst $(DIR)/%.c, %.o, $(SRCFILES))

# Skapar nyckelord så att make inte tror att dessa namn är filer
.PHONY: build clean

# Skapar objektfiler
%.o: $(DIR)/%.c
	@echo "Kompilerar $<"
	$(CC) $(Flags) $< -o $(BUILD)/$@

# Skapar den körbara filen
build: $(OBJFILES)
	@echo "Skapar $(NAME)"
	$(CC) $(addprefix $(BUILD)/,$^) -o $(NAME)
	@echo "Klart!"

# Rensar upp filer när de inte längre behövs
clean:
	rm -f $(addprefix $(BUILD)/, $(OBJFILES)) $(NAME)
