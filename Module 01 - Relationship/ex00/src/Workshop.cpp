#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

Workshop::Workshop(std::vector<std::string> requiredTools)
{
    _requiredTools = requiredTools;
}

void Workshop::registerWorker(Worker *worker)
{
    if (this->isWorkerEligible(worker))
    {
        _workers.push_back(worker);
        worker->addWorkshop(this);
    }
}

void Workshop::releaseWorker(Worker *worker)
{
    for (std::vector<Worker *>::iterator it = _workers.begin(); it != _workers.end(); it++)
    {
        if (*it == worker)
        {
            std::cout << "Worker released" << std::endl;
            _workers.erase(it);
            worker->removeWorkshop(this);
            break;
        }
    }
}

void Workshop::executeWorkDay()
{
    for (std::vector<Worker *>::iterator it = _workers.begin(); it != _workers.end(); it++)
    {
        (*it)->work();
    }
}

const std::vector<Worker *> &Workshop::getWorkers() const
{
    return _workers;
}

bool Workshop::isWorkerEligible(Worker *worker) const
{
    if (this->isWorkerRegistered(worker))
    {
        printColor(RED, "Worker is already registered");
        return false;
    }

    if (!this->doesWorkerHaveRequiredTools(worker))
    {
        printColor(RED, "Worker does not have required tools");
        return false;
    }

    printColor(GREEN, "Worker is eligible");
    return true;
}

bool Workshop::isWorkerRegistered(Worker *worker) const
{
    return std::find(_workers.begin(), _workers.end(), worker) != _workers.end();
}

bool Workshop::isToolRequired(Tool *tool) const
{
    return std::find(_requiredTools.begin(), _requiredTools.end(), tool->getType()) != _requiredTools.end();
}

bool Workshop::doesWorkerHaveRequiredTools(Worker *worker) const
{
    bool toolRequiredFound = false;

    if (worker == NULL)
    {
        return false;
    }
    
    for (size_t i = 0; i < _requiredTools.size(); i++)
    {
        for (size_t j = 0; j < worker->getTools().size(); j++)
        {
            if (worker->getTools()[j]->getType() == _requiredTools[i])
            {
                toolRequiredFound = true;
                break;
            }
        }
        if (!toolRequiredFound)
        {
            return false;
        }
    }
    return true;
}

void Workshop::printColor(std::string color, std::string message)
{
    std::cout << color << message << RESET << std::endl;
}