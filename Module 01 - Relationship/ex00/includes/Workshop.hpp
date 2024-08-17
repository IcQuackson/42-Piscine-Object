#pragma once

#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include <iostream>
#include <vector>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Worker;
class Tool;

class Workshop
{
private:
    std::vector<Worker *> _workers;
    std::vector<std::string> _requiredTools;

public:
    Workshop(std::vector<std::string> requiredTools);
    void registerWorker(Worker *worker);
    void releaseWorker(Worker *worker);
    void executeWorkDay();
    const std::vector<Worker *> &getWorkers() const;
    bool isWorkerEligible(Worker *worker) const;
    bool isWorkerRegistered(Worker *worker) const;
    bool isToolRequired(Tool *tool) const;
    bool doesWorkerHaveRequiredTools(Worker *worker) const;
    static void printColor(std::string color, std::string message);
};

#endif