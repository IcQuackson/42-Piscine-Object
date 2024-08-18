#pragma once

#include "LoggerDecorator.hpp"

class ConstantHeaderDecorator : public LoggerDecorator
{
private:
    std::string _header;

public:
    ConstantHeaderDecorator(ILogger *logger, std::string header) : LoggerDecorator(logger), _header(header) {}

    void write(std::string message)
    {
       _wrappedLogger->write(_header + " " + message);
    }

};