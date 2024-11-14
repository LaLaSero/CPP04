#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string const &type) : type(type){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "<Wrong> Animal sounds" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return this->type;
}