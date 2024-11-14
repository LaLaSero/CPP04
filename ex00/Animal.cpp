#include "Animal.hpp"

Animal::Animal(std::string const &type) : type(type){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy){
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sounds" << std::endl;
}

const std::string& Animal::getType() const
{
	return this->type;
}