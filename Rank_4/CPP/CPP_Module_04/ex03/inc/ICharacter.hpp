/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:02:54 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 18:33:58 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICharacter_HPP
# define ICharacter_HPP

# include "AMateria.hpp"

class ICharacter {
    public:
        virtual ~ICharacter(void) {}
        virtual std::string const   &getName(void) const = 0;
        virtual void                equip(AMateria *m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif
