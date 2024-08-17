#pragma once

#include "employee.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class SalariedEmployee : public Employee
{
protected:
    int _nonWorkedHours;
    std::vector<int> _nonWorkedHoursLog;
public:
    SalariedEmployee(int hourlyValue) : Employee(hourlyValue), _nonWorkedHours(0)
    {}

    int getNonWorkedHours() const
    {
        return _nonWorkedHours;
    }

    void registerNonWorkedHours(int hours)
    {
        if (hours > 0)
        {
            _nonWorkedHoursLog.push_back(hours);
            _nonWorkedHours += hours;
        }
    }

    void printNonWorkedHoursLog()
    {
        int day = 1;
        std::vector<int>::const_iterator it;
        for (it = _nonWorkedHoursLog.begin(); it != _nonWorkedHoursLog.end(); it++)
        {
            std::cout << "Day: " << day++ << " -> Non Worked Hours: " << *it << std::endl; 
        }
    }

    std::vector<int> getNonWorkedHoursLog() const
    {
        return _nonWorkedHoursLog;
    }
};


class ContractEmployee : public SalariedEmployee
{
public:
    ContractEmployee(int hourlyValue) : SalariedEmployee(hourlyValue)
    {}
};


class Apprentice : public SalariedEmployee
{
private:
    int _schoolHours;
    std::vector<int> _schoolHoursLog;

public:
    Apprentice(int hourlyValue) : SalariedEmployee(hourlyValue), _schoolHours(0)
    {}

    void registerSchoolHours(int hours)
    {
        if (hours > 0)
        {
            _schoolHoursLog.push_back(hours);
            _schoolHours += hours;
        }
    }

    int getSchoolHours() const
    {
        return _schoolHours;
    }

    double calculatePayroll()
    {
        return SalariedEmployee::calculatePayroll() + _schoolHours * _hourlyValue / 2;
    }

    void printSchoolHoursLog()
    {
        int day = 1;
        std::vector<int>::const_iterator it;
        for (it = _schoolHoursLog.begin(); it != _schoolHoursLog.end(); it++)
        {
            std::cout << "Day: " << day++ << " -> School Hours: " << *it << std::endl; 
        }
    }

    std::vector<int> getSchoolHoursLog() const
    {
        return _schoolHoursLog;
    }
};