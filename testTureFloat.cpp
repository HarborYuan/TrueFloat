#include <iostream>
#include "TrueFloat.hpp"

int main()
{
    double a = -0.323123;
    truef32 ans(a);
    std::cout<<ans<<std::endl;
    return 0;
}