## Constants -------------------------------------------------------------------
# General
CC = g++ -Wall

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib
MAIN_DIR = $(SRC_DIR)/main
EVENT_DIR = $(SRC_DIR)/event

# Include-related
INC_BOOST = -Iinclude/boost_1_72_0/
INC_SDL2 = -Iinclude/SDL2/
INCLUDE_FLAGS = $(INC_BOOST) $(INC_SDL2)

# Library-related
ifeq ($(OS),Windows_NT)
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		LIB_SDL = -L$(LIB_DIR)/w_x64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		LIB_SDL = -L$(LIB_DIR)/w_x86
	endif
else
	LIB_SDL = -L$(LIB_DIR)/linux
endif
LIBRARIES_FLAGS = $(LIB_SDL)

# Link-related
LINK_SDL = -lSDL2 -lSDL2_image
LINKER_FLAGS = $(LINK_SDL)


## Build commands---------------------------------------------------------------

# Builds everything
default : setup map event

# Map tests
map: map_run

# Event tests
event: event_run

# GameManager tests
gm: gamemanager_run

# Cleans executables
clean:
ifeq ($(OS),Windows_NT)
	if exist $(BIN_DIR)/mapTests.exe rm $(BIN_DIR)/mapTests.exe
	if exist $(BIN_DIR)/eventTests.exe rm $(BIN_DIR)/eventTests.exe
else
	test ! -e $(BIN_DIR)/mapTests || rm $(BIN_DIR)/mapTests
	test ! -e $(BIN_DIR)/eventTests || rm $(BIN_DIR)/eventTests
endif

# Cleans executables and objects
realclean: clean
	rm $(OBJ_DIR)/*.o

## Setup -----------------------------------------------------------------------
setup: make_dir

# Makes necessary directories if empty
make_dir:
ifeq ($(OS),Windows_NT)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)
endif


## Runs ------------------------------------------------------------------------
map_run: $(BIN_DIR)/mapTests

event_run: $(BIN_DIR)/eventTests

gamemanager_run: $(BIN_DIR)/gmTests


## Actual builds ---------------------------------------------------------------

# Binairies
$(BIN_DIR)/eventTests: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o
	$(CC) $^ -o $@

$(BIN_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

$(BIN_DIR)/gmTests: $(OBJ_DIR)/gmTests.o $(OBJ_DIR)/GameManager.o $(OBJ_DIR)/Map.o
	$(CC) $^ -o $@

# Main objects
$(OBJ_DIR)/eventTests.o: $(MAIN_DIR)/eventTests.cpp $(EVENT_DIR)/*.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/mapTests.o: $(MAIN_DIR)/mapTests.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/gmTests.o: $(MAIN_DIR)/gmTests.cpp $(SRC_DIR)/GameManager.h $(SRC_DIR)/Map.h
	$(CC) -c $(INCLUDE_FLAGS) $< -o $@

# Required objects
$(OBJ_DIR)/InheritedEvents.o : $(EVENT_DIR)/InheritedEvents.cpp $(EVENT_DIR)/*.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/GameManager.o: $(SRC_DIR)/GameManager.cpp $(SRC_DIR)/GameManager.h $(SRC_DIR)/Map.h
	$(CC) -c $(INCLUDE_FLAGS) $< -o $@

$(OBJ_DIR)/Event.o: $(EVENT_DIR)/Event.cpp $(EVENT_DIR)/Event.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/Map.o: $(SRC_DIR)/Map.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@
