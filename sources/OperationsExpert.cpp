#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
    if (!board.is_research(c_location))
    {
        board.build(c_location);
    }
    return *this;
}