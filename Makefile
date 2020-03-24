## Constants -------------------------------------------------------------------
# General
CC = g++ -Wall

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib

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
LINK_SDL2 = -lSDL2
LINKER_FLAGS = $(LINK_SDL2)


## Build commands---------------------------------------------------------------

# Builds everything
default : setup map event

# Map tests
map: map_run

# Event tests
event: event_run


## Setup -----------------------------------------------------------------------
setup: make_dir

# Makes necessary directories if empty
make_dir:
ifeq ($(OS),Windows_NT)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	if not exist $(BIN_DIR) mkdir $(BIN_DIR)
else
	test -d $(OBJ_DIR) || mkdir -p $(OBJ_DIR)
	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)
endif


## Runs ------------------------------------------------------------------------
map_run: $(BIN_DIR)/mapTests

event_run: $(BIN_DIR)/eventTests


## Actual builds ---------------------------------------------------------------

# Binairies
$(BIN_DIR)/eventTests: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o
	$(CC) $^ -o $@

$(BIN_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(CC) $(LIBRARIES_FLAGS) $(LINK_SDL2) $^ -o $@

# Main objects
$(OBJ_DIR)/eventTests.o: $(SRC_DIR)/main/eventTests.cpp $(SRC_DIR)/event/Event.h $(SRC_DIR)/event/InheritedEvents.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/mapTests.o: $(SRC_DIR)/main/mapTests.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

# Required objects
$(OBJ_DIR)/InheritedEvents.o : $(SRC_DIR)/event/InheritedEvents.cpp $(SRC_DIR)/event/InheritedEvents.h $(SRC_DIR)/event/Event.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/Event.o: $(SRC_DIR)/event/Event.cpp $(SRC_DIR)/event/Event.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/Map.o: $(SRC_DIR)/Map.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@
