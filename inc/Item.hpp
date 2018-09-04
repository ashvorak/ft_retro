/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:30:50 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 18:10:54 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

#include "Element.hpp"
#include <ctime>

class Item : public Element {

	public: 
		Item();
		Item(int x, int y);
		Item(const Item &copy);
		Item & operator=(const Item &src);
		~Item();

		void setStatus(bool st);
		bool getStatus();

	private:
		bool 	_st;
		
};

#endif