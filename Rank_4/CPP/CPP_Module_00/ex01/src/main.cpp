/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:59:07 by yfang             #+#    #+#             */
/*   Updated: 2024/08/08 17:08:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

int main(void) {
	Phonebook	phonebook;
    std::string input;
	int			flag = 1;

    while (flag) {
        std::cout << "OPTIONS:" << std::endl << "-ADD    -SEARCH    -EXIT"
		<< std::endl << std::endl;
        if (!std::getline(std::cin, input, '\n'))
	    	return (0);
    	if (input == "ADD" || input == "add")
			flag = phonebook.new_contact();
		if (input == "SEARCH" || input == "search")
			flag = phonebook.show_contact(phonebook.search_contact());
        if (input == "EXIT" || input == "exit")
            break ;
	}
	return (0);
}
