CC=g++
CCFLAGS=-g -Wall -Wextra
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(wildcard *.h)
TARGET=a.out

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS) Makefile
	$(CC) $(CCFLAGS) -c $<

#%.o: %.cpp
#$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o *.gch $(TARGET) && rm -rf a.out.dSYM
