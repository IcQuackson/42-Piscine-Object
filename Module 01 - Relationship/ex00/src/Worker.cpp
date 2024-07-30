
#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker(Position position, Statistic statistic) : position(position), statistic(statistic), workshop(NULL)
{
}

Worker::Worker() : position(Position()), statistic(Statistic()), workshop(NULL)
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

const IWorkshop *Worker::getWorkshop() const
{
    return this->workshop;
}

void Worker::setPosition(Position position)
{
    this->position = position;
}

void Worker::setStatistic(Statistic statistic)
{
    this->statistic = statistic;
}

void Worker::setWorkshop(IWorkshop *workshop)
{
    this->workshop = workshop;
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
            if (this->workshop != NULL && !this->workshop->isWorkerEligible(this))
            {
                this->workshop->releaseWorker(this);
            }
        }
    }
}

void Worker::work() const
{
    std::cout << "Worker working" << std::endl;
}

