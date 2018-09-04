/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:51:35 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/23 21:32:39 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Element.hpp"

Element::Element() {
	
}

Element::Element(int x, int y) : _x(x), _y(y) {
	
}

Element::Element(const Element &copy) {
	*this = copy;
}

Element & Element::operator=(Element const &src) {
	if (this == &src)
		return (*this);
	this->_x = src._x;
	this->_y = src._y;
	return (*this);
}

Element::~Element() {
	
}

void Element::setPosition(int x, int y) {
	this->_x = x;
	this->_y = y;
}

int Element::getX() { return this->_x;}

int Element::getY() { return this->_y;}

void Element::move(int dx, int dy){
	this->_x += dx;
	this->_y += dy;
}

void Element::print(int y, int x, const char *s) {
	mvprintw(y, x, s);
}