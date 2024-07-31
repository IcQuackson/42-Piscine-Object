
#pragma once

#include <iostream>

#define MAX_ARTICLES 200

struct Article
{
    std::string name;
    int quantity;
};

class Command
{
protected:
    int id;
    std::string date;
    std::string client;
    Article articles[MAX_ARTICLES];

public:
    virtual int get_total_price() const
    {
        int total_price = 0;
        for (int i = 0; i < MAX_ARTICLES; i++)
        {
            total_price += articles[i].quantity;
        }
        return total_price;
    }

    void setDate(std::string date)
    {
        this->date = date;
    }

    void setClient(std::string client)
    {
        this->client = client;
    }

    void addArticle(std::string name, int quantity)
    {
        for (int i = 0; i < MAX_ARTICLES; i++)
        {
            if (articles[i].name.empty())
            {
                articles[i].name = name;
                articles[i].quantity = quantity;
                break;
            }
        }
    }

    virtual ~Command() {}
};