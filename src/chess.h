#ifndef CHESS_H
#define CHESS_H

#define WHITE 0
#define BLACK 1

/**
 * The Game struct
 * This struct contains all the information of the game.
 * - The board consists of an 8x8 array of array of chars
 * - The moves consisting of an array of chars
 * - The moves count is the number of moves in the moves array
 */
typedef struct {
		char board[8][8];	// 8x8 board
		char moves[1000][4];	// 1000 moves, 4 chars per move
		unsigned int moves_count;	// number of moves
} ChessGame;

/**
 * The instance of the game
 */
extern ChessGame game;

/**
 * This function initializes the game.
 * - The board is set to the initial state
 * - The moves are set to an empty string
 */	
void init_game();

/**
 * This function returns the piece at the given position.
 * - The position is given as a string of two chars, e.g. "e2"
 */
char get_piece(char* position);
	
/**
 * This function returns the current player.
 * - The current player is either WHITE or BLACK
 */	
char get_current_player();

/**
 * This function sets the board to the given state.
 * - The board is given an 8x8 array of chars
 */
void set_board(char board[8][8]);

/**
 * This function returns the valid moves for the given piece.
 * - The position is given as a string of two chars, e.g. "e2"
 * - The moves are returned as an array of strings of moves, e.g. ["e4e5", "e4e6"]
 */
char** get_valid_moves(char* position);

#endif // CHESS_H
