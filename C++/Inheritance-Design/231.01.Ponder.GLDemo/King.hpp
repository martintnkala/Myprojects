//
//  King.hpp
//  Lab01
//
//  Created by Martin Nkala on 4/22/23.
//

#ifndef King_hpp
#define King_hpp
#include "Piece.hpp"

class King: public Piece
{
public:
   void draw(int position, bool black) override;
};

#endif /* King_hpp */
