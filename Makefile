## Constants -------------------------------------------------------------------
# General
CC = g++ -Wall

OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
LIB_DIR = lib
MAIN_DIR = $(SRC_DIR)/main
EVENT_DIR = $(SRC_DIR)/event
ATTACK_DIR = $(SRC_DIR)/attack
ITEM_DIR = $(SRC_DIR)/item
POKEMON_DIR = $(SRC_DIR)/pokemon

# Include-related
INC_BOOST = -Iinclude/boost_1_72_0/
INC_SDL2 = -Iinclude/SDL2/
INCLUDE_FLAGS = $(INC_BOOST) $(INC_SDL2)

# Library-related
ifeq ($(OS),Windows_NT)
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		LIB_SDL = -L$(LIB_DIR)/w_x64
		TARGET_DIR = $(BIN_DIR)/w_x64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		LIB_SDL = -L$(LIB_DIR)/w_x86
		TARGET_DIR = $(BIN_DIR)/w_x86
	endif
else
	LIB_SDL = -L$(LIB_DIR)/linux
	TARGET_DIR = $(BIN_DIR)
endif
LIBRARIES_FLAGS = $(LIB_SDL)

# Link-related
LINK_SDL = -lSDL2 -lSDL2_image
ifeq ($(OS),Windows_NT)
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		LINKER_FLAGS = -lmingw64 $(LINK_SDL)
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		LINKER_FLAGS = -lmingw32 $(LINK_SDL)
	endif
else
	LINKER_FLAGS = $(LINK_SDL)
endif

## Build commands---------------------------------------------------------------

# Builds everything
default : setup map event

# Map tests
map: _map_run

# Event tests
event: _event_run

# GameManager tests
gm: _gamemanager_run

# Pokemon class tests
pokemon: _pokemon_run

# Cleans executables
clean:
ifeq ($(OS),Windows_NT)
	if exist $(TARGET_DIR)/mapTests.exe rm $(TARGET_DIR)/mapTests.exe
	if exist $(TARGET_DIR)/eventTests.exe rm $(TARGET_DIR)/eventTests.exe
else
	test ! -e $(TARGET_DIR)/mapTests || rm $(TARGET_DIR)/mapTests
	test ! -e $(TARGET_DIR)/eventTests || rm $(TARGET_DIR)/eventTests
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
_map_run: $(TARGET_DIR)/mapTests

_event_run: $(TARGET_DIR)/eventTests

_gamemanager_run: $(TARGET_DIR)/gmTests

_pokemon_run: $(POKEMON_DIR)/%.o


## Actual builds ---------------------------------------------------------------

# Binairies
$(TARGET_DIR)/eventTests: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o
	$(CC) $^ -o $@

$(TARGET_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

$(TARGET_DIR)/gmTests: $(OBJ_DIR)/gmTests.o $(OBJ_DIR)/GameManager.o $(OBJ_DIR)/Map.o
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

$(POKEMON_DIR)/%.o: $(POKEMON_DIR)/%.cpp $(POKEMON_DIR)/%.h $(POKEMON_DIR)/Pokemon.h
	$(CC) -c $< -o $@
