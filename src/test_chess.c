#include "unity.h"
#include "chess.h"
#include <stdlib.h>
#include <string.h>

/**
 * Compare function for qsort
 */
int compare(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
}

void setUp(void)
{
	init_game();
}

void tearDown(void)
{
}

void test_get_piece(void)
{
	TEST_ASSERT_EQUAL_CHAR('R', get_piece("a1"));
	TEST_ASSERT_EQUAL_CHAR('P', get_piece("a2"));
	TEST_ASSERT_EQUAL_CHAR('k', get_piece("e8"));
}

/**
 * Test get current player
 */
void test_get_current_player(void)
{
	TEST_ASSERT_MESSAGE(get_current_player() == WHITE, "get_current_player() should return WHITE");
}

/**
 * Test set the current board
 */
void test_set_board(void)
{
	char testPosition[8][8] = {
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'r', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
	};
	set_board(testPosition);
	TEST_ASSERT_EQUAL_CHAR('R', get_piece("a1"));
	TEST_ASSERT_EQUAL_CHAR('r', get_piece("c5"));
}
	


/**
 * Test get valid rook moves
 */
void test_get_valid_rook_moves(void)
{
	char testPosition[8][8] = {
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'r', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
	};
	set_board(testPosition);
	char *validMoves[] = {"c5a5", "c5b5", "c5c1", "c5c2", "c5c3", "c5c4", "c5c6", "c5c7", "c5c8", "c5d5", "c5e5", "c5f5", "c5g5", "c5h5"};
	// sort the valid moves
	qsort(validMoves, 14, sizeof(char *), compare);
	char **moves = get_valid_moves("c4");
	// sort the moves
	qsort(moves, 11, sizeof(char *), compare);
	TEST_ASSERT_EQUAL_STRING_ARRAY(validMoves, moves, 11);
}

/**
 * Test runner
 */
int main(void)
{
		UNITY_BEGIN();
		RUN_TEST(test_get_piece);
		RUN_TEST(test_get_current_player);
		RUN_TEST(test_set_board);
		RUN_TEST(test_get_valid_rook_moves);
		return UNITY_END();
}

