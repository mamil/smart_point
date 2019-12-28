#include "smart_point.h"

#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#include <iostream>

void test()
{
    int* temp = new int{ 42 };
    //delete temp;
    rstd::smart_ptr<int> num{ temp };

    if (num)
        std::cout << *num << std::endl;

    //**** copy
    rstd::smart_ptr<int> num1(std::move(num));
    if (num)
    {
        std::cout << *num << std::endl;
    }
    else
    {
        std::cout << "num is empty" << std::endl;
    }
    if (num1)
    {
        std::cout << *num1 << std::endl;
    }
    else
    {
        std::cout << "num1 is empty" << std::endl;
    }

    // num = num1; // can't do this anymore
    num = std::move(num1);
    if (num)
    {
        std::cout << *num << std::endl;
    }
    else
    {
        std::cout << "num is empty" << std::endl;
    }
    if (num1)
    {
        std::cout << *num1 << std::endl;
    }
    else
    {
        std::cout << "num1 is empty" << std::endl;
    }
}

int main()
{
    test();

    _CrtDumpMemoryLeaks(); // check memory leaks
    return 0;
}
