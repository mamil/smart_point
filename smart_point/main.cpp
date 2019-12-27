#include "smart_point.h"

#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>

void test()
{
    int* temp = new int{ 5 };
    //delete temp;
    rstd::smart_ptr<int> num{ temp };
}

int main()
{
    test();

    _CrtDumpMemoryLeaks(); // check memory leaks
    return 0;
}
