#pragma once

#define WORKDAY_HOURS 7

class Employee
{
private:
    Employee()
    {}

protected:
    int _hourlyValue;
    int _hoursWorked;

public:
    Employee(int hourlyValue) : _hourlyValue(hourlyValue), _hoursWorked(0)
    {}

    int getHourlyValue() const
    {
        return _hourlyValue;
    }

    int getHoursWorked() const
    {
        return _hoursWorked;
    }

    virtual int executeWorkday()
    {
        _hoursWorked += 7;
        return _hoursWorked;
    }

    virtual double calculatePayroll()
    {
        return _hoursWorked * _hourlyValue;
    }
};