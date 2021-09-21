
#
CC := g++
CC_FLAGS := -Wall -std=c++17 -g -pedantic -c


#
LINK := g++
LINK_FLAGS := -Wall -pedantic -std=c++17


#
BIN_NAME := main
BIN := ./$(BIN_NAME)


#
default: run


#
run:	build
	$(BIN)
.PHONY: run


#
build:	$(BIN)
.PHONY: build

#
$(BIN):	main.o
	$(LINK) $(LINK_FLAGS) "$^" -o "$@"


#
main.o:	main.cpp
	$(CC) $(CC_FLAGS) $< -o "$@"


#
clean:
	-rm *.o
	-rm $(BIN)
.PHONY: clean

