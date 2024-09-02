#pragma once

#include <iostream>
#include <vector>

template <typename T>
class ListSingleton
{
private:
    std::vector<T*> list;
    ListSingleton() {}

public:
    ListSingleton(const ListSingleton&) = delete;
    ListSingleton& operator=(const ListSingleton&) = delete;

    static ListSingleton *getInstance()
    {
        static ListSingleton<T> instance;
        return &instance;
    }

    void add(T *item)
    {
        list.push_back(item);
    }

    bool remove(T *item)
    {
        for (auto it = list.begin(); it != list.end(); it++)
        {
            if (*it == item)
            {
                delete *it;
                list.erase(it);
                return true;
            }
        }
        return false;
    }

    void print()
    {
        for (auto item : list)
        {
            std::cout << *item << std::endl;
        }
    }

    void clear() {
        for (auto& item : list) {
            delete item;  // Delete all objects
        }
        list.clear();
    }

    ~ListSingleton() {
        clear();
    }

};