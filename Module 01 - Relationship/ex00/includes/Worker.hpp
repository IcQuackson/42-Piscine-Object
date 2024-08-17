
#pragma once

#include "Position.hpp"
#include "Statistic.hpp"
#include "Workshop.hpp"
#include "Tool.hpp"
#include <cstdarg>
#include <vector>
#include <cstddef>
#include <algorithm>

class Position;
class Statistic;
class Tool;
class Workshop;

class Worker
{
private:
    Position position;
    Statistic statistic;
    std::vector<Tool *> _tools;
    std::vector<Workshop *> _workshops;

public:
    Worker(Position position, Statistic statistic);
    Worker();
    ~Worker();
    Position getPosition() const;
    Statistic getStatistic() const;
    const std::vector<Tool *> getTools() const;
    const Tool *getTool(size_t index) const;
    const std::vector<Workshop *> getWorkshops() const;
    void addWorkshop(Workshop *workshop);
    void removeWorkshop(Workshop *workshop);
    void setPosition(Position position);
    void setStatistic(Statistic statistic);
    void addTool(Tool *tool);
    void removeTool(Tool *tool);
    void work() const;

    template<typename ToolType>
    const ToolType *getTool() const
    {
        for (std::vector<Tool *>::const_iterator it = _tools.begin(); it != _tools.end(); ++it)
        {
            if (dynamic_cast<ToolType *>(*it))
            {
                return dynamic_cast<ToolType *>(*it);
            }
        }
        return NULL;
    }
};