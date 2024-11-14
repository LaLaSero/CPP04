#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "____________________________________________________" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "____________________________________________________" << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "____________________________________________________" << std::endl;

	delete meta;
	delete j;
	delete i;

	std::cout << "____________________________________________________" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();

	std::cout << "____________________________________________________" << std::endl;

	std::cout << j2->getType() << " " << std::endl;

	j2->makeSound();
	meta2->makeSound();

	std::cout << "____________________________________________________" << std::endl;

	delete meta2;
	delete j2;

	return 0;
}