/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:45:25 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 18:27:11 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_H
# define BULLET_H

#include "Element.hpp"

class Bullet : public Element {
	
	private :
		bool _av;
		bool _on_line;

	public:
		Bullet();
		Bullet(int x, int y);
		Bullet(const Bullet &copy);
		Bullet & operator=(const Bullet &src);
		~Bullet();

		bool	getOnLine();
		void	setOnLine(bool bl);
		bool	getAv();
		void	setAv(bool bl);
		void 	setMove(int x, int y);
};

#endif