#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "------------------Basic creation and deletion--------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "-----------------------Deep copy---------------------------------" << std::endl;
	Dog* doggy = new Dog();
	doggy->setIdeas(0, "FOOD");
	doggy->setIdeas(1, "WALK");
	Dog* husky = new Dog(*doggy);
	std::cout << "Doggy thinks: " << doggy->getIdeas(0) << std::endl;
	std::cout << "Husky thinks: " << husky->getIdeas(0) << std::endl;
	delete doggy;
	std::cout << "Husky still thinks: " << husky->getIdeas(0) << std::endl;
	delete husky;

	std::cout << "-------------------------Array of animals------------------------" << std::endl;
	Animal* creatures[5];

	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0) {
			creatures[i] = new Dog();
			static_cast<Dog*>(creatures[i])->setIdeas(0, "WALK");
		}
		else {
			creatures[i] = new Cat();
			static_cast<Cat*>(creatures[i])->setIdeas(0, "FOOD");
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0)
			std::cout << "Dog " << i + 1 << " is thinking about " << static_cast<Dog*>(creatures[i])->getIdeas(0) << std::endl;
		else
			std::cout << "Cat " << i + 1 << " is thinking about " << static_cast<Cat*>(creatures[i])->getIdeas(0) << std::endl;
		std::cout << "Animal " << i + 1 << " says ";
		creatures[i]->makeSound();
		delete creatures[i];
	}
	return 0;
}