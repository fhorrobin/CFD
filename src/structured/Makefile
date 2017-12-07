CC = icpc
OUTPUT = cfd.x
OBJECTS = main.o Initialize.o WriteFile.o # CalculateTimeStep.o GhostCellUpdater.o VariableReconstructor.o Flux.o TimeIntegration.o VariableCopy.o

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

CalculateTimeStep.o: CalculateTimeStep.cpp CalculateTimeStep.h
	$(CC) -c CalculateTimeStep.cpp

GhostCellUpdater.o: GhostCellUpdater.cpp GhostCellUpdater.h
	$(CC) -c GhostCellUpdater.cpp

VariableReconstructor.o: VariableReconstructor.cpp VariableReconstructor.h
	$(CC) -c VariableReconstructor.cpp

Flux.o: Flux.cpp Flux.h
	$(CC) -c Flux.cpp

TimeIntegration.o: TimeIntegration.cpp TimeIntegration.h
	$(CC) -c TimeIntegration.cpp

VariableCopy.o: VariableCopy.cpp VariableCopy.h
	$(CC) -c VariableCopy.cpp

clean:
	rm *.o
	rm *.x