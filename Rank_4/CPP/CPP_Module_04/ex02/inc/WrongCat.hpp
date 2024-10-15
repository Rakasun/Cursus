/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:30:29 by yfang             #+#    #+#             */
/*   Updated: 2024/10/03 16:30:29 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        WrongCat(void);
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat &other);
        virtual ~WrongCat(void);

        void    makeSound(void) const;
};

#endif
