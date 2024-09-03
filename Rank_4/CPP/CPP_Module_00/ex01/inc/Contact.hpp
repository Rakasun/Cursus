/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:09:36 by yfang             #+#    #+#             */
/*   Updated: 2024/08/23 14:16:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

# define RESET "\033[0;m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define BOLD "\033[1m"
# define END "\033[0m"

class	Contact{
	private:
		std::string data[5];
  public:
      Contact();
      ~Contact();
      std::string getData(int index) const { return data[index]; }
      bool    set_data();
};

#endif