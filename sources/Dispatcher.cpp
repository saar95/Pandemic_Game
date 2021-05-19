#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (c == c_location)
    {
        throw invalid_argument{"Please enter diffrent cities"};
    }
    if (board.is_research(c_location))
    {
        c_location = c;
    }
    else if (city_cards.count(c)!=0)
    {
        c_location = c;
        city_cards.erase(c);
    }
    else
    {
        throw invalid_argument{"You dont have the right card"};
    }
    return *this;
}