CC = g++
CFLAGS = -std=c++14 -g -Wall
TARGET = finalProject.o
SRCS = finalProject.cpp
S1 = Paint.cpp
S2 = Para.cpp

OPENCV = `pkg-config opencv4 --cflags --libs`
LIBS = $(OPENCV)

$(TARGET) : 
	$(CC) $(CFLAGS) $(LIBS) -o $(TARGET) $(SRCS) $(S1) $(S2)

## clean
clean:
	rm -f $(TARGET) $(OBJ) $(DEP)