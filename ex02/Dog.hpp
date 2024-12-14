#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);

		void makeSound() const;

		void getBrainAddress() const;
		void getIdeas(size_t index) const;
		void setIdeas(size_t index, const std::string &idea);

	private:
		std::string type;
		Brain *brain;
	
};