#include <iostream>
#include "Network.hpp"
int main(int argc, char const *argv[])
{
    Network N(2, 1);
    N.addLayer(10);
    N.inputs({1,0});
    N.expected({1});
    N.processData();
    N.printActual();
    return 0;
}

// x  
// x
// x
// x