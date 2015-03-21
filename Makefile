EXEC= minautorus.out
CXX= g++
CXXFLAGS= -g -std=c++11 -I"include/" -I"lib/include/" -Wall -lsfml-graphics -lsfml-window -lsfml-system
SRC= $(wildcard src/*.cpp lib/src/*.cpp)
OBJ= $(SRC:.cpp=.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f src/*.o
	rm -f lib/src/*.o

	rm -f src/*~ #for emacs
	rm -f lib/src/*~ #for emacs

mrproper: clean
	rm -f $(EXEC)
