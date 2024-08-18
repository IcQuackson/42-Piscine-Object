#pragma once

#include "ILogger.hpp"
#include <fstream>
#include <ostream>
#include <string>

class StreamLogger : public ILogger
{
private:
    std::ostream &_stream;

public:
    StreamLogger(std::ostream &stream) : _stream(stream)
    {
    }

    void write(std::string message)
    {
        _stream << message << std::endl;
    }
};