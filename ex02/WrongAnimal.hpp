#pragma once

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(std::string const &type="WrongAnimal");
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);

		virtual void makeSound() const;

		const std::string& getType() const;

	protected:
		std::string type;
};