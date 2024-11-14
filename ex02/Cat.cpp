#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
, brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

// no need to address with the case that new() failed
Cat::Cat(const Cat &copy)
: Animal(copy) // up cast
, brain(new Brain(*copy.brain)) // deep copy
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	delete brain;
	brain = new Brain(*copy.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::getBrainAddress() const
{
	std::cout << "Brain address: " << brain << std::endl;
}

void Cat::getIdeas(size_t index) const
{
	if(index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	std::cout << "Idea[" << index << "]: " << brain->getIdea(index) << std::endl;
}

void Cat::setIdeas(size_t index, const std::string &idea)
{
	brain->setIdea(index, idea);
}