#include "Dog.hpp"

Dog::Dog()
: Animal("Dog")
, brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

// no need to address with the case that new() failed
Dog::Dog(const Dog &copy)
: Animal(copy) // up cast
, brain(new Brain(*copy.brain)) // deep copy
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	delete brain;
	brain = new Brain(*copy.brain);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wooh" << std::endl;
}

void Dog::getBrainAddress() const
{
	std::cout << "Brain address: " << brain << std::endl;
}

void Dog::getIdeas(size_t index) const
{
	if(index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	std::cout << "Idea[" << index << "]: " << brain->getIdea(index) << std::endl;
}

void Dog::setIdeas(size_t index, const std::string &idea)
{
	brain->setIdea(index, idea);
}