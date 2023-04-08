#include <iostream>
#include "ConverterJSON.h"

int main()
{
    std::cout << "Search Engine is under development." << std::endl;
    auto* converter = new ConverterJSON();
    std::cout << converter->getProgramName() << "" << std::endl;
    std::cout << "Version: " << converter->getProgramVersion() << "" << std::endl;
    delete converter;
    converter = nullptr;
    return 0;
}
