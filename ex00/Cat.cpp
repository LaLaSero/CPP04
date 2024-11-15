#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

// up castするが，cat class 特有の変数はないため初期化の必要なし
Cat::Cat(const Cat &copy) : Animal(copy){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy){
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	type = copy.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

