
#pragma once

#include <iostream>
#include "command.hpp"

#define PACKAGE_REDUCTION_DISCOUNT_FIXED_VALUE 10

class PackageReductionDiscountCommand : public Command
{

public:
    int get_total_price() const
    {
        int total_price = Command::get_total_price();

        if (Command::get_total_price() > 150)
        {
            total_price -= PACKAGE_REDUCTION_DISCOUNT_FIXED_VALUE;
        }
        return total_price;
    }

    virtual ~PackageReductionDiscountCommand() {}
};