#pragma once

struct Statistic
{
private:
    int level;
    int exp;

public:
    Statistic(int level, int exp);
    Statistic();
    int getLevel() const;
    int getExp() const;
    void setLevel(int level);
    void setExp(int exp);
};