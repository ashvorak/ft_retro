/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:35:40 by oshvorak          #+#    #+#             */
/*   Updated: 2018/06/24 18:25:24 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"
#include "../inc/Game.hpp"
#include "../inc/Enemy.hpp"

Game::Game() {
	this->w = 100;
	this->h = 50;
	this->s = 0;
	this->bonus = 0;
	this->ammo = BULLET_NUM;
	this->fps = 15;
	this->lives = 3;
	p1 = new Player(this->w / 2, this->h - 2);
}

Game::Game(const Game &copy) {
	*this = copy;
}

Game 		&Game::operator=(const Game &src) {
	this->w = src.w;
	this->h = src.h;
	this->s = src.s;
	this->bonus = src.bonus;
	this->ammo = src.ammo;
	this->fps = src.fps;
	this->lives = src.lives;
	delete this->p1;
	this->p1 = src.p1;
	this->it = src.it;
	for (int i = 0; i < ENEMY_NUM; i++){
		this->em[i] = src.em[i];
	}
	for (int i = 0; i < BULLET_NUM; i++){
		this->bullet[i] = src.bullet[i];
	}	
	return *this;
}

Game::~Game() {
	delete p1;
}

void Game::init() {
	initscr();
	curs_set(0);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	attron(A_BOLD);
	refresh();

	getmaxyx(stdscr, h, w);
	p1->setPosition(w/2, h - 2);

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
}

void Game::info(WINDOW *win, int key, int s) {
	clear(); 
	refresh();
	wattron(win, A_BOLD | COLOR_PAIR(1));
	key = 0;
	box(win, 0, 0);

	color_set(3, NULL);
	mvprintw(1, 1, "Lifes: %d", lives);

	color_set(4, NULL);
	mvprintw(1, 12, "Ammo: %d", ammo);

	color_set(2, NULL);
	mvprintw(1, 23, "SCORE: %d", s);

	color_set(0, NULL);
	mvprintw(1, COLS - 17, "Press q to quit");
	wrefresh(win);
}

void Game::launch(){
	init();
	nodelay(stdscr, FALSE);
	mvprintw(LINES / 2 - 2, COLS / 2 - 6, "WELCOMES YOU");
	mvprintw(LINES / 2, COLS / 2 - 12, "PRESS ENTER TO CONTINUE");
	mvprintw(1, COLS - 17, "Press q to quit");
	int ch;
	if((ch = getch()) != 'q')
	{
		nodelay(stdscr, TRUE);
		play();
	} else {
		clear();
		mvprintw(LINES / 2, COLS / 2 - 4, "GOODBYE");
		refresh();
		sleep(2);
	}
	attroff(A_BOLD);
	endwin();
}

void Game::game_over(WINDOW *win) {
	clear();
	mvprintw(LINES / 2 - 2, COLS / 2 - 4, "GAME OVER");
	mvprintw(LINES / 2, COLS / 2 - 5, "SCORE: %d", this->s);
	mvprintw(LINES / 2 + 2, COLS / 2 - 10, "PRESS ENTER TO RESTART");
	refresh();
    int ch;

    while((ch = getch()) != 'q')
    {
    	if (ch == 10)
	    {
	    	this->s = 0;
	    	this->fps = 15;
			this->lives = 3;
	    	it.setStatus(false);
			for (int i = 0; i < BULLET_NUM; i++) {
				this->bullet[i].setOnLine(false);
				this->bullet[i].setAv(true);
			}
	    	this->ammo = BULLET_NUM;
	    	initEnemy();
	    	this->p1->setPosition(w / 2, h - 2);
	    	return ;
    	}
    }
	clear();
	mvprintw(LINES / 2, COLS / 2 - 4, "GOODBYE");
	refresh();
	sleep(2);
	delwin(win);
	endwin();
	exit(0);
}

void Game::play() {
	char ch;
	clock_t t1;
	clock_t t2 = 0;

	initEnemy();
	WINDOW *win = newwin(3, w, 0, 0);
	while((ch = getch()) != 'q')
	{
		t1 = clock() / (CLOCKS_PER_SEC / fps);
		movePlayer(p1, ch);
		if (t1 > t2) {
			t2 = t1;

			if (s > 0 && s % 500 == 0)
			{
				fps += 5;
			}

			s++;
			moveEnemy(em);
			moveBullet(bullet);
			info(win, ch, s);
			checkCollision(em, bullet);
			color_set(2, NULL);
			p1->print(this->p1->getY(), this->p1->getX(), "^");
			color_set(0, NULL);
			printArr(em);
			printArr(bullet);
			if (it.getStatus())
				it.print(it.getY(), it.getX(), "?");
		}
		
		if (this->s > 0 && this->s % 150 == 0)
		{
			it.setPosition(rand() % this->w + 4, rand() % (this->h - 3) + 3);
			it.setStatus(true);
		}
		if (checkCollision(p1, em)) {
			if (lives == 1) {
				game_over(win);
				t1 = 0;
				t2 = 0;
			} else {
				lives--;
			}
		}
		refresh();
	}
	delwin(win);
	endwin();

}

void Game::movePlayer(Player *p, int key) {

	switch(key) {
		case ' ':
				for (int i = 0; i < BULLET_NUM && ammo > 0; i++)
				{
					if (this->bullet[i].getAv() == true)
					{
						this->bullet[i].setOnLine(true);
						this->bullet[i].setAv(false);
						this->bullet[i].setMove(p->getX(), p->getY() - 1);
						ammo--;
						break;
					}
				}
				break;
			case 2:
				if (p->getY() + 1 <= this->h - 2)
					p->move(0, 1);
				break;
			case 3:
				if (p->getY() - 1 >= 3)
					p->move(0, -1);
				break;
			case 4:
				if (p->getX() - 1 >= 2)
					p->move(-1, 0); 
				break;
			case 5:
				if (p->getX() + 1 < w - 2)
					p->move(1, 0);
				break;
		}

}	

void Game::moveEnemy(Enemy *em) {
	for(int j = 0; j < ENEMY_NUM; j++) {
		if (em[j].getDelay() == 0)
		{
			if (em[j].getY() + 2 == this->h)
				em[j].setNewEnemy(this->w);
			else {
				if (em[j].getX() > 2 && em[j].getX() < w - 1)
				{
					int n_rand = rand() % 10;
					if (n_rand == 0)
						em[j].move(rand() % 3 - 1, 1);
					else
						em[j].move(0, 1);
				}
	     		else
	        		em[j].move(0, 1);
			}
		}
		else
			em[j].setDelay(em[j].getDelay() - 1);	
	}
}

void Game::moveBullet(Bullet *bullet) {
	for(int j = 0; j < BULLET_NUM; j++) {
		if (this->bullet[j].getOnLine())
		{
			if (this->bullet[j].getY() - 1 >= 2)
				bullet[j].move(0, -1);
			else
			{
				bullet[j].setOnLine(false);
				bullet[j].setPosition(0, 0);
			}
		}	
	}
}

bool Game::checkCollision(Player *p1, Enemy em[]) {
	int x = p1->getX();
	int y = p1->getY();
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (em[i].getX() == x && em[i].getY() == y)
		{
			em[i].setNewEnemy(this->w);
			return (1);	
		}
	}
	if (x == this->it.getX() && y == this->it.getY())
	{
		it.setStatus(false);
		for (int i = 0; i < BULLET_NUM; i++)
			this->bullet[i].setAv(true);
		ammo = BULLET_NUM;
	}
	return (0);
}

void Game::checkCollision(Enemy *em, Bullet *bullet) {
	for (int i = 0; i < ENEMY_NUM; i++) 
	{
		if (em[i].getDelay() == 0) 
		{
			for (int j = 0; j < BULLET_NUM; j++) 
			{
				if (bullet[j].getOnLine())
				{
					if (em[i].getX() == bullet[j].getX() && (em[i].getY() == bullet[j].getY() 
					|| em[i].getY() == bullet[j].getY() + 1))
					{
						em[i].setNewEnemy(this->w);
						bullet[j].setOnLine(false);
						bullet[j].setPosition(0, 0);
						this->s += 10;
					}
				}	
			}
		}
	}
}

void Game::printArr(Enemy em[]) {
	for(int j = 0; j < ENEMY_NUM; j++)
		if (em[j].getDelay() == 0) {
			color_set(3, NULL);
			em[j].print(em[j].getY(), em[j].getX(), "X");
			color_set(0, NULL);
		}
}

void Game::printArr(Bullet bullet[]) {
	for(int j = 0; j < BULLET_NUM; j++)
		if (bullet[j].getOnLine() == true){
			color_set(4, NULL);
			bullet[j].print(bullet[j].getY(), bullet[j].getX(), "!");
			color_set(0, NULL);
		}
}

void Game::initEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++)
		em[i].setNewEnemy(this->w);
}
