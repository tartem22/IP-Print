#include <string>
#include <vector>
#include <list>
#include <tuple>

#include <iostream>

#include "ip_print.h"

int main()
{
    int ip_int = 124356;
    printIP(ip_int);
    char ip_char = -1;
    printIP(ip_char);
    short ip_short = 0;
    printIP(ip_short);
    long ip_long = 8875824491850138409;
    printIP(ip_long);

    std::string ip_str = "169.254.0.1";
    printIP(ip_str);

    std::vector<int> v = {134, 256, 5, 7};
    printIP(v);
    std::list<int> l = {234, 567, 890, 1};
    printIP(l);  

    // std::tuple<int, int, int, int> ip_tuple(128,64,32,16);
    // printIP(ip_tuple);

}