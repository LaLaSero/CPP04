#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);

		virtual void makeSound() const;

		void getBrainAddress() const;
		void getIdeas(size_t index) const;
		void setIdeas(size_t index, const std::string &idea);

	private:
		std::string type;
		Brain *brain;

};