
#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int cards_limit = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    int cards_owned = 0;
    if (!board.is_research(c_location))
    {
        throw std::invalid_argument{"To use this you must have research stations in the selected cities"};
    }
    if (city_cards.size() >= cards_limit)
    {
        
        for (auto temp = city_cards.begin(); temp != city_cards.end() || cards_owned < cards_limit; cards_owned++)
        {
            temp = city_cards.erase(temp);
        }
        board.cure(c);
    }
    else
    {
        throw std::invalid_argument{"You dont have the right card"};
    }
    return *this;
}