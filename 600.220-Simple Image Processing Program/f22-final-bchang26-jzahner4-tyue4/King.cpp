#include "King.h"

namespace Chess
{
  bool King::legal_move_shape(const Position& start, const Position& end) const {
    // Start and end location must be different
    if (start.first == end.first && start.second == end.second) {
      return false;
    }

    // Start and end location must be one square away in any direction
    if (abs(start.first - end.first) > 1 || abs(start.second - end.second) > 1) {
      return false;
    }

    return true;
  }
}