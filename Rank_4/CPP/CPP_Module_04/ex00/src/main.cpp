/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:26:50 by yfang             #+#    #+#             */
/*   Updated: 2024/10/04 11:09:39 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

int main(void) {
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	// meta = i;	
	// meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal*	wa = new WrongAnimal();
	const WrongCat*		wc = new WrongCat();

	wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;
	return 0;
}
