/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:05:06 by yfang             #+#    #+#             */
/*   Updated: 2024/08/08 17:03:17 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	Phonebook{
	private:
		Contact	contacts[8];
		int		index;
		int		flag;
	public:
		Phonebook();
		~Phonebook();
		bool	new_contact();
		int		search_contact();
		bool	show_contact(int index);
};

#endif