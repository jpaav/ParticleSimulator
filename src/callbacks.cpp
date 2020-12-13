//
// Created by Joseph Paavola on 12/13/20.
//

#include "callbacks.h"
#include <iostream>

void error_callback(int code, const char* description)
{
    std::cerr << "ERROR (" << code << "): " << description << std::endl;
}