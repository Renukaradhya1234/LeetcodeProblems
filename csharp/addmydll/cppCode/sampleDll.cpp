// example.cpp
#include <iostream>

extern "C" {
    __declspec(dllexport) void PrintNumber() {
        for(int num = 0; num < 10; num++ )
		{
			std::cout << num << std::endl;
		}
    }
}
