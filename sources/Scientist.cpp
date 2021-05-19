#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{
    int cards_owned = 0;
    if (board.is_discover_cure(c))
    {
        return *this;
    }

    if (board.is_research(c_location))
    {
        
        for (const auto &temp : city_cards)
        {
            if (Board::get_color(temp) == c)
            {
                cards_owned++;
            }
            if (cards_owned == n)
            {
                break;
            }
        }
        if (cards_owned == n)
        {
            cards_owned = 0;
            for (auto temp = city_cards.begin(); temp != city_cards.end() || cards_owned < n; cards_owned++)
            {
                if (Board::get_color(*temp) == c)
                {
                    temp = city_cards.erase(temp);
                }
                else
                {
                    ++temp;
                }
            }
            board.cure(c);
        }
        else
        {
            throw invalid_argument{"You dont have the right card"};
        }
    }
    else
    {

        throw invalid_argument{"To use this you must have research stations in the selected cities"};
    }
    return *this;
}