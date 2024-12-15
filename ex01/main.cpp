#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "____________________________________________________" << std::endl;

	const Animal  *meta[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << "------Animal[" << i << "] is a Dog------" << std::endl;
			meta[i] = new(std::nothrow) Dog();
			if (meta[i] == NULL)
			{
				std::cout << "Failed to allocate memory" << std::endl;
				return 1;
			}
		}
		else
		{
			std::cout << "------Animal[" << i << "] is a Cat------" << std::endl;
			meta[i] = new(std::nothrow) Cat();
			if (meta[i] == NULL)
			{
				std::cout << "Failed to allocate memory" << std::endl;
				return 1;
			}
		}
	}

	std::cout << "____________________________________________________" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "------Animal[" << i << "] is a " << meta[i]->getType()<< "------" << std::endl;
		meta[i]->makeSound();
	}

	std::cout << "____________________________________________________" << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "------Deleting Animal[" << i << "]------" << std::endl;
		delete meta[i];
	}

	std::cout << "____________________________________________________" << std::endl;

	Cat *a = new Cat();

	std::cout << "------Setting ideas------" << std::endl;

	a->setIdeas(0, "Idea 0");
	a->setIdeas(1, "Idea 1");
	a->setIdeas(2, "Idea 2");
	a->setIdeas(99, "Idea 99");
	a->setIdeas(100, "Idea 100");

	std::cout << "------Getting ideas------" << std::endl;

	a->getIdeas(0);
	a->getIdeas(1);
	a->getIdeas(2);
	a->getIdeas(99);
	a->getIdeas(100);

	a->getBrainAddress();

	std::cout << "------Copy Construct-----" << std::endl;

	Cat *b = new Cat(*a);

	std::cout << "------Getting ideas------" << std::endl;

	b->getIdeas(0);
	b->getIdeas(1);
	b->getIdeas(2);
	b->getIdeas(99);
	b->getIdeas(100);

	b->getBrainAddress();
	
	std::cout << "<a's brain address is not equal to b's brain address>" << std::endl;

	std::cout << "____________________________________________________" << std::endl;

	delete a;
	delete b;

	std::cout << "____________________________________________________" << std::endl;

	Dog basic;
	basic.setIdeas(0, "I want to play");
	Dog tmp = basic;
	tmp.getIdeas(0);
	tmp.setIdeas(0, "I want to sleep");

	std::cout << "--------------DEEP COPY TEST-------------------" << std::endl;
	tmp.getIdeas(0);
	basic.getIdeas(0);
	std::cout << "the two ideas above must be different." << std::endl;

	std::cout << "____________________________________________________" << std::endl;


	return 0;
}