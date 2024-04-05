#include <iostream>
#include "string.h"


int main() {
    std::string str = "helloworld";
    String obj(str);
    std::cout << obj[0] << std::endl;
}