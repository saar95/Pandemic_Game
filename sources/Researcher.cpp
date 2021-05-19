#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int city_cards_limit = 5;

Player &Researcher::discover_cure(Color c)
{
    int cards_owned = 0;
    if (board.is_discover_cure(c))
    {
        return *this;
    }
    
    for (const auto &temp : city_cards)
    {
        if (Board::get_color(temp) == c)
        {
            cards_owned++;
        }
        if (cards_owned == city_cards_limit)
        {
            break;
        }
    }
    if (cards_owned == city_cards_limit)
    {
        cards_owned = 0;
        for (auto temp = city_cards.begin(); temp != city_cards.end() || cards_owned < city_cards_limit; cards_owned++)
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
    return *this;
}

