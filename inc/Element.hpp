/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:49:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 17:43:20 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

#include <ncurses.h>
#include <string>

class Element {

	protected:	
		int _x;
		int _y;
		
	public:
		Element();
		Element(int x, int y);
		Element(const Element &copy);
		Element & operator=(const Element &src);
		~Element();

		void 	setPosition(int x, int y);
		int		getX();
		int		getY();
		void	move(int dx, int dy);
		void	print(int y, int x, const char *s);


};

#endif