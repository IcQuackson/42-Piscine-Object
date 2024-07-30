#include "Hammer.hpp"

Hammer::Hammer()
{
    this->numberOfUses = 0;
    this->owner = NULL;
}

void Hammer::use()
{
    this->numberOfUses++;
    std::cout << "Hammer used " << this->numberOfUses << " times" << std::endl;
}

Hammer::~Hammer()
{
}

std::ostream &operator<<(std::ostream &os, const Hammer &hammer)
{
    os << "Hammer used " << hammer.numberOfUses << " times";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Hammer *hammer)
{
    if (hammer == NULL)
    {
        os << "Hammer used 0 times";
        return os;
    }
    os << "Hammer used " << hammer->numberOfUses << " times";
    return os;
}