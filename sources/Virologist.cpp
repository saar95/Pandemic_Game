#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (board.get_cube(c) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (city_cards.count(c)==0 && c_location!=c)
    {
        throw invalid_argument{"Theres no match card"};
    }
    if (board.is_discover_cure(Board::get_color(c)))
    {       
         city_cards.erase(c);
        board.clean_cube(c);
    }
    else
    {
       
        city_cards.erase(c);
         board.decrease_cube(c);
    }
    return *this;
}