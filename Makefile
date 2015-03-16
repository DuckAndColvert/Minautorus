EXEC= minautorus
CXX= g++
CXXFLAGS= -g -std=c++11 -I"include/" -Wall
SRC= src/*
OBJ= $(SRC:.cpp=.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
