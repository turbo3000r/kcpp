CXX ?= C:/cygwin64/bin/g++.exe
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -pedantic

INCLUDE_DIR := include

MAIN_SRC := src/main.cpp
WORK_SRC := src/zadanie1/WorkexampleOne.cxx
TEST_SRC := src/zd-x.test.cpp

MAIN_BIN := main.exe
TEST_BIN := zd-x.test.exe

.PHONY: all run test clean

all: $(MAIN_BIN)

$(MAIN_BIN): $(MAIN_SRC) $(WORK_SRC) $(INCLUDE_DIR)/WorkExampleOne.h
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(MAIN_SRC) $(WORK_SRC) -o $(MAIN_BIN)

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_BIN)

run: $(MAIN_BIN)
	./$(MAIN_BIN)

clean:
	rm -f $(MAIN_BIN) $(TEST_BIN)
