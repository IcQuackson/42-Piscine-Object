#pragma once

#include "LoggerDecorator.hpp"
#include <ctime>
#include <sstream>

class DateHeaderDecorator : public LoggerDecorator
{
private:
    std::string getCurrentTimestamp()
    {
        // Get the current time
        std::time_t now = std::time(0);
        
        // Convert now to tm struct for UTC
        std::tm* gmtm = std::gmtime(&now);
        
        // Convert tm struct to a date-time string
        std::stringstream ss;
        ss << gmtm->tm_year + 1900 << '-' 
        << gmtm->tm_mon + 1 << '-' 
        << gmtm->tm_mday << ' ' 
        << gmtm->tm_hour << ':' 
        << gmtm->tm_min << ':' 
        << gmtm->tm_sec;
        
        std::string dateTime = ss.str();
        return dateTime;
    }
public:
    DateHeaderDecorator(ILogger *logger) : LoggerDecorator(logger) {}

    void write(std::string message)
    {
        _wrappedLogger->write(getCurrentTimestamp() + " " + message);
    }

};