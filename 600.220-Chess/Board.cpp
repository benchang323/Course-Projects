#include "Piece.h"
#include <iostream>
#include <utility>
#include <map>
#ifndef _WIN32
#include "Terminal.h"
#endif // !_WIN32
#include "Board.h"
#include "CreatePiece.h"
#include "Exceptions.h"

namespace Chess
{
  /* DO NOT MODIFY */
  Board::Board(){}

  //Constructor
  Board::Board(const Board &board){
    for (std::map<Position, Piece*>::const_iterator cit = board.occ.cbegin(); cit != board.occ.cend(); ++ cit) {
      if (cit->second == nullptr) {
        occ[cit->first] = nullptr;
      }
      else {
        // Make copy of piece
        Piece *new_piece = create_piece(cit->second->to_ascii());
        occ[cit->first] = new_piece;
      }
    }
  }

  //Destructor
  Board::~Board() {
    // Loop through the map and delete all the pieces
    for (std::map<Position, Piece*>::iterator it = occ.begin(); it != occ.end(); ++it) {
      delete it->second;
    }
    occ.clear();
  }

  //return a const pointer or NULL by searching if the piece exists
  const Piece* Board::operator()(const Position& position) const {
    // Loop through the map and look for the position
    for (std::map<Position, Piece*>::const_iterator cit = occ.cbegin(); cit != occ.cend(); ++ cit) {
      if (cit->first == position) {
        return cit->second;
      }
    }
    return NULL;
  }

  // add a new piece with the specified designator with given position
  void Board::add_piece(const Position& position, const char& piece_designator) {
    // Control flow for different piece_designator cases
    if (piece_designator == '-') {
      occ[position] = NULL;
    }
    else if(piece_designator == '\n') {
      // Do nothing
    }
    else {
      // Create a new piece to add to the map if the position is not occupied
      Piece *new_piece = create_piece(piece_designator);
      
      if (new_piece == nullptr) {
        throw Exception("invalid designator");
      }
      if (position.first < 'A' ||position.first > 'H' || position.second < '1' || position.second > '8') {
        throw Exception("invalid position");
      }
      delete_piece(position);
      occ[position] = new_piece;
      
    }
  }

  //delete the piece if it is captured
  void Board::delete_piece(const Position& position){
    for (std::map<Position, Piece*>::iterator it = occ.begin(); it != occ.end(); ++it){
      if (it->first == position){
        delete it->second;
        occ.erase(it);
        break;
      }
    }
  }

  //delete all 
  void Board::delete_all(){
    for (std::map<Position, Piece*>::iterator it = occ.begin(); it != occ.end(); ++it) {
      delete it->second;
    }
    occ.clear();
}

  // Print out the whole board
  void Board::display() const {
    // Print column names
    std::cout << "  ";

    // Print column names
    for (char i = 'A'; i <= 'H'; i++) {
      Terminal::color_all(false, Terminal::WHITE, Terminal::RED);
      std::cout << i << " ";
    }
    Terminal::set_default();
    std::cout << std::endl;

    // Print rows and columns (pieces)
    int count = 0;
    // Loop through the rows
    for (int r = 8; r > 0; r--) {
      Terminal::color_all(false, Terminal::WHITE, Terminal::RED);
      std::cout << r << " ";
      // Loop through the columns
      for (char c = 'A'; c <= 'H'; c++) {
        count ++;
        // Alternate colors
        if((count + r) % 2 == 0) {
          Terminal::color_all(true, Terminal::BLACK, Terminal::GREEN);
        }
        else{
          Terminal::color_all(true, Terminal::BLACK, Terminal::YELLOW);
        }
        // Print the pieces
        Position p = Position(c, '0' + r);
        const Piece *piece = (*this)(p);
        if (piece == nullptr) {
          std::cout << "- ";
          Terminal::set_default();
        } else {
          std::cout << piece->to_ascii() << " ";
          Terminal::set_default();
        }
      }
      std::cout << std::endl;
    }
  }

  bool Board::has_valid_kings() const {
    int white_king_count = 0;
    int black_king_count = 0;

    // Loop through the map and count the number of kings
    for (std::map<std::pair<char, char>, Piece*>::const_iterator it = occ.begin(); it != occ.end(); it++) {
      // Check if the piece is a king
      if (it->second) {
        switch (it->second->to_ascii()) {
          // Color difference
          case 'K':
            white_king_count++;
            break;
          case 'k':
            black_king_count++;
            break;
          }
        }
      }
    
    return (white_king_count == 1) && (black_king_count == 1);
  }

/* DO NOT MODIFY */
std::ostream& operator<<(std::ostream& os, const Board& board) {
  for(char r = '8'; r >= '1'; r--) {
    for(char c = 'A'; c <= 'H'; c++) {
const Piece* piece = board(Position(c, r));
if (piece) {
  os << piece->to_ascii();
} else {
  os << '-';
}
    }
    os << std::endl;
  }
  return os;
}
}