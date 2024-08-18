#pragma once

#include "ILogger.hpp"

class LoggerDecorator : public ILogger
{
protected:
    ILogger *_wrappedLogger;

public:
    LoggerDecorator(ILogger *logger)
    {
        _wrappedLogger = logger;
    }

    virtual ~LoggerDecorator() {}
    
    virtual void write(std::string message)
    {
        _wrappedLogger->write(message);
    }
};