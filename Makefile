# Makefile for kohi,v 1.0 2008/12/14
# author @ shakka

BIN			= kohi
DIR			= /usr/local/
CC				= gcc
OBJ			= $(BIN).o
LIB			= lib$(BIN).a
CFLAGS		= -c -Wall -g -o
RM				= rm -f *.a *.o *~

all : $(OBJ) $(LIB)

$(OBJ) : $(BIN).c
	@echo 'Object >>'
	@echo 'Building object >>'
	$(CC) $(CFLAGS) $(OBJ) $(BIN).c
	@echo 'done'

$(LIB): $(OBJ)
	@echo 'Library >>'
	@echo 'Building library ...'
	$(AR) rcs $@ $^
	@echo 'done'

install: $(LIB)
	@echo 'Install >>'
	@echo 'Building destination directory...'
	mkdir -p $(DIR)
	@echo 'Copying header file...'
	cp -f $(BIN).h $(DIR)include/
	@echo 'Copying library file...'
	cp -f $(LIB) $(DIR)lib/
	@echo 'done'

uninstall:
	@echo 'Uninstall >>'
	@echo 'Deleting header file...'
	rm -f $(DIR)include/$(BIN).h
	@echo 'Deleting library file...'
	rm -f $(DIR)lib/$(LIB)
	@echo 'done'

clean:
	@echo 'Clean >>'
	@echo 'Cleaning project...'
	$(RM)
	@echo 'done'
