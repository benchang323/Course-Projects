#include "Pawn.h"

namespace Chess
{
    bool Pawn::legal_move_shape(const Position& start, const Position& end) const {
        // Start and end location must be different
        if (start.first == end.first && start.second == end.second) {
            return false;
        }

        // Initial move can be two spaces
        if (start.second == '2' && end.second == '4' && start.first == end.first && is_white()) {
            return true;
        }
        else if (start.second == '7' && end.second == '5' && start.first == end.first && !is_white()) {
            return true;
        }

        // Normal move is one space, cannot move backwards
        if (start.first == end.first && is_white() && end.second - start.second == 1) {
            return true;
        }
        else if (start.first == end.first && !is_white() && end.second - start.second == -1) {
            return true;
        }

        return false; 
    }

    bool Pawn::legal_capture_shape(const Position& start, const Position& end) const {
        // Start and end location must be different
        if (start.first == end.first && start.second == end.second) {
            return false;
        }

        // Capture is one space diagonally
        if (is_white() && end.second - start.second == 1 && abs(end.first - start.first) == 1) {
            return true;
        }
        else if (!is_white() && end.second - start.second == -1 && abs(end.first - start.first) == 1) {
            return true;
        }

        return false;
    }
}