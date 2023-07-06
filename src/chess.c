#include "chess.h"
#include <string.h>

/**
 * The chess game instance
 */
ChessGame game;

 /**
 * This function initializes the game.
 * - The board is set to the initial state
 * - The move cound is set to 0
 */
void init_game()
{
	// Set the board to the initial state
	char initialBoard[8][8] = {
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
	};

	// Copy the initial board to the game board
	memcpy(game.board, initialBoard, sizeof(initialBoard));

	// Set the moves count to 0
	game.moves_count = 0;
}

/**
 * This function returns a piece at a given position
 * - The position is given by a string, e.g. "a1"
 * @param position The position of the piece
 */
char get_piece(char* position)
{
	int x = position[0] - 'a';
	int y = position[1] - '1';
	return game.board[y][x];
}

/**
 * This function gets the current player
 */
char get_current_player()
{
	return game.moves_count % 2 == 0 ? WHITE : BLACK;
}

/**
 * This function returns the color of a given piece
 * @param piece The piece to get the color of
 */
char get_piece_color(char piece)
{
	if ('a' <= piece && piece <= 'z')
		return BLACK;
	else if ('A' <= piece && piece <= 'Z')
		return WHITE;
	else
		return ' ';
}

 /**
 * This function sets the board at a given state
 * - The board is given an 8x8 array of characters
 * @param board The board to set
 */
void set_board(char board[8][8])
{
	memcpy(game.board, board, sizeof(char) * 8 * 8);
}

/**
 * This function returns valid rook moves for a given position
 */
char** get_valid_rook_moves(char* position, char color)
{
	// Define the valid moves array
	char valid_moves[27][4];
	unsigned int valid_moves_count = 0;

	// Convert the position to x and y
	int x = position[0] - 'a';
	int y = position[1] - '1';

	//
}

/**
 * This function returns all the valid moves for a given piece
 * - The position is given by a string, e.g. "a1"
 * @param position The position of the piece
 */
char** get_valid_moves(char* position)
{
	// Get the piece at the given position
	char piece = get_piece(position);
	
	// If the piece is empty, return NULL
	if (piece == ' ')
		return NULL;
	
	// Get current player
	char player = get_current_player();

	// Get the piece color
	char color = get_piece_color(piece);

	// If the piece color is not the same as the current player, return NULL
	if (color != player)
		return NULL;

	// Get the valid moves for the piece
}
