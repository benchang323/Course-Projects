#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

namespace Chess
{
	class Knight : public Piece {

	public:
    	bool legal_move_shape(const Position& start, const Position& end) const override;

		/* DO NOT MODIFY */
		char to_ascii() const override { return is_white() ? 'N' : 'n';	}

		int point_value() const override { return 3; }
    
		/* DO NOT MODIFY */
		std::string to_unicode() const override { return is_white() ? "\u2658" : "\u265E"; }

	private:
		/* DO NOT MODIFY */
		Knight(bool is_white) : Piece(is_white) {}

		friend Piece* create_piece(const char& piece_designator);
	};
}

#endif // KNIGHT_H
