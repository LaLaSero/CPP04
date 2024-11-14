#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);

		virtual void makeSound() const;

		void getBrainAddress() const;
		void getIdeas(size_t index) const;
		void setIdeas(size_t index, const std::string &idea);

	private:
		std::string type;
		Brain *brain;

};