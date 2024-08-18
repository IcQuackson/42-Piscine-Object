#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "StreamLogger.hpp"
#include "LoggerDecorator.hpp"
#include "DateHeaderDecorator.hpp"
#include "ConstantHeaderDecorator.hpp"
#include <vector>

void testFileLogger()
{
    ILogger *logger = new FileLogger("log.txt");

    logger->write("Message for the file logger");

    delete logger;
}

void testStreamLogger()
{
    ILogger *logger = new StreamLogger(std::cout);

    logger->write("Message for the stream logger");

    delete logger;
}

void testDateHeaderDecorator()
{
    ILogger *logger = new FileLogger("log.txt");

    ILogger *dateHeaderLogger = new DateHeaderDecorator(logger);

    dateHeaderLogger->write("Message with date header for the file logger");

    delete dateHeaderLogger;
    delete logger;
}

void testConstantHeaderDecorator()
{
    ILogger *logger = new FileLogger("log.txt");

    ILogger *constantHeaderLogger = new ConstantHeaderDecorator(logger, "[INFO]");

    constantHeaderLogger->write("Message with constant header for the file logger");

    delete constantHeaderLogger;
    delete logger;
}

void testDateHeaderAndConstantHeaderDecorator()
{
    ILogger *logger = new FileLogger("log.txt");

    ILogger *dateHeaderLogger = new DateHeaderDecorator(logger);

    ILogger *constantHeaderLogger = new ConstantHeaderDecorator(dateHeaderLogger, "[INFO]");

    constantHeaderLogger->write("Message with date and constant header for the file logger");

    delete constantHeaderLogger;
    delete dateHeaderLogger;
    delete logger;
}

void testAllLoggers()
{
    std::vector<ILogger *> loggers;

    loggers.push_back(new FileLogger("log.txt"));
    loggers.push_back(new StreamLogger(std::cout));
    loggers.push_back(new ConstantHeaderDecorator(new FileLogger("log.txt"), "[INFO]"));
    loggers.push_back(new DateHeaderDecorator(new StreamLogger(std::cout)));
    loggers.push_back(new DateHeaderDecorator(new ConstantHeaderDecorator(new FileLogger("log.txt"), "[INFO]")));

    for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); ++it)
    {
        (*it)->write("Message for all loggers");
        delete *it;
    }
}

int main()
{
    testFileLogger();
    testStreamLogger();
    testDateHeaderDecorator();
    testConstantHeaderDecorator();
    testDateHeaderAndConstantHeaderDecorator();
    testAllLoggers();

    return 0;
}