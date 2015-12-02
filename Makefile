CC=/usr/bin/gcc
SRC_DIR=src
OBJ_DIR=build
INC_DIR=includes
SRCS=$(SRC_DIR)/stack.c
OBJS=$(OBJ_DIR)/stack.o

CFLAGS=-c -Wall

INCS=$(INC_DIR)/node.h $(INC_DIR)/stack.h

all: $(OBJS)
	$(CC) -I$(INC_DIR) -o main $(SRC_DIR)/main.c $(OBJS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean: $(OBJS) main
	rm $(OBJS)
	rm main
