#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
        std::map<City, int> sick_level;
        std::set<City> res_station;
        std::set<Color> cured;
        std::map<City,Color> cities_color;

    public:
        Board() {}
        void build(City c);
        void remove_cures();
        void remove_stations();
        bool is_clean();
        static bool is_connected(City &c1, City &c2);
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        bool is_research(City c);
        void cure(Color c);
        int get_cube(City c);
        void decrease_cube(City c);
        void clean_cube(City c);
        static Color get_color(City c);
        int get_near_cities(City c);
        bool is_discover_cure(Color c);
    };

}
