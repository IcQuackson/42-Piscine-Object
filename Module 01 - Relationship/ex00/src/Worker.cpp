
#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker(Position position, Statistic statistic) : position(position), statistic(statistic)
{
}

Worker::Worker() : position(Position()), statistic(Statistic())
{
}

Worker::~Worker()
{
    // Remove the owner of all tools
    for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); ++it)
    {
        (*it)->removeOwner();
    }
}

Position Worker::getPosition() const
{
    return this->position;
}

Statistic Worker::getStatistic() const
{
    return this->statistic;
}

const std::vector<Tool *> Worker::getTools() const
{
    return this->tools;
}

const Tool *Worker::getTool(size_t index) const
{
    if (index < this->tools.size())
    {
        return this->tools[index];
    }
    return NULL;
}

const std::vector<IWorkshop *> Worker::getWorkshops() const
{
    return this->workshops;
}

void Worker::setPosition(Position position)
{
    this->position = position;
}

void Worker::setStatistic(Statistic statistic)
{
    this->statistic = statistic;
}

void Worker::addTool(Tool *tool)
{
    // If the tool is already owned by another worker, remove the owner
    if (tool)
    {
        if (tool->getOwner())
        {
            tool->getOwner()->removeTool(tool);
        }
        tool->removeOwner();
        tool->setOwner(this);
        this->tools.push_back(tool);
    }
}

void Worker::removeTool(Tool *tool)
{
    if (tool)
    {
        std::vector<Tool *>::iterator it = std::find(this->tools.begin(), this->tools.end(), tool);
        if (it != this->tools.end())
        {
            (*it)->removeOwner();
            this->tools.erase(it);
            // If the worker has a workshop and is no longer eligible, release the worker
            while (this->workshops.size() > 0 && !(*this->workshops.begin())->isWorkerEligible(this))
            {
                (*this->workshops.begin())->releaseWorker(this);
            }
        }
    }
}

void Worker::work() const
{
    std::cout << "Worker working" << std::endl;
}

void Worker::addWorkshop(IWorkshop *workshop)
{
    if (!workshop)
    {
        std::cout << "Workshop is null" << std::endl;
        return;
    }
    if (!workshop->isWorkerRegistered(this) || !workshop->isWorkerEligible(this))
    {
        std::cout << "Worker not eligible for workshop" << std::endl;
        return;
    }
    if (std::find(this->workshops.begin(), this->workshops.end(), workshop) != this->workshops.end())
    {
        std::cout << "Worker already registered in workshop" << std::endl;
        return;
    }
    else
    {
        std::cout << "Worker registered in workshop" << std::endl;
        this->workshops.push_back(workshop);
    }
}

void Worker::removeWorkshop(IWorkshop *workshop)
{
    if (workshop)
    {
        std::vector<IWorkshop *>::iterator it = std::find(this->workshops.begin(), this->workshops.end(), workshop);
        if (it != this->workshops.end())
        {
            this->workshops.erase(it);
        }
    }
}