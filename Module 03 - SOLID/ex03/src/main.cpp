
#include <iostream>
#include <assert.h>
#include "employeeManagement.hpp"
#include "salariedEmployee.hpp"
#include "hourlyEmployee.hpp"


// test TempWorker register mobilized hours
void testTempWorkerRegisterMobilizedHours()
{
    TempWorker tempWorker(10);
    tempWorker.mobilize(10);
    assert(tempWorker.getMobilizedHours() == 10);
}

// test TempWorker execute workday with 10 mobilized hours
void testTempWorkerExecuteWorkdayWith10MobilizedHours()
{
    TempWorker tempWorker(10);
    tempWorker.mobilize(10);
    assert(tempWorker.executeWorkday() == 7);
    assert(tempWorker.getWorkedHoursLog().size() == 1);
    assert(tempWorker.getMobilizedHours() == 3);
}

// test TempWorker execute workday with 5 mobilized hours
void testTempWorkerExecuteWorkdayWith5MobilizedHours()
{
    TempWorker tempWorker(10);
    tempWorker.mobilize(5);
    assert(tempWorker.executeWorkday() == 5);
    assert(tempWorker.getWorkedHoursLog().size() == 1);
    assert(tempWorker.getMobilizedHours() == 0);
}

// test TempWorker execute workday without mobilized hours
void testTempWorkerExecuteWorkdayWithoutMobilizedHours()
{
    TempWorker tempWorker(10);
    assert(tempWorker.executeWorkday() == 0);
    assert(tempWorker.getWorkedHoursLog().size() == 1);
}

// test ContractEmployee register non worked hours
void testContractEmployeeRegisterNonWorkedHours()
{
    ContractEmployee contractEmployee(10);
    contractEmployee.registerNonWorkedHours(10);
    assert(contractEmployee.getNonWorkedHours() == 10);
}

// test Apprentice register school hours and non worked hours
void testApprenticeRegisterSchoolHoursAndNonWorkedHours()
{
    Apprentice apprentice(10);
    apprentice.registerSchoolHours(10);
    apprentice.registerNonWorkedHours(5);
    assert(apprentice.getSchoolHours() == 10);
    assert(apprentice.getNonWorkedHours() == 5);
}

// test EmployeeManager add and remove employees
void testEmployeeManagerAddAndRemoveEmployees()
{
    EmployeeManager employeeManager;
    TempWorker tempWorker(10);
    ContractEmployee contractEmployee(10);
    Apprentice apprentice(10);

    employeeManager.addEmployee(&tempWorker);
    employeeManager.addEmployee(&contractEmployee);
    employeeManager.addEmployee(&apprentice);

    assert(employeeManager.getEmployees().size() == 3);

    employeeManager.removeEmployee(&tempWorker);
    assert(employeeManager.getEmployees().size() == 2);

    employeeManager.removeEmployee(&contractEmployee);
    assert(employeeManager.getEmployees().size() == 1);

    employeeManager.removeEmployee(&apprentice);
    assert(employeeManager.getEmployees().size() == 0);
}

// test calculate payroll
void testCalculatePayroll()
{
    EmployeeManager employeeManager;
    TempWorker tempWorker(10);
    ContractEmployee contractEmployee(10);
    Apprentice apprentice(10);

    tempWorker.mobilize(20);
    contractEmployee.registerNonWorkedHours(5);
    apprentice.registerSchoolHours(2);
    apprentice.registerNonWorkedHours(3);

    employeeManager.addEmployee(&tempWorker);
    employeeManager.addEmployee(&contractEmployee);
    employeeManager.addEmployee(&apprentice);

    employeeManager.executeWorkday();
    employeeManager.calculatePayroll();

    // check payroll values
    assert(tempWorker.calculatePayroll() == 70);
    assert(contractEmployee.calculatePayroll() == 70);
    assert(apprentice.calculatePayroll() == 80);

    // check log sizes
    assert(tempWorker.getWorkedHoursLog().size() == 1);
    assert(contractEmployee.getNonWorkedHoursLog().size() == 1);
    assert(apprentice.getSchoolHoursLog().size() == 1);
    assert(apprentice.getNonWorkedHoursLog().size() == 1);
    
    // check log values
    assert(tempWorker.getWorkedHoursLog().at(0) == 7);
    assert(contractEmployee.getNonWorkedHoursLog().at(0) == 5);
    assert(apprentice.getSchoolHoursLog().at(0) == 2);
    assert(apprentice.getNonWorkedHoursLog().at(0) == 3);
}

int main()
{
    testTempWorkerRegisterMobilizedHours();
    testTempWorkerExecuteWorkdayWith10MobilizedHours();
    testTempWorkerExecuteWorkdayWith5MobilizedHours();
    testTempWorkerExecuteWorkdayWithoutMobilizedHours();
    testContractEmployeeRegisterNonWorkedHours();
    testApprenticeRegisterSchoolHoursAndNonWorkedHours();
    testEmployeeManagerAddAndRemoveEmployees();
    testCalculatePayroll();

    std::cout << "All tests passed!" << std::endl;

    return 0;

}