#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy){
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "<Wrong> Me0w Me0w" << std::endl;
}

