# The compilator used
CC = gcc

# Name of file
NAME = Bil-Register

# Sorce file dir
DIR = src

# List of src and obj files
# wildcard is used for * to work
SRCFILES = $(wildcard $(DIR)/*.c)
OBJFILES = $(wildcard *.o)

# Creates keywords so make does not this these name are files
.PHONY: obj-build, build, clean

# "make build" runs both obj-build and final
build: obj-build, final

# creates obj files
obj-build: $(SRCS)
	$(CC) -c $(SRCFILES)

# creates the executable file
final: $(OBJFILES)
	$(CC) -o $(NAME) 

# cleans up files when done
clean:
	rm -f $(OBJFILES) $(NAME)