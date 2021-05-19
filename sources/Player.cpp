#include "Player.hpp"
using namespace std;
const int cards_limit = 5;

using namespace pandemic;

        Player& Player::take_card(City c)
    {
        city_cards.insert(c);
        return *this;
    }
    Player& Player::remove_cards()
    {
        city_cards.clear();
        return *this;
    }

    Player& Player::fly_direct(City c)
    {
        if (c_location == c)
        {
            throw invalid_argument{"Please enter diffrent cities"};
        }
        if ((bool)city_cards.count(c))
        {
            city_cards.erase(c);
            c_location = c;
        }
        else
        {
            throw invalid_argument{"You dont have the right card"};
        }
        return *this;
    }

       Player& Player::fly_shuttle(City c)
    {
        if (c_location == c)
        {
            throw invalid_argument{"Please enter diffrent cities"};
        }
        if (!board.is_research(c_location) || !board.is_research(c))
        {
            throw invalid_argument{"To use this you must have research stations in the selected cities"};
        }
        c_location = c;
        return *this;
    }

    Player& Player::fly_charter(City c)
    {
        if (c_location == c)
        {
            throw invalid_argument{"Please enter diffrent cities"};
        }
        if ((bool)city_cards.count(c_location))
        {
            city_cards.erase(c_location);
            c_location = c;
        }
        else
        {
            throw invalid_argument{"You dont have the right card"};
        }
        return *this;
    }

 

    Player& Player::treat(City c)
    {
        if (board.get_cube(c) == 0)
        {
            throw invalid_argument{"No cubes in the selected city"};
        }
        if (c != c_location)
        {
            throw invalid_argument{"You are not in the selected city"};
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

    

    Player& Player::discover_cure(Color c)
    {
        if (board.is_discover_cure(c))
        {
            return *this;
        }
        if (board.is_research(c_location))
        {
            int cards_owned = 0;
            for (const auto &temp : city_cards)
            {
                if (Board::get_color(temp) == c)
                {
                    cards_owned++;
                }
                if (cards_owned == cards_limit)
                {
                    break;
                }
            }
            if (cards_owned == cards_limit)
            {
                cards_owned = 0;
                for (auto temp = city_cards.begin(); temp != city_cards.end() || cards_owned < cards_limit; cards_owned++)
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

    Player& Player::build()
    {
        if (board.is_research(c_location))
        {
            return *this;
        }
        if ((bool)city_cards.count(c_location))
        {
            city_cards.erase(c_location);
            board.build(c_location);
        }

        else
        {
            throw invalid_argument{"You dont have the right card"};
        }
        return *this;
    }

    Player& Player::drive(City c)
    {
        if (c_location == c)
        {
            throw invalid_argument{"Please enter diffrent cities"};
        }
        if (Board::is_connected(c_location, c))
        {
            c_location = c;
        }
        else
        {
            throw invalid_argument{"There in no way to move between this cities"};
        }
        return *this;
    }
