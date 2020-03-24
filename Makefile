##  ----------------------------------------------------- Constants -----------
COMP = g++ -Wall

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

BOOST = include/boost_1_72_0/
## ------------------------------------------------------build commands--------

# default builds everything
default : map event

# make map makes the map test
map: make_dir map_run

# make event makes the event test
event: make_dir event_run
## ----------------------------------------------- make_dir ------------------

# makes necessary directories if empty
make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)
endif

## ------------------------------------------------- runs ---------------------

map_run: $(BIN_DIR)/mapTests

event_run: $(BIN_DIR)/eventTests
## ----------------------------------------------------------- actual builds --
# main builds (binairies)
$(BIN_DIR)/eventTests: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o
	$(COMP) $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o -o $(BIN_DIR)/eventTests

$(BIN_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(COMP) $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o -o $(BIN_DIR)/mapTests

## objects builds
# mains :
$(OBJ_DIR)/eventTests.o: $(SRC_DIR)/main/eventTests.cpp $(SRC_DIR)/event/Event.h $(SRC_DIR)/event/InheritedEvents.h
	$(COMP) -c $(SRC_DIR)/main/eventTests.cpp -o $(OBJ_DIR)/eventTests.o

$(OBJ_DIR)/mapTests.o: $(SRC_DIR)/main/mapTests.cpp $(SRC_DIR)/Map.h
	$(COMP) -I $(BOOST) -c $(SRC_DIR)/main/mapTests.cpp -o $(OBJ_DIR)/mapTests.o

# files :
$(OBJ_DIR)/InheritedEvents.o : $(SRC_DIR)/event/InheritedEvents.cpp $(SRC_DIR)/event/InheritedEvents.h $(SRC_DIR)/event/Event.h
	$(COMP) -c $(SRC_DIR)/event/InheritedEvents.cpp -o $(OBJ_DIR)/InheritedEvents.o

$(OBJ_DIR)/Event.o: $(SRC_DIR)/event/Event.cpp $(SRC_DIR)/event/Event.h
	$(COMP) -c $(SRC_DIR)/event/Event.cpp -o $(OBJ_DIR)/Event.o

$(OBJ_DIR)/Map.o: $(SRC_DIR)/Map.cpp $(SRC_DIR)/Map.h
	$(COMP) -I $(BOOST) -c $(SRC_DIR)/Map.cpp -o $(OBJ_DIR)/Map.o
