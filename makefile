valueof: valueof.o
	g++ -g -o valueof valueof.o
valueof.o: valueof.cpp environment.o
	g++ -g -c valueof.cpp
environment.o: environment.cpp expression.o
	g++ -g -c environment.cpp
expression.o: expression.cpp
	g++ -g -c expression.cpp