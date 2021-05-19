#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(City c)
{
    if ((!Board::is_connected(c_location, c) && c!=c_location)||(board.get_cube(c) == 0) )
    {
        throw invalid_argument{"No cubes in the selected city"};
    }
    if (board.is_discover_cure(Board::get_color(c)))
    {
        board.clean_cube(c);
    }
    else
    {
        board.decrease_cube(c);
    }
    return *this;
}


