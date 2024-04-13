.PHONY:clean

OBJ=./main.c ./src/*.c ../common/src/*.c 
TARGET=server

all:
	gcc -o $(TARGET) $(OBJ) -D_D
clean:
	$(RM) $(TARGET)
