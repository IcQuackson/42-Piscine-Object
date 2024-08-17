
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
    for (std::vector<Tool *>::iterator it = _tools.begin(); it != _tools.end(); ++it)
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
    return _tools;
}

const Tool *Worker::getTool(size_t index) const
{
    if (index < _tools.size())
    {
        return _tools[index];
    }
    return NULL;
}

const std::vector<Workshop *> Worker::getWorkshops() const
{
    return _workshops;
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
            std::cout << "Tool already owned by another worker" << std::endl;
            tool->getOwner()->removeTool(tool);
        }
        tool->removeOwner();
        tool->setOwner(this);
        _tools.push_back(tool);
        std::cout << "Tool added" << std::endl;
    }
}

void Worker::removeTool(Tool *tool)
{
    if (tool)
    {
        std::vector<Tool *>::iterator it = std::find(_tools.begin(), _tools.end(), tool);
        if (it != _tools.end())
        {
            std::cout << "Tool removed" << std::endl;
            (*it)->removeOwner();
            _tools.erase(it);
            // If the worker has a workshop and is no longer eligible, release the worker
            while (_workshops.size() > 0 && !(*_workshops.begin())->doesWorkerHaveRequiredTools(this))
            {
                std::cout << "Worker no longer eligible for workshop" << std::endl;
                (*_workshops.begin())->releaseWorker(this);
            }
        }
        std::cout << "Tool not found" << std::endl;
    }
}

void Worker::work() const
{
    if (_workshops.size() == 0)
    {
        std::cout << "Worker not registered in any workshop" << std::endl;
        return;
    }
    std::cout << "Worker working" << std::endl;
}

void Worker::addWorkshop(Workshop *workshop)
{
    if (!workshop)
    {
        std::cout << "Workshop is null" << std::endl;
        return;
    }
    if (!workshop->isWorkerRegistered(this))
    {
        std::cout << "Worker not eligible for workshop" << std::endl;
        return;
    }
    if (std::find(_workshops.begin(), _workshops.end(), workshop) != _workshops.end())
    {
        std::cout << "Worker already registered in workshop" << std::endl;
        return;
    }
    else
    {
        std::cout << "Worker registered in workshop" << std::endl;
        _workshops.push_back(workshop);
    }
}

void Worker::removeWorkshop(Workshop *workshop)
{
    if (workshop)
    {
        std::vector<Workshop *>::iterator it = std::find(_workshops.begin(), _workshops.end(), workshop);
        if (it != _workshops.end())
        {
            _workshops.erase(it);
        }
    }
}