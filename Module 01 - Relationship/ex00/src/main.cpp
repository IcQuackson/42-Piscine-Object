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

void myAssert(bool condition, std::string message) {
    if (!condition) {
        printColor(RED, "Assertion failed: " + message);
    }
    assert(condition);
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
    myAssert(worker->getPosition().getX() == 1, "Worker has incorrect X position");
    myAssert(worker->getPosition().getY() == 2, "Worker has incorrect Y position");
    myAssert(worker->getPosition().getZ() == 3, "Worker has incorrect Z position");
    myAssert(worker->getStatistic().getLevel() == 4, "Worker has incorrect level");
    myAssert(worker->getStatistic().getExp() == 5, "Worker has incorrect experience");

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
    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");
    myAssert(worker->getTool(0) == tool, "Worker does not have the correct tool");

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

    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");

    worker->removeTool(tool);

    myAssert(worker->getTools().size() == 0, "Worker still has tools after removing");

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

    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");

    delete worker;

    myAssert(tool != NULL, "Tool was deleted along with the worker");

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

    myAssert(worker1->getTools().size() == 1, "Worker 1 does not have the correct number of tools");
    myAssert(tool->getOwner() == worker1, "Tool does not have the correct owner");

    worker2->addTool(tool);

    myAssert(worker2->getTools().size() == 1, "Worker 2 does not have the correct number of tools");
    myAssert(worker1->getTools().size() == 0, "Worker 1 still has tools after changing ownership");
    myAssert(tool->getOwner() == worker2, "Tool does not have the correct owner");

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

    myAssert(tool->getNumberOfUses() == 1, "Tool did not increment the number of uses correctly");

    delete tool;
    std::cout << std::endl;
}

void testRegisterWorker()
{
    printColor(GREEN, "Test 8: Register worker");

    std::vector<std::string> requiredTools;
    requiredTools.push_back("Hammer");

    Workshop *workshop = new Workshop(requiredTools);
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    myAssert(workshop->getWorkers().size() == 0, "Workshop already has workers");
    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");

    workshop->registerWorker(worker);

    myAssert(workshop->getWorkers().size() == 1, "Workshop did not register the worker");
    myAssert(worker->getWorkshops().size() == 1, "Worker did not register the workshop");
    myAssert(worker->getWorkshops()[0] == workshop, "Worker registered to the wrong workshop");

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

    std::vector<std::string> requiredTools;
    requiredTools.push_back("Hammer");
    Workshop *workshop = new Workshop(requiredTools);

    Worker *worker1 = new Worker();
    Worker *worker2 = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Hammer();
    worker1->addTool(tool1);
    worker2->addTool(tool2);

    myAssert(workshop->getWorkers().size() == 0, "Workshop already has workers");
    myAssert(worker1->getTools().size() == 1, "Worker 1 does not have the correct number of tools");
    myAssert(worker2->getTools().size() == 1, "Worker 2 does not have the correct number of tools");

    workshop->registerWorker(worker1);
    workshop->registerWorker(worker2);

    myAssert(workshop->getWorkers().size() == 2, "Workshop did not register all workers");
    myAssert(worker1->getWorkshops().size() == 1, "Worker 1 did not register the workshop");
    myAssert(worker1->getWorkshops()[0] == workshop, "Worker 1 registered to the wrong workshop");
    myAssert(worker2->getWorkshops().size() == 1, "Worker 2 did not register the workshop");
    myAssert(worker2->getWorkshops()[0] == workshop, "Worker 2 registered to the wrong workshop");

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

    std::vector<std::string> requiredTools;
    requiredTools.push_back("Hammer");
    Workshop *workshop = new Workshop(requiredTools);
    Worker *worker = new Worker();
    Tool *tool = new Hammer();
    worker->addTool(tool);

    myAssert(workshop->getWorkers().size() == 0, "Workshop already has workers");
    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");
    myAssert(worker->getTool<Hammer>() != NULL, "Worker does not have the correct tool");
    myAssert(dynamic_cast<const Hammer *>(worker->getTool<Hammer>()) != NULL, "Worker does not have the correct tool type");

    workshop->registerWorker(worker);

    myAssert(workshop->getWorkers().size() == 1, "Workshop did not register the worker");
    myAssert(worker->getWorkshops().size() == 1, "Worker did not register the workshop");
    myAssert(worker->getWorkshops()[0] == workshop, "Worker registered to the wrong workshop");

    workshop->releaseWorker(worker);

    myAssert(workshop->getWorkers().size() == 0, "Workshop did not release the worker");
    myAssert(worker->getWorkshops().size() == 0, "Worker did not release the workshop");

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

    myAssert(worker->getTool<Hammer>() != NULL, "Worker does not have the correct tool");
    myAssert(worker->getTool<Shovel>() != NULL, "Worker does not have the correct tool");
    myAssert(worker->getTool<Hammer>() == tool1, "Worker does not have the correct tool");
    myAssert(worker->getTool<Shovel>() == tool2, "Worker does not have the correct tool");

    delete worker;
    delete tool1;
    delete tool2;
    std::cout << std::endl;
}

// test register worker with tool that is not allowed by the workshop
void testRegisterWorkerWithWrongTool()
{
    printColor(GREEN, "Test 13: Register worker with wrong tool");

    std::vector<std::string> requiredTools;
    requiredTools.push_back("Hammer");
    Workshop *workshop = new Workshop(requiredTools);
    Worker *worker = new Worker();
    Tool *tool = new Shovel();
    worker->addTool(tool);

    myAssert(workshop->getWorkers().size() == 0, "Workshop already has workers");
    myAssert(worker->getTools().size() == 1, "Worker does not have the correct number of tools");
    myAssert(worker->getTool<Shovel>() != NULL, "Worker does not have the correct tool");

    workshop->registerWorker(worker);

    myAssert(workshop->getWorkers().size() == 0, "Workshop registered the worker with wrong tool");
    myAssert(worker->getWorkshops().size() == 0, "Worker registered to the workshop with wrong tool");

    delete workshop;
    delete worker;
    delete tool;
    std::cout << std::endl;
}

void testDeleteToolFromWorkerWithOnlyAllowedTool()
{
    printColor(GREEN, "Test 14: Delete tool from worker with only allowed tool");

    std::vector<std::string> requiredTools;
    requiredTools.push_back("Hammer");
    Workshop *workshop = new Workshop(requiredTools);
    Worker *worker = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Shovel();
    worker->addTool(tool1);
    worker->addTool(tool2);

    myAssert(workshop->getWorkers().size() == 0, "Workshop already has workers");
    myAssert(worker->getTools().size() == 2, "Worker does not have the correct number of tools");
    myAssert(worker->getTool<Hammer>() != NULL, "Worker does not have the correct tool");
    myAssert(worker->getTool<Shovel>() != NULL, "Worker does not have the correct tool");

    workshop->registerWorker(worker);

    myAssert(workshop->getWorkers().size() == 1, "Workshop did not register the worker");
    myAssert(worker->getWorkshops().size() == 1, "Worker did not register the workshop");
    myAssert(worker->getWorkshops()[0] == workshop, "Worker registered to the wrong workshop");
    myAssert(workshop != NULL, "Workshop is NULL");

    worker->removeTool(tool1);

    myAssert(workshop->getWorkers().size() == 0, "Workshop did not release the worker");
    myAssert(worker->getWorkshops().size() == 0, "Worker did not release the workshop");

    delete workshop;
    delete worker;
    delete tool1;
    delete tool2;
    std::cout << std::endl;
}

// test register to two different workshops
void testRegisterToTwoWorkshops()
{
    printColor(GREEN, "Test 15: Register to two different workshops");

    std::vector<std::string> requiredTools1;
    requiredTools1.push_back("Hammer");
    Workshop *workshop1 = new Workshop(requiredTools1);

    std::vector<std::string> requiredTools2;
    requiredTools2.push_back("Shovel");
    Workshop *workshop2 = new Workshop(requiredTools2);
    Worker *worker = new Worker();
    Tool *tool1 = new Hammer();
    Tool *tool2 = new Shovel();
    worker->addTool(tool1);
    worker->addTool(tool2);

    myAssert(workshop1->getWorkers().size() == 0, "Workshop 1 already has workers");
    myAssert(workshop2->getWorkers().size() == 0, "Workshop 2 already has workers");
    myAssert(worker->getTools().size() == 2, "Worker does not have the correct number of tools");
    myAssert(worker->getTool<Hammer>() != NULL, "Worker does not have the correct tool");
    myAssert(worker->getTool<Shovel>() != NULL, "Worker does not have the correct tool");

    workshop1->registerWorker(worker);
    workshop2->registerWorker(worker);

    myAssert(workshop1->getWorkers().size() == 1, "Workshop 1 did not register the worker");
    myAssert(workshop2->getWorkers().size() == 1, "Workshop 2 did not register the worker");
    myAssert(worker->getWorkshops().size() == 2, "Worker did not register to both workshops");
    myAssert(worker->getWorkshops()[0] == workshop1, "Worker registered to the wrong workshop");
    myAssert(worker->getWorkshops()[1] == workshop2, "Worker registered to the wrong workshop");

    delete workshop1;
    delete workshop2;
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
    testRegisterToTwoWorkshops();
    return 0;
}