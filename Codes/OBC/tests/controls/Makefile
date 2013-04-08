CC = gcc
FLAGS = -Wall -g
TARGET = main
OBJ =  frame.o igrf.o mathutil.o propagator.o quest.o controller.o

all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -lm $(OBJ) -o $@
%.o : %.c
	$(CC) $(FLAGS) -c $<
clean:
	rm -f $(OBJ) $(TARGET)
