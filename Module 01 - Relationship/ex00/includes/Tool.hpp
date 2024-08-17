
#pragma once

#include "Worker.hpp"
#include <iostream>

class Worker;

class Tool
{
protected:
    Tool();
    int numberOfUses;
    Worker *owner;
    std::string type;

public:
    virtual ~Tool();
    virtual void use() = 0;
    virtual std::string getType() const;
    Worker *getOwner() const;
    int getNumberOfUses() const;
    void setOwner(Worker *owner);
    void removeOwner();
};