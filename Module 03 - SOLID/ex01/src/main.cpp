#include "command.hpp"
#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"

int main()
{
    Command *command = new Command();
    command->setDate("Thuesday");
    command->setClient("John Doe");
    
    for (int i = 0; i < 200; i++)
    {
        command->addArticle("Apple", 1);
    }

    std::cout << "Total price: " << command->get_total_price() << std::endl;

    PackageReductionDiscountCommand *packageReductionDiscountCommand = new PackageReductionDiscountCommand();
    packageReductionDiscountCommand->setDate("Thuesday");
    packageReductionDiscountCommand->setClient("John Doe");

    for (int i = 0; i < 200; i++)
    {
        packageReductionDiscountCommand->addArticle("Apple", 1);
    }

    std::cout << "Total price with package reduction discount: " << packageReductionDiscountCommand->get_total_price() << std::endl;

    ThuesdayDiscountCommand *thuesdayDiscountCommand = new ThuesdayDiscountCommand();
    thuesdayDiscountCommand->setDate("Thuesday");
    thuesdayDiscountCommand->setClient("John Doe");

    for (int i = 0; i < 200; i++)
    {
        thuesdayDiscountCommand->addArticle("Apple", 1);
    }

    std::cout << "Total price with Thuesday discount: " << thuesdayDiscountCommand->get_total_price() << std::endl;

    delete command;
    delete packageReductionDiscountCommand;
    delete thuesdayDiscountCommand;

    return 0;
}