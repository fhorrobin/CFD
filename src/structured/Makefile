CC = icpc
OUTPUT = cfd.x
OBJECTS = main.o Initialize.o WriteFile.o

default: cfd

all: clean cfd

cfd: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUT)

main.o: main.cpp Cell.h Config.h
	$(CC) -c main.cpp

Initialize.o: Initialize.cpp Initialize.h
	$(CC) -c Initialize.cpp

WriteFile.o: WriteFile.cpp WriteFile.h
	$(CC) -c WriteFile.cpp

clean:
	rm *.o
	rm *.x