#include "Medic.hpp"
#include "Board.hpp"

using namespace std;
using namespace pandemic;

Player& Medic::treat(City c)
{
    if (board.get_cube(c) == 0)
    {
        throw invalid_argument{"No cubes in the selected city"};
    }
    if (c_location != c)
    {
        throw invalid_argument{"You are not in the selected city"};
    }
    board.clean_cube(c);
    return *this;
}


Player& Medic::fly_direct(City c)
{
    if (c == c_location)
    {
        throw invalid_argument{"Please enter diffrent cities"};
    }
    if (city_cards.count(c)!=0)
    {
        c_location = c;
        city_cards.erase(c);
        
        if (board.is_discover_cure(Board::get_color(c)))
        {
            board.clean_cube(c);
        }
    }
    else
    {
        throw invalid_argument{"You dont have the right card"};
    }
    return *this;
}

Player& Medic::fly_charter(City c)
{
    if (c == c_location)
    {
        throw invalid_argument{"Please enter diffrent cities"};
    }
    if (city_cards.count(c_location)!=0)
    {
        c_location = c;
        city_cards.erase(c_location);
        if (board.is_discover_cure(Board::get_color(c)))
        {
            board.clean_cube(c);
        }
    }
    else
    {
        throw invalid_argument{"You dont have the right card"};
    }
    return *this;
}

Player& Medic::fly_shuttle(City c)
{
    if (c == c_location)
    {
        throw invalid_argument{"Please enter diffrent cities"};
    }
    if (board.is_research(c_location) && board.is_research(c) )
    {
        c_location = c;
        if (board.is_discover_cure(Board::get_color(c)))
        {
            board.clean_cube(c);
        }
    }
    else
    {
        throw invalid_argument{"To use this you must have research stations in the selected cities"};
    }
    return *this;
}

Player& Medic::drive(City c)
{
    if (c == c_location)
    {
        throw invalid_argument{"Please enter diffrent cities"};
    }
    if (Board::is_connected(c_location, c))
    {
        c_location = c;
        if (board.is_discover_cure(Board::get_color(c)))
        {
            board.clean_cube(c);
        }
    }
    else
    {
        throw invalid_argument{"There in no way to move between this cities"};
    }
    return *this;
}