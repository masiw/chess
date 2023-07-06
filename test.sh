#! /usr/bin/env bash

# Test chess.c
echo "Testing chess.c"

# Compile the test
gcc -std=c17 -o run_test \
	src/test_chess.c src/chess.c \
	src/unity.c 

# Run the test
./run_test

# Delete the test
rm run_test

# Test array_utils.c
echo "Testing array_utils.c"

# Compile the test
gcc -std=c17 -o run_test \
	src/test_array_utils.c src/array_utils.c \
	src/unity.c

# Run the test
./run_test

# Delete the test
rm run_test
