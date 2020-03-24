COMP = g++ -Wall

OBJ_DIR = ../obj
BIN_DIR = ../bin

BOOST = ../include/boost_1_72_0/

default: make_dir run

make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)
endif

run: $(BIN_DIR)/mapTests

$(BIN_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(COMP) $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o -o $(BIN_DIR)/mapTests

$(OBJ_DIR)/mapTests.o: mapTests.cpp Map.h
	$(COMP) -I $(BOOST) -c mapTests.cpp -o $(OBJ_DIR)/mapTests.o

$(OBJ_DIR)/Map.o: Map.cpp Map.h
	$(COMP) -I $(BOOST) -c Map.cpp -o $(OBJ_DIR)/Map.o
