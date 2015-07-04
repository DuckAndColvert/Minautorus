EXEC= minautorus.out
CXX= clang++
CXXFLAGS= -g -std=c++11 -I"include/" -I"lib/include/" -Wall 
SRC= $(wildcard src/*.cpp lib/src/*.cpp)
HEADER= $(wildcard src/*.hpp lib/src/*.hpp)
OBJ= $(SRC:.cpp=.o)

$(EXEC): $(HEADER) $(OBJ) 
	$(CXX) $(CXXFLAGS) $^ -lsfml-graphics -lsfml-window -lsfml-system -o $@

clean:
	rm -f src/*.o
	rm -f lib/src/*.o

	rm -f src/*~ #for emacs
	rm -f lib/src/*~ #for emacs

mrproper: clean
	rm -f $(EXEC)


.PHONY: clean mrproper
