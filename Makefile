CXX		  := g++
CXX_FLAGS := -w -Wextra -std=c++17 -ggdb -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=-lthostmduserapi_se
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB)   $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
