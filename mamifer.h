#ifndef MAMIFER_H
#define MAMIFER_H

#include <animal.h>
#include <string.h>


class mamifer : public animal
{
    public:
        mamifer(){}
        mamifer(std::string price, int x):animal(price,x){}
        std::string Specie();

};

#endif // MAMIFER_H
