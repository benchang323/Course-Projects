#include "Knight.h"

namespace Chess
{
  bool Knight::legal_move_shape(const Position& start, const Position& end) const {
    // Start and end location must be different
    if (start.first == end.first && start.second == end.second) {
      return false;
    }

    // Start and end location must be in a L shape
    // Left/right then up/down
    if (abs(start.first - end.first) == 2 && abs(start.second - end.second) == 1) {
      return true;
    }
    // Up/down then left/right
    else if (abs(start.first - end.first) == 1 && abs(start.second - end.second) == 2) {
      return true;
    }

    return false;
  }
}