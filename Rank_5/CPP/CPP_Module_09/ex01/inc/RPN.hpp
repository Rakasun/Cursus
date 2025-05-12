/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:31:48 by yfang             #+#    #+#             */
/*   Updated: 2025/04/23 17:28:56 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>

class RPN {
    private:
        std::stack<int> _stack;

        bool    isOperator(char c);
        void    applyOperator(char c);
    public:
        RPN(void);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN(void);
        
        int evaluate(const std::string &expression);
};

#endif