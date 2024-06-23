#include "Bank.hpp"
#include "Account.hpp"

int main()
{
	Account accountA = Account();
	accountA.setId(0);
	accountA.setValue(100);

	Account accountB = Account();
	accountB.setId(1);
	accountB.setValue(100);

	Bank bank = Bank();
	bank.setLiquidity(999);
	bank.addClientAccount(&accountA);
	bank.addClientAccount(&accountB);

	bank.decreaseLiquidity(200);
	accountA.increaseValue(400);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
