#include "Cat.hpp"

Cat::Cat()
: Animal("Cat")
, brain(new(std::nothrow) Brain())
{
	if (!brain) {
		std::cerr << "Failed to allocate Brain, exiting." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

// no need to address with the case that new() failed
Cat::Cat(const Cat &copy)
: Animal(copy) // up cast
, brain(new(std::nothrow) Brain(*copy.brain)) // deep copy
{
	if (!brain) {
		std::cerr << "Failed to allocate Brain, exiting." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this == &copy)
		return *this;
	Animal::operator=(copy);
	delete brain;
	brain = new(std::nothrow) Brain(*copy.brain);
	if (!brain) {
		std::cerr << "Failed to allocate Brain, exiting." << std::endl;
		exit(EXIT_FAILURE);
	}
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
	if(index >= MAX_IDEAS)
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
