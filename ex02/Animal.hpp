#pragma once

#include <iostream>
#include <cstdlib>

class Animal
{
	public:
		Animal(std::string const &type="Animal");
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);

		virtual void makeSound() const = 0;

		const std::string& getType() const;

	protected:
		std::string type;
};