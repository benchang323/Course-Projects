#include "Bishop.h"

namespace Chess
{
  bool Bishop::legal_move_shape(const Position& start, const Position& end) const {
    // Start and end location must be different
    if (start.first == end.first && start.second == end.second) {
      return false;
    }
    
    // Start and end location must be on the same diagonal
    if (abs(start.first - end.first) != abs(start.second - end.second)) {
      return false;
    }

    return true;
  }
}