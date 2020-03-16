COMP = g++ -Wall

OBJ_DIR = ../obj
BIN_DIR = ../bin

BOOST = ../include/boost_1_72_0/

run: $(BIN_DIR)/mapTests

$(BIN_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(COMP) $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o -o $(BIN_DIR)/mapTests

$(OBJ_DIR)/mapTests.o: mapTests.cpp Map.h
	$(COMP) -I $(BOOST) -c mapTests.cpp -o $(OBJ_DIR)/mapTests.o

$(OBJ_DIR)/Map.o: Map.cpp Map.h
	$(COMP) -I $(BOOST) -c Map.cpp -o $(OBJ_DIR)/Map.o
