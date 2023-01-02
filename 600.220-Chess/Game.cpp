#include <cassert>
#include "Game.h"

namespace Chess
{
	/* DO NOT MODIFY */
	Game::Game() : is_white_turn(true) {
		// Add the pawns
		for (int i = 0; i < 8; i++) {
			board.add_piece(Position('A' + i, '1' + 1), 'P');
			board.add_piece(Position('A' + i, '1' + 6), 'p');
		}

		// Add the rooks
		board.add_piece(Position( 'A'+0 , '1'+0 ) , 'R' );
		board.add_piece(Position( 'A'+7 , '1'+0 ) , 'R' );
		board.add_piece(Position( 'A'+0 , '1'+7 ) , 'r' );
		board.add_piece(Position( 'A'+7 , '1'+7 ) , 'r' );

		// Add the knights
		board.add_piece(Position( 'A'+1 , '1'+0 ) , 'N' );
		board.add_piece(Position( 'A'+6 , '1'+0 ) , 'N' );
		board.add_piece(Position( 'A'+1 , '1'+7 ) , 'n' );
		board.add_piece(Position( 'A'+6 , '1'+7 ) , 'n' );

		// Add the bishops
		board.add_piece(Position( 'A'+2 , '1'+0 ) , 'B' );
		board.add_piece(Position( 'A'+5 , '1'+0 ) , 'B' );
		board.add_piece(Position( 'A'+2 , '1'+7 ) , 'b' );
		board.add_piece(Position( 'A'+5 , '1'+7 ) , 'b' );

		// Add the kings and queens
		board.add_piece(Position( 'A'+3 , '1'+0 ) , 'Q' );
		board.add_piece(Position( 'A'+4 , '1'+0 ) , 'K' );
		board.add_piece(Position( 'A'+3 , '1'+7 ) , 'q' );
		board.add_piece(Position( 'A'+4 , '1'+7 ) , 'k' );
	}

	// Copy constructor
	Game::Game(const Game* original) {
		for(int i = 'A'; i<='H'; i++) {
			for(int j = '1'; j<= '8'; j++) {
				if((original->board(Position(i,j))) != NULL) {
					const Piece* added_piece = original->board(Position(i,j));
					char character = (*added_piece).to_ascii();
					board.add_piece(Position(i, j), character);
				}
			}
		}
	}

	// Rewriting and simplifying the make_move function
	void Game::make_move(const Position& start, const Position& end) {
		// Get piece at start location
		const Piece* mvp = board(start);
		
		// Check if there is a piece at the start location
		if(mvp == NULL){
			throw Exception("no piece at start position");
		}
		//check that start and end positions are on the board
		if((start.first < 'A' || start.first > 'H') || (start.second < '1' || start.second > '8')){
			throw Exception("start position is not on board");
		}
		if((end.first < 'A' || end.first > 'H') || (end.second < '1' || end.second > '8')){
			throw Exception("end position is not on board");
		}

		// Check color
		if (mvp->is_white() == is_white_turn) {
			// Check if the move is legalgit
			if (mvp->legal_move_shape(start, end) || (mvp->legal_capture_shape(start, end) && board(end) != NULL && board(end)->is_white() != is_white_turn)) {
				// Check if the path is clear
				// Set the direction of the path
				int x_dir = end.first - start.first;
				int y_dir = end.second - start.second;
				int x_sign = 1;
				int y_sign = 1;
				// Direction
				if (x_dir < 0) {
					x_sign = -1;
				}
				if (y_dir < 0) {
					y_sign = -1;
				}
				int straight_x = 1;
				int straight_y = 1;
				if (y_dir == 0) {
					straight_y = 0;
				}
				if (x_dir == 0) {
					straight_x = 0;
				}
				// Magnitude
				x_dir = abs(x_dir);
				y_dir = abs(y_dir);

				// Knight can jump through pieces
				if ((mvp->to_ascii() != 'N' && mvp->to_ascii() != 'n') && (mvp->to_ascii() != 'P' && mvp->to_ascii() != 'p')) {
					for (int i = 1; i < x_dir; i++) {
						// Check if path is clear
						if (board(Position(start.first + i * x_sign * straight_x, start.second + i * y_sign * straight_y)) != NULL) {
							throw Exception("path is not clear");
						}
					}
					for (int i = 1; i < y_dir; i++) {
						// Check if path is clear
						if (board(Position(start.first + i * x_sign * straight_x, start.second + i * y_sign * straight_y)) != NULL) {
							throw Exception("path is not clear");
						}
					}
				}
				// Pawn can only move forward if nothing is in front of it, and can only capture diagonally
				else if (mvp->to_ascii() == 'P' || mvp->to_ascii() == 'p') {
					// Check if the pawn is moving forward
					if (board(end) == NULL) {
						if (x_dir != 0) {
							throw Exception("illegal move shape");
						}
					}
					else {
						if (x_dir != 1) {
							throw Exception("illegal capture shape");
						}
					}
					// If there is anything blocking pawn at initial step, it cannot move forward too
					if (start.second == '2' || start.second == '7') {
						if (board(Position(start.first, start.second + y_sign)) != NULL) {
							throw Exception("path is not clear");
						}
					}
				}

				// Check if the end location is occupied by a piece of the same color
				if (board(end) != NULL) {
					if (board(end)->is_white() == mvp->is_white()) {
						throw Exception("cannot capture own piece");
					}
				}
				// See if piece moves into check
				// Do it without memoery leaks
				Game temp_game = Game(this); 
				temp_game.board.add_piece(end, mvp->to_ascii());
				temp_game.board.delete_piece(start);
				if(temp_game.in_check(is_white_turn)){
					throw Exception("move exposes check");
				}
				//piece promotion of Pawn
				char piece_designator;
				if ((mvp->is_white() && (end.second == '8')) || (!mvp->is_white() && (end.second == '1'))) {
					piece_designator = turn_white() ? 'Q' : 'q';
				} 
				else {
					piece_designator = mvp->to_ascii();
				}

				// Move the piece
				board.add_piece(end, piece_designator);
				board.delete_piece(start);
				// Change the turn
				is_white_turn = !is_white_turn;
			}	
			else {
				throw Exception("illegal move shape");
			}
		}
		else {
			throw Exception("piece color and turn do not match");
		}
	}

	// Returns true if the designated player is in check
	bool Game::in_check(const bool& white) const {
		// Loop through every piece on the board to find the king
		for (char i = 'A'; i <= 'H'; i++) {
			for (char j = '1'; j <= '8'; j++) {
				// Create a position object for the current position
				Chess::Position pos;
				pos.first = i;
				pos.second = j;
				// Control flow to check if the piece is the king
				if ((board(pos) != NULL) && (board(pos)->is_white() != white)) {
					// Check every possible move for the king
					for (char k = 'A'; k <= 'H'; k++) {
						for (char l = '1'; l <= '8'; l++) {
							// Create a position object for the current position
							Chess::Position temp_pos;
							temp_pos.first = k;
							temp_pos.second = l;
							// Check if the other piece can capture the king
							if (board(pos)->legal_capture_shape(pos, temp_pos)) {
								bool clear = true;
								if ((board(pos)->to_ascii() != 'N' && board(pos)->to_ascii() != 'n') && (board(pos)->to_ascii() != 'P' && board(pos)->to_ascii() != 'p')) {	
								// Check if the path is clear
								int x_dir = temp_pos.first - pos.first;
								int y_dir = temp_pos.second - pos.second;
								int x_sign = 1;
								int y_sign = 1;
								if (x_dir < 0) {
									x_sign = -1;
								}
								if (y_dir < 0) {
									y_sign = -1;
								}
								int straight_x = 1;
								int straight_y = 1;
								if (y_dir == 0) {
									straight_y = 0; //don't need to change anything here	
								}
								if (x_dir == 0) {
									straight_x = 0;
								}
								x_dir = abs(x_dir);
								y_dir = abs(y_dir);
								// Check if path is clear
								for (int i = 1; i < x_dir; i++) {
									// Check if path is clear
									if (board(Position(pos.first + i * x_sign * straight_x, pos.second + i * y_sign * straight_y)) != NULL) {
										clear = false;
									}
								}
								// Check if path is clear
								for (int i = 1; i < y_dir; i++) {
									// Check if path is clear
									if (board(Position(pos.first + i * x_sign * straight_x, pos.second + i * y_sign * straight_y)) != NULL) {
										clear = false;
									}
								}
								}
								if (clear) {
									// Check if the move captures the king
									if (board(temp_pos) != NULL) {
										if (board(temp_pos)->is_white() == white) {
											// Check if the piece is a king
											if ((board(temp_pos)->to_ascii() == 'K') || (board(temp_pos)->to_ascii() == 'k')) {
												return true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return false;	
	}

	// Returns true if the designated player is in checkmate
	bool Game::in_mate(const bool& white) const {
		// Check if the player is in check
		if (in_check(white)) {
			// Check if any piece can capture the king
			for (char i = 'A'; i <= 'H'; i++) {
				for (char j = '1'; j <= '8'; j++) {
					Chess::Position pos;
					pos.first = i;
					pos.second = j;
					// Check for both white and black pieces
					if ((board(pos) != NULL) && (board(pos)->is_white() == white)) {
						// Check every possible move
						for (char k = 'A'; k <= 'H'; k++) {
							for (char l = '1'; l <= '8'; l++) {
								// Check if the move is legal
								Chess::Position pos2;
								pos2.first = k;
								pos2.second = l;
								Game temp_game = Game(this);
								temp_game.is_white_turn = white;
								//test if the piece can move anywhere on the board
								try {
									if (board(pos)->legal_move_shape(pos, pos2)) {
										temp_game.make_move(pos, pos2);
									}
								}
								catch (Exception& e) {
									// Do nothing (invalid move results in no change)

								} //test if game is still in check after move
								if ((board(pos)->legal_move_shape(pos, pos2))) {
									if (!temp_game.in_check(white)) {
										return false;
									}

								}

							}
						}
					}
				}
			}
			return true;
		}
		// If not in check, then not in checkmate
		else {
			return false;
		}
		return false;
	}

	// Stalemate means no players can make a legal move
	bool Game::in_stalemate(const bool& white) const {
		//stalemate fct is the same as in_mate except for the initial test if it's currently in check
		for (char i = 'A'; i <= 'H'; i++) {
			for (char j = '1'; j <= '8'; j++) {
				Chess::Position pos;
				pos.first = i;
				pos.second = j;
				// Check for both white and black pieces
				if ((board(pos) != NULL) && (board(pos)->is_white() == white)) {
					// Check every possible move
					for (char k = 'A'; k <= 'H'; k++) {
						for (char l = '1'; l <= '8'; l++) {
							// Create a temporary game to test the move
							Chess::Position pos2;
							pos2.first = k;
							pos2.second = l;
							Game temp_game = Game(this);
							temp_game.is_white_turn = white;
							bool move_blocked = false;
							// Check if the move is legal
							try {
								if(board(pos)->legal_move_shape(pos, pos2)){
									temp_game.make_move(pos,pos2);
								}	
							}
							catch (Exception& e) {
								// invalid move means no pieces move, so the moving team won't be in check
								move_blocked = true;
							}
							//move has to have worked with no exceptions and not be in check
							if(board(pos)->legal_move_shape(pos, pos2)&&(move_blocked == false)){
								if (!temp_game.in_check(white)) {
										// Undo the move
										//board(pos)->legal_move_shape(pos2, pos);
										return false;
								}
							}
						}
					}
				}
			}
		}
		
		return true;
	}

    // Return the total material point value of the designated player
    int Game::point_value(const bool& white) const {
		int total = 0;
		// Loop through the board and add up the point values of all the pieces
		for (char i = 'A'; i <= 'H'; i++) {
			for (char j = '1'; j <= '8'; j++) {
				// Check for the pieces
				Chess::Position pos;
				pos.first = i;
				pos.second = j;
				// Color is the same as the designated player
				if ((board(pos) != NULL) && (board(pos)->is_white() == white)) {
					total += board(pos)->point_value();
				}
			}
		}
		return total;
    }

    std::istream& operator>> (std::istream& is, Game& game) {
		//delete all the things in the board to have a new set
		game.board.delete_all();
		//add the game piece in the board if it is a new one
		for(int row = '8'; row >= '1'; row--){
			for(int col = 'A'; col <= 'I'; col++){
				std::pair<char, char> position;
				char piece_designator = is.get();
				position.first = col;
      			position.second = row;
      			game.board.add_piece(position, piece_designator);	
			}
		}
		//the designator's turn of the final char
		char turn_designator = is.get();
		if(turn_designator == 'w'){
    		game.is_white_turn = true;
  		}
  		else if(turn_designator == 'b'){
			game.is_white_turn = false;
  		}
		//if not w and b, throw the expection
		else{
			throw Exception();
		}
		return is;
	}

    /* DO NOT MODIFY */
	std::ostream& operator<< (std::ostream& os, const Game& game) {
		// Write the board out and then either the character 'w' or the character 'b',
		// depending on whose turn it is
		return os << game.board << (game.turn_white() ? 'w' : 'b');
	}
}