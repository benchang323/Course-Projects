#include "Rook.h"
#include <iostream>

namespace Chess
{
  bool Rook::legal_move_shape(const Position& start, const Position& end) const {
    // Start and end location must be different
    if (start.first == end.first && start.second == end.second) {
      return false;
    }

    // Start and end location is on the same row
    if (start.first == end.first) {
      return true;
    }
    // Start and end location is on the same column
    else if (start.second == end.second) {
      return true;
    }

    return false;
  }
}