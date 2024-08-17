#pragma once

#include "employee.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class HourlyEmployee : public Employee
{
protected:
    int _mobilizedHours;
    std::vector<int> _workedHoursLog;

public:
    HourlyEmployee(int hourlyValue) : Employee(hourlyValue), _mobilizedHours(0)
    {}

    void mobilize(int hours)
    {
        if (hours > 0)
        {
            _mobilizedHours += hours;
        }
    }

    int getMobilizedHours() const
    {
        return _mobilizedHours;
    }

    int executeWorkday()
    {
        int hoursWorkedDay = 0;

        if (_mobilizedHours > 0)
        {
            // Worker works a maximum of 7 hours
            hoursWorkedDay = 7;
            if (_mobilizedHours < 7)
            {
                hoursWorkedDay = _mobilizedHours;
            }
            _mobilizedHours -= hoursWorkedDay;
        }
        _hoursWorked += hoursWorkedDay;
        _workedHoursLog.push_back(hoursWorkedDay);
        return hoursWorkedDay;
    }

    void printWorkedHoursLog()
    {
        int day = 1;
        std::vector<int>::const_iterator it;
        for (it = _workedHoursLog.begin(); it != _workedHoursLog.end(); it++)
        {
            std::cout << "Day: " << day++ << " -> Worked Hours: " << *it << std::endl; 
        }
    }

    std::vector<int> getWorkedHoursLog() const
    {
        return _workedHoursLog;
    }
};

class TempWorker : public HourlyEmployee
{
public:
    TempWorker(int hourlyValue) : HourlyEmployee(hourlyValue)
    {}
};