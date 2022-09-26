#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list;

    list.insert(3, 1);

    std::cout << list.getSize() << std::endl;
}