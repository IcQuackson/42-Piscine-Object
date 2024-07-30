#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"
#include <assert.h>

void printColor(std::string color, std::string text) {
    std::cout << color << text << RESET << std::endl;
}

void testToolCreation()
{
    printColor(GREEN, "Test 1: Tool creation");
    Tool *tool = new Hammer();
    delete tool;
    std::cout << std::endl;
}

void testWorkerCreation()
{
    printColor(GREEN, "Test 2: Worker creation");
    Position position = Position(1, 2, 3);
    Statistic statistic = Statistic(4, 5);
    Worker *worker = new Worker(position, statistic);

    // assert that the worker has correct position and statistic
    assert(worker->getPosition().getX() == 1);
    assert(worker->getPosition().getY() == 2);
    assert(worker->getPosition().getZ() == 3);
    assert(worker->getStatistic().getLevel() == 4);
    assert(worker->getStatistic().getExp() == 5);

    delete worker;
    std::cout << std::endl;
}

void testWorkerAddTool()
{
    printColor(GREEN, "Test 3: Worker add tool");
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    // assert that the worker has the correct tool
    assert(worker->getTools().size() == 1);
    assert(worker->getTool(0) == tool);

    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testRemoveToolFromWorker()
{
    printColor(GREEN, "Test 4: Worker remove tool");
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    assert(worker->getTools().size() == 1);

    worker->removeTool(tool);

    assert(worker->getTools().size() == 0);

    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testDeleteWorkerWithTool()
{
    printColor(GREEN, "Test 5: Delete worker with tool");
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    assert(worker->getTools().size() == 1);

    delete worker;

    assert(tool != NULL);

    delete tool;
    std::cout << std::endl;
}

void testChangeToolOwner()
{
    printColor(GREEN, "Test 6: Change tool owner");
    Worker *worker1 = new Worker();
    Worker *worker2 = new Worker();
    Tool *tool = new Hammer();
    worker1->addTool(tool);

    assert(worker1->getTools().size() == 1);
    assert(tool->getOwner() == worker1);

    worker2->addTool(tool);

    assert(worker2->getTools().size() == 1);
    assert(worker1->getTools().size() == 0);
    assert(tool->getOwner() == worker2);

    delete worker1;
    delete worker2;
    delete tool;
    std::cout << std::endl;
}

void testUseTool()
{
    printColor(GREEN, "Test 7: Use tool");
    Tool *tool = new Hammer();
    tool->use();

    assert(tool->getNumberOfUses() == 1);

    delete tool;
    std::cout << std::endl;
}

void testRegisterWorker()
{
    printColor(GREEN, "Test 8: Register worker");
    Workshop<Hammer> *workshop = new Workshop<Hammer>();
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getTools().size() == 1);

    workshop->registerWorker(worker);

    assert(workshop->getWorkers().size() == 1);
    assert(worker->getWorkshop() == workshop);

    delete workshop;
    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testWorkerWork()
{
    printColor(GREEN, "Test 9: Worker work");
    Worker *worker = new Worker();
    worker->work();
    delete worker;
    std::cout << std::endl;
}

void testWorkshopExecuteWorkDay()
{
    printColor(GREEN, "Test 10: Workshop execute work day");
    Workshop<Hammer> *workshop = new Workshop<Hammer>();
    Worker *worker1 = new Worker();
    Worker *worker2 = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Hammer();
    worker1->addTool(tool1);
    worker2->addTool(tool2);

    assert(workshop->getWorkers().size() == 0);
    assert(worker1->getTools().size() == 1);
    assert(worker2->getTools().size() == 1);

    workshop->registerWorker(worker1);
    workshop->registerWorker(worker2);

    assert(workshop->getWorkers().size() == 2);
    assert(worker1->getWorkshop() == workshop);
    assert(worker2->getWorkshop() == workshop);

    workshop->executeWorkDay();
    delete workshop;
    delete worker1;
    delete worker2;
    delete tool1;
    delete tool2;
    std::cout << std::endl;
}

void testReleaseWorker()
{
    printColor(GREEN, "Test 11: Release worker");
    Workshop<Hammer> *workshop = new Workshop<Hammer>();
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getTools().size() == 1);
    assert(worker->getTool<Hammer>() != NULL);
    assert(dynamic_cast<const Hammer *>(worker->getTool<Hammer>()) != NULL);

    workshop->registerWorker(worker);

    assert(workshop->getWorkers().size() == 1);
    assert(worker->getWorkshop() == workshop);

    workshop->releaseWorker(worker);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getWorkshop() == NULL);

    delete workshop;
    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testGetToolByType()
{
    printColor(GREEN, "Test 12: Get tool by type");
    Worker *worker = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Shovel();
    worker->addTool(tool1);
    worker->addTool(tool2);

    assert(worker->getTool<Hammer>() != NULL);
    assert(worker->getTool<Shovel>() != NULL);
    assert(worker->getTool<Hammer>() == tool1);
    assert(worker->getTool<Shovel>() == tool2);

    delete worker;
    delete tool1;
    delete tool2;
    std::cout << std::endl;
}

// test register worker with tool that is not allowed by the workshop
void testRegisterWorkerWithWrongTool()
{
    printColor(GREEN, "Test 13: Register worker with wrong tool");
    Workshop<Hammer> *workshop = new Workshop<Hammer>();
    Worker *worker = new Worker();
    Tool *tool = new Shovel();
    worker->addTool(tool);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getTools().size() == 1);
    assert(worker->getTool<Shovel>() != NULL);

    workshop->registerWorker(worker);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getWorkshop() == NULL);

    delete workshop;
    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testDeleteToolFromWorkerWithOnlyAllowedTool()
{
    printColor(GREEN, "Test 14: Delete tool from worker with only allowed tool");
    Workshop<Hammer> *workshop = new Workshop<Hammer>();
    Worker *worker = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Shovel();
    worker->addTool(tool1);
    worker->addTool(tool2);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getTools().size() == 2);
    assert(worker->getTool<Hammer>() != NULL);
    assert(worker->getTool<Shovel>() != NULL);

    workshop->registerWorker(worker);

    assert(workshop->getWorkers().size() == 1);
    assert(worker->getWorkshop() == workshop);

    worker->removeTool(tool1);

    assert(workshop->getWorkers().size() == 0);
    assert(worker->getWorkshop() == NULL);

    delete workshop;
    delete worker;
    delete tool1;
    delete tool2;
    std::cout << std::endl;
}

int main()
{
    testToolCreation();
    testWorkerCreation();
    testWorkerAddTool();
    testRemoveToolFromWorker();
    testDeleteWorkerWithTool();
    testChangeToolOwner();
    testUseTool();
    testRegisterWorker();
    testWorkerWork();
    testWorkshopExecuteWorkDay();
    testReleaseWorker();
    testGetToolByType();
    testRegisterWorkerWithWrongTool();
    testDeleteToolFromWorkerWithOnlyAllowedTool();
    return 0;
}