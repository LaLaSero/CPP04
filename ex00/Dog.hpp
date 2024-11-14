#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);

		virtual void makeSound() const;

	private:
		std::string type;
	
};