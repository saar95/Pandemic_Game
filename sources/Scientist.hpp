  
#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

    class Scientist: public Player {
        int n;

        public:
            Scientist(Board& board, City c, int num): Player(board, c, "Scientist"), n(num) {}
            Player &discover_cure(Color c) override;
    };    
}

  
