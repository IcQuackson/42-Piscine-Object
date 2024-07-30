#pragma once

#ifndef WORKSHOP_TPP
#define WORKSHOP_TPP

#include "Worker.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

template <typename T>
void Workshop<T>::registerWorker(Worker *worker)
{
    // If worker has any tool that is allowed by the workshop, set the workshop as the worker's workshop
    std::vector<Tool *> tools = worker->getTools();
    for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); it++)
    {
        if (dynamic_cast<T *>(*it))
        {
            worker->setWorkshop(this);
            this->workers.push_back(worker);
            return;
        }
    }
}

template <typename T>
void Workshop<T>::releaseWorker(Worker *worker)
{
    for (std::vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
    {
        if (*it == worker)
        {
            (*it)->setWorkshop(NULL);
            this->workers.erase(it);
            break;
        }
    }
}

template <typename T>
void Workshop<T>::executeWorkDay()
{
    for (std::vector<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
    {
        (*it)->work();
    }
}

template <typename T>
const std::vector<Worker *> &Workshop<T>::getWorkers() const
{
    return this->workers;
}

template <typename T>
bool Workshop<T>::isWorkerEligible(Worker *worker) const
{
    std::vector<Tool *> tools = worker->getTools();
    for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); it++)
    {
        if (dynamic_cast<T *>(*it))
        {
            return true;
        }
    }
    return false;
}

#endif