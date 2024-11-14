#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

// up castするが，Dog class 特有の変数はないため初期化の必要なし
Dog::Dog(const Dog &copy) : Animal(copy){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy){
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wooh" << std::endl;
}

