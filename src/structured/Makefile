CC = icpc
CFLAGS = -O3 -qopenmp
OUTPUT = cfd.x
OBJECTS = main.o Initialize.o WriteFile.o CalculateTimeStep.o GhostCellUpdater.o VariableReconstructor.o Flux.o TimeIntegration.o VariableCopy.o

default: cfd

all: clean cfd

cfd: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(OUTPUT)

main.o: main.cpp Cell.h Config.h
	$(CC) $(CFLAGS) -c main.cpp

Initialize.o: Initialize.cpp Initialize.h
	$(CC) $(CFLAGS) -c Initialize.cpp

WriteFile.o: WriteFile.cpp WriteFile.h
	$(CC) $(CFLAGS) -c WriteFile.cpp

CalculateTimeStep.o: CalculateTimeStep.cpp CalculateTimeStep.h
	$(CC) $(CFLAGS) -c CalculateTimeStep.cpp

GhostCellUpdater.o: GhostCellUpdater.cpp GhostCellUpdater.h
	$(CC) $(CFLAGS) -c GhostCellUpdater.cpp

VariableReconstructor.o: VariableReconstructor.cpp VariableReconstructor.h
	$(CC) $(CFLAGS) -c VariableReconstructor.cpp

Flux.o: Flux.cpp Flux.h
	$(CC) $(CFLAGS) -c Flux.cpp

TimeIntegration.o: TimeIntegration.cpp TimeIntegration.h
	$(CC) $(CFLAGS) -c TimeIntegration.cpp

VariableCopy.o: VariableCopy.cpp VariableCopy.h
	$(CC) $(CFLAGS) -c VariableCopy.cpp

clean:
	rm *.o
	rm *.x