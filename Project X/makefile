Project: projX.o DataType.o SmartPtr.o
	g++ -g projX.cpp DataType.o SmartPtr.o -o project

main: projX.cpp DataType.h SmartPtr.h
	g++ -g -c projX.cpp -o main.o

DataType: DataType.cpp DataType.h
	g++ -g -c DataType.cpp -o DataType.o

SmartPtr: SmartPtr.cpp SmartPtr.h DataType.h
	g++ -g -c SmartPtr.cpp -o SmartPtr.o
