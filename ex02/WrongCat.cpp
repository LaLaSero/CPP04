#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
, brain(new Brain())
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
	delete brain;
}

// no need to address with the case that new() failed
WrongCat::WrongCat(const WrongCat &copy)
: WrongAnimal(copy) // up cast
, brain(new Brain(*copy.brain)) // deep copy
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	WrongAnimal::operator=(copy);
	delete brain;
	brain = new Brain(*copy.brain);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "<wrong> Me0w Me0w" << std::endl;
}

void WrongCat::getBrainAddress() const
{
	std::cout << "Brain address: " << brain << std::endl;
}

void WrongCat::getIdeas(size_t index) const
{
	if(index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	std::cout << "Idea[" << index << "]: " << brain->getIdea(index) << std::endl;
}

void WrongCat::setIdeas(size_t index, const std::string &idea)
{
	brain->setIdea(index, idea);
}


