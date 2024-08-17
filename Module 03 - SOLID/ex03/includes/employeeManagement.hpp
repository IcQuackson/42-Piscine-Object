#pragma once

#include "employee.hpp"
#include <iostream>
#include <stddef.h>
#include <vector>


class EmployeeManager
{

private:
    std::vector<Employee *> _employees;

public:
    void addEmployee(Employee *employee)
    {
        if (employee != NULL)
        {
            _employees.push_back(employee);
        }
    }

    void removeEmployee(Employee *employee)
    {
        if (employee != NULL)
        {
            for (size_t i = 0; i < _employees.size(); i++)
            {
                if (_employees.at(i) == employee)
                {
                    _employees.erase(_employees.begin() + i);
                    return;
                }
            }
        }
    }

    std::vector<Employee *> getEmployees() const
    {
        return _employees;
    }

    void executeWorkday()
    {
        for (size_t i = 0; i < _employees.size(); i++)
        {
            _employees.at(i)->executeWorkday();
        }
    }

    void calculatePayroll()
    {
        int payroll = 0;

        for (size_t i = 0; i < _employees.size(); i++)
        {
            Employee *employee = _employees.at(i);
            payroll += employee->calculatePayroll();
        }
        std::cout << "Current payroll: " + payroll << std::endl;
    }
};