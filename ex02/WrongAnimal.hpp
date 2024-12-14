#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(std::string const &type="WrongAnimal");
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);

		void makeSound() const;

		const std::string& getType() const;

	protected:
		std::string type;
};