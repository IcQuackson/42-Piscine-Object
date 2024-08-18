#pragma once

#include "ILogger.hpp"
#include <fstream>
#include <string>

class FileLogger : public ILogger
{

private:
    std::string _filename;

public:
    FileLogger(std::string filename)
    {
        _filename = filename;
    }

    void write(std::string message)
    {
        // Open the file in append mode and create the file if it doesn't exist.
        std::ofstream file(_filename.c_str(), std::ios::out | std::ios::app);

        if (!file) {
            std::cerr << "Failed to open the file." << std::endl;
            return;
        }

        file << message << std::endl;

        if (!file.good()) {
            std::cerr << "Error occurred at writing time." << std::endl;
            return;
        }

        file.close();
    }
};