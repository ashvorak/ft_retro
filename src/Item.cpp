/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:35:40 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 18:25:24 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Item.hpp"

Item::Item() {
	this->_x = 0;
	this->_y = 0;
	this->_st = false;
}

Item::Item(int x, int y) {
	
	this->_x = x;
	this->_y = y;
	this->_st = false;

}

Item::Item(const Item &copy) {
	*this = copy;
}

Item & Item::operator=(Item const &src) {
	if (this == &src)
		return (*this);
	this->_x = src._x;
	this->_y = src._y;
	this->_st = src._st;
	return (*this);
}

Item::~Item() {
	
}

void	Item::setStatus(bool st) {
	this->_st = st;
}

bool	Item::getStatus() {
	return this->_st;
}