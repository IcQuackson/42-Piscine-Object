#pragma once

#ifndef IWORKSHOP_HPP
#define IWORKSHOP_HPP

#include <vector>

class Worker;

class IWorkshop {
public:
    virtual ~IWorkshop() {}
    virtual void registerWorker(Worker* worker) = 0;
    virtual void releaseWorker(Worker* worker) = 0;
    virtual void executeWorkDay() = 0;
    virtual const std::vector<Worker *> &getWorkers() const = 0;
    virtual bool isWorkerEligible(Worker *worker) const = 0;
    virtual bool isWorkerRegistered(Worker *worker) const = 0;

};

#endif // IWORKSHOP_HPP
