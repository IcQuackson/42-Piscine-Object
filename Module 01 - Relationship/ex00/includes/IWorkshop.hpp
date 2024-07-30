#pragma once

#ifndef IWORKSHOP_HPP
#define IWORKSHOP_HPP

class Worker;

class IWorkshop {
public:
    virtual ~IWorkshop() {}
    virtual void registerWorker(Worker* worker) = 0;
    virtual void releaseWorker(Worker* worker) = 0;
    virtual void executeWorkDay() = 0;
    virtual bool isWorkerEligible(Worker *worker) const = 0;

};

#endif // IWORKSHOP_HPP
