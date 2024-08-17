
#include "Shovel.hpp"
#include "Tool.hpp"

Shovel::Shovel()
{
    this->numberOfUses = 0;
    this->owner = NULL;
    this->type = "Shovel";
}

void Shovel::use()
{
    this->numberOfUses++;
    std::cout << "Shovel used " << this->numberOfUses << " times" << std::endl;
}

Shovel::~Shovel()
{
}

std::ostream &operator<<(std::ostream &os, const Shovel &shovel)
{
    os << "Shovel used " << shovel.numberOfUses << " times";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Shovel *shovel)
{
    if (shovel == NULL)
    {
        os << "Shovel used 0 times";
        return os;
    }
    os << "Shovel used " << shovel->numberOfUses << " times";
    return os;
}