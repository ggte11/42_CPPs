#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << meta->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	meta->makeSound();
	cat->makeSound();
	dog->makeSound();
	delete meta;
	delete cat;
	delete dog;
	std::cout << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongAnimal = new WrongAnimal();

	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongAnimal->getType() << std::endl;
	wrongMeta->makeSound();
	wrongAnimal->makeSound();
	delete wrongMeta;
	delete wrongAnimal;
	std::cout << std::endl;

	WrongCat wrongCat;
	wrongCat.makeSound();
	std::cout << wrongCat.getType() << std::endl;
	return 0;
}