#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class GeneSplicer: public Player {

        public:
            GeneSplicer(Board& board, City c): Player(board, c, "GeneSplicer") {}
            Player& discover_cure(Color c) override;
    };
    
}