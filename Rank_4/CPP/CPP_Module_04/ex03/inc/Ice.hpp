/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:06:39 by yfang             #+#    #+#             */
/*   Updated: 2024/10/10 16:11:51 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "Character.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        ~Ice();

        AMateria    *clone(void) const;
        void        use(ICharacter &target);
};

#endif