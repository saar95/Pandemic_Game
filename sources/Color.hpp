#pragma once
#include <map>

namespace pandemic
{

enum Color
{
    Black,Blue,Red,Yellow
};

    inline std::string colors_map(Color color) {

    switch (color){
        case Red: return "Red"; break;
        case Blue: return "Blue"; break;
        case Black: return "Black"; break;
        case Yellow: return "Yellow"; break;
    }
}
}