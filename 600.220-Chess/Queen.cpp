#include "Queen.h"
#include <iostream>
#include <vector>

namespace Chess
{
    bool Queen::legal_move_shape(const Position& start, const Position& end) const {
        // Start and end location must be different
        if (start.first == end.first && start.second == end.second) {
            return false;
        }

        // Start and end location must be on the same row, column, or diagonal
        if (start.first != end.first && start.second != end.second && abs(start.first - end.first) != abs(start.second - end.second)) {
            return false;
        }

        return true;
    }
}