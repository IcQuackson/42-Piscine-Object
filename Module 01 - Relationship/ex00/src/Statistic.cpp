#include "Statistic.hpp"

Statistic::Statistic(int level, int exp) : level(level), exp(exp)
{
}

Statistic::Statistic() : level(1), exp(0)
{
}

int Statistic::getLevel() const
{
    return this->level;
}

int  Statistic::getExp() const
{
    return this->exp;
}

void  Statistic::setLevel(int level)
{
    this->level = level;
}

void  Statistic::setExp(int exp)
{
    this->exp = exp;
}