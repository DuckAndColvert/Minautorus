EXEC= minautorus.out
CXX= g++
CXXFLAGS= -g -std=c++11 -I"include/" -Wall -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f src/*.o
	rm -f src/*~ #for emacs

mrproper: clean
	rm -f $(EXEC)
