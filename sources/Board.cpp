#include <map>
#include <set>
#include <iostream>
#include <string>

#include "Board.hpp"
using namespace std;
using namespace pandemic;

void Board::remove_cures()
{
    cured.clear();
}

void Board::remove_stations()
{
    res_station.clear();
}



void Board::build(City c)
{
    res_station.insert(c);
}

bool Board::is_research(City c)
{
    bool ans=false;
    if(res_station.count(c)!=0){
        ans=true;
    }
    return ans;
}

std::ostream &pandemic::operator<<(std::ostream &os, const Board &board)
{
    return os;
}

bool Board::is_clean()
{
    bool ans=true;
    for (auto &level : sick_level)
    {
        if (level.second > 0)
        {
            ans= false;
        }
    }
    return ans;
}

Color Board::get_color(City c)
{
    return city_color_map.at(c);
}

int Board::get_cube(City c)
{
    return sick_level.at(c);
}

void Board::decrease_cube(City c)
{
    if ((bool)sick_level.count(c))
    {
        sick_level.at(c) = sick_level.at(c)-1;
    }
}

int &Board::operator[](City c)
{
    return sick_level[c];
}

void Board::clean_cube(City c)
{
        sick_level.at(c) = 0;
}

void Board::cure(Color c)
{
    cured.insert(c);
}


bool Board::is_discover_cure(Color c)
{
    bool ans=false;
    if(cured.count(c)!=0){
        ans=true;
    }
    return ans;
}



static map<City, set<City>> cities_ways{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};


int get_near_cities(City c){
    return cities_ways.at(c).count(c);
}

bool Board::is_connected(City &c1, City &c2)
{
    bool ans=false;
    if(cities_ways.at(c1).count(c2)!=0){
        ans=true;
    }
    return ans;
}

