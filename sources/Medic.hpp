#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player{

        public:
            Medic(Board& board, City c): Player(board, c, "Medic") {}
            Player& treat(City c) override;
            Player & drive(City c) override;
            Player & fly_direct(City c) override;
            Player & fly_charter(City c) override;
            Player & fly_shuttle(City c) override;
    };
}