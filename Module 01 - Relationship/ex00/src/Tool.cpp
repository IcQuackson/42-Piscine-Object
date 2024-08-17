#include "Tool.hpp"

Tool::Tool()
{
    this->numberOfUses = 0;
    this->owner = NULL;
}

Tool::~Tool()
{
}

Worker *Tool::getOwner() const
{
    return this->owner;
}

void Tool::setOwner(Worker *owner)
{
    this->owner = owner;
}

void Tool::removeOwner()
{
    this->owner = NULL;
}

int Tool::getNumberOfUses() const
{
    return this->numberOfUses;
}

std::string Tool::getType() const
{
    return this->type;
}