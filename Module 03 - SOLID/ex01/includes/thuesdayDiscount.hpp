
#pragma once

#include <iostream>
#include "command.hpp"

#define THUESDAY_DISCOUNT_PERCENTAGE 0.1

class ThuesdayDiscountCommand : public Command
{

public:
    int get_total_price() const
    {
        int total_price = Command::get_total_price();

        if (this->date == "Thuesday")
        {
            total_price -= total_price * THUESDAY_DISCOUNT_PERCENTAGE;
        }
        return total_price;
    }

    virtual ~ThuesdayDiscountCommand() {}
};