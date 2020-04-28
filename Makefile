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
INC_SRC = -I$(SRC_DIR) -I$(EVENT_DIR) -I$(ATTACK_DIR) -I$(ITEM_DIR) -I$(POKEMON_DIR)
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
LINK_SDL = -lSDL2 -lSDL2_image -lSDL2_ttf
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
event: _event_sdl_run

# GameManager tests
gm: _gamemanager_run

# Pokemon class tests
pokemon: _pokemon_run

#Attack class tests
attack : _attack_run
#en vrac pour ML mais je rangerai :)
fight : _fight_run
player : _player_run
item : _item_run

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

#_event_run: $(TARGET_DIR)/eventTests

_gamemanager_run: $(TARGET_DIR)/gmTests

_pokemon_run: $(OBJ_DIR)/Bulbasaur.o $(OBJ_DIR)/Charmander.o $(OBJ_DIR)/Mewthree.o $(OBJ_DIR)/Pokemon.o $(OBJ_DIR)/Squirtle.o $(OBJ_DIR)/WildPok.o

_event_sdl_run: $(TARGET_DIR)/eventTestSDL

_attack_run : $(OBJ_DIR)/Attack.o $(OBJ_DIR)/First.o $(OBJ_DIR)/Second.o

_fight_run : $(OBJ_DIR)/Fight.o

_player_run : $(OBJ_DIR)/Player.o

_item_run : $(OBJ_DIR)/Item.o

_test_ttf : $(TARGET_DIR)/ttfTests

## Actual builds ---------------------------------------------------------------

# Binairies
#$(TARGET_DIR)/eventTests: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/eventTests.o
#	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

$(TARGET_DIR)/eventTestSDL: $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/Component.o $(OBJ_DIR)/eventTestSDL.o $(OBJ_DIR)/sdlTools.o
	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

$(TARGET_DIR)/mapTests: $(OBJ_DIR)/Map.o $(OBJ_DIR)/mapTests.o
	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

$(TARGET_DIR)/gmTests: $(OBJ_DIR)/gmTests.o $(OBJ_DIR)/GameManager.o $(OBJ_DIR)/Map.o $(OBJ_DIR)/sdlTools.o $(OBJ_DIR)/Player.o
	$(CC) $^ -o $@

$(TARGET_DIR)/FightTest: $(OBJ_DIR)/Fight.o $(OBJ_DIR)/Event.o $(OBJ_DIR)/InheritedEvents.o $(OBJ_DIR)/Component.o $(OBJ_DIR)/eventTestSDL.o $(OBJ_DIR)/sdlTools.o
	$(CC) $^ -o $@ $(LIB_SDL) $(LINK_SDL)

# Main objects
$(OBJ_DIR)/eventTests.o: $(MAIN_DIR)/eventTests.cpp $(EVENT_DIR)/*.h
	$(CC) -c $(INCLUDE_FLAGS) $< -o $@

$(OBJ_DIR)/eventTestSDL.o: $(MAIN_DIR)/eventTestSDL.cpp $(EVENT_DIR)/Component.h $(EVENT_DIR)/Event.h $(EVENT_DIR)/InheritedEvents.h
	$(CC) -c $(INCLUDE_FLAGS) $< -o $@

$(OBJ_DIR)/mapTests.o: $(MAIN_DIR)/mapTests.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/gmTests.o: $(MAIN_DIR)/gmTests.cpp $(SRC_DIR)/GameManager.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS) -c $(INCLUDE_FLAGS) $< -o $@

# Required objects
$(OBJ_DIR)/InheritedEvents.o : $(EVENT_DIR)/InheritedEvents.cpp $(EVENT_DIR)/*.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/Component.o : $(EVENT_DIR)/Component.cpp $(EVENT_DIR)/*.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/GameManager.o: $(SRC_DIR)/GameManager.cpp $(SRC_DIR)/GameManager.h $(SRC_DIR)/Map.h $(SRC_DIR)/Player.h $(SRC_DIR)/sdlTools.h
	$(CC) -c $(INC_SRC) $(INCLUDE_FLAGS) $< -o $@

$(OBJ_DIR)/Event.o: $(EVENT_DIR)/Event.cpp $(EVENT_DIR)/Event.h $(EVENT_DIR)/Component.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/Map.o: $(SRC_DIR)/Map.cpp $(SRC_DIR)/Map.h
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/Pokemon.o: $(POKEMON_DIR)/Pokemon.cpp $(POKEMON_DIR)/Pokemon.h $(ATTACK_DIR)/Attack.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Charmander.o: $(POKEMON_DIR)/Charmander.cpp $(POKEMON_DIR)/Charmander.h $(POKEMON_DIR)/Pokemon.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Bulbasaur.o: $(POKEMON_DIR)/Bulbasaur.cpp $(POKEMON_DIR)/Bulbasaur.h $(POKEMON_DIR)/Pokemon.h $(ATTACK_DIR)/First.h $(ATTACK_DIR)/Second.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Squirtle.o: $(POKEMON_DIR)/Squirtle.cpp $(POKEMON_DIR)/Squirtle.h $(POKEMON_DIR)/Pokemon.h $(ATTACK_DIR)/First.h $(ATTACK_DIR)/Second.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Mewthree.o: $(POKEMON_DIR)/Mewthree.cpp $(POKEMON_DIR)/Mewthree.h $(POKEMON_DIR)/Pokemon.h $(ATTACK_DIR)/First.h $(ATTACK_DIR)/Second.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/WildPok.o: $(POKEMON_DIR)/WildPok.cpp $(POKEMON_DIR)/WildPok.h $(POKEMON_DIR)/Pokemon.h $(ATTACK_DIR)/First.h $(ATTACK_DIR)/Second.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Attack.o: $(ATTACK_DIR)/Attack.cpp $(ATTACK_DIR)/Attack.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS)  -c $< -o $@

$(OBJ_DIR)/First.o: $(ATTACK_DIR)/First.cpp $(ATTACK_DIR)/First.h $(ATTACK_DIR)/Attack.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS)  -c $< -o $@

$(OBJ_DIR)/Second.o:$(ATTACK_DIR)/Second.cpp $(ATTACK_DIR)/Second.h $(ATTACK_DIR)/Attack.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS) -c $< -o $@

$(OBJ_DIR)/Item.o: $(ITEM_DIR)/Item.cpp $(ITEM_DIR)/Item.h $(POKEMON_DIR)/Pokemon.h
	$(CC) -c $< -o $@

$(OBJ_DIR)/Player.o: $(SRC_DIR)/Player.cpp $(SRC_DIR)/Player.h $(POKEMON_DIR)/Pokemon.h $(ITEM_DIR)/Item.h $(POKEMON_DIR)/Bulbasaur.h $(POKEMON_DIR)/Charmander.h $(POKEMON_DIR)/Squirtle.h
	$(CC) $(INC_SRC) -c $< -o $@

$(OBJ_DIR)/Fight.o: $(EVENT_DIR)/Fight.cpp $(EVENT_DIR)/Fight.h $(ATTACK_DIR)/Attack.h $(SRC_DIR)/Player.h $(POKEMON_DIR)/Pokemon.h $(POKEMON_DIR)/WildPok.h $(ITEM_DIR)/Item.h $(EVENT_DIR)/Component.h
	$(CC) -c $(INC_SRC) $(INCLUDE_FLAGS)-c $< -o $@

$(OBJ_DIR)/sdlTools.o: $(SRC_DIR)/sdlTools.cpp $(SRC_DIR)/sdlTools.h
	$(CC) $(INC_SRC) $(INCLUDE_FLAGS) -c $< -o $@

