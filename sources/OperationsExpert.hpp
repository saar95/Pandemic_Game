#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class OperationsExpert: public Player {

        public:
            OperationsExpert(Board& board, City c): Player(board, c, "OperationsExpert") {}
            Player& build() override;
    };

}