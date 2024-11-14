#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

// assignよりもdirect copyの方がeffective
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < MAX_IDEAS; i++)
		this->ideas[i].assign(other.ideas[i]);
	return *this;
}

const std::string& Brain::getIdea(size_t index) const
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return this->ideas[0];
	}
	return this->ideas[index];
}

const std::string* Brain::getIdeaAddress(size_t index) const
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return &this->ideas[0];
	}
	return &this->ideas[index];
}

void Brain::setIdea(size_t index, const std::string &idea)
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cerr << "Index out of range" << std::endl;
		return ;
	}
	this->ideas[index].assign(idea);
}


