
#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "IWorkshop.hpp"
#include <vector>
#include <cstddef>
#include <algorithm>

class Position;
class Statistic;
class Tool;

class Worker
{
private:
    Position position;
    Statistic statistic;
    std::vector<Tool *> tools;
    IWorkshop *workshop;

public:
    Worker(Position position, Statistic statistic);
    Worker();
    ~Worker();
    Position getPosition() const;
    Statistic getStatistic() const;
    const std::vector<Tool *> getTools() const;
    const Tool *getTool(size_t index) const;
    const IWorkshop *getWorkshop() const;
    void setPosition(Position position);
    void setStatistic(Statistic statistic);
    void setWorkshop(IWorkshop *workshop);
    void addTool(Tool *tool);
    void removeTool(Tool *tool);
    void work() const;

    template<typename ToolType> const ToolType *getTool() const
    {
        for (std::vector<Tool *>::const_iterator it = this->tools.begin(); it != this->tools.end(); ++it)
        {
            if (dynamic_cast<ToolType *>(*it))
            {
                return dynamic_cast<ToolType *>(*it);
            }
        }
        return NULL;
    }
};