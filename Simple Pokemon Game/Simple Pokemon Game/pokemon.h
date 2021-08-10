#pragma once
#include <iostream>
using namespace std;
class pokemon {
private:
	int hp;
	int playerNum;
	int x;
	int y;
	char type;
public:
	//Constuctor
	pokemon(int pNum) { 
		playerNum = pNum;
		hp = 3;
		x = 8 * (playerNum - 1);
		y = 0;
	}
	~pokemon() {}
	/*Operating pokemon's movement*/
	bool move(char c, int(*field)[9]) {
		{
			if (c == 'U' || c == 'u') {
				if (y > 0) {
					if (field[y + 1][x] != 1) {
						field[y][x] = 0;
						y--;
						field[y][x] = 1;
						return true;
					}
					else
						return false;
				}
				else if (y == 0)
					return false;
			}
			else if (c == 'D' || c == 'd') {
				if (y <8) {
					if (field[y - 1][x] != 1) {
						field[y][x] = 0;
						y++;
						field[y][x] = 1;
						return true;
					}
					else
						return false;
				}
				else if (y == 8)
					return false;
			}
			else if (c == 'R' || c == 'r') {
				if (x < 8) {
					if (field[y][x + 1] != 1) {
						field[y][x] = 0;
						x++;
						field[y][x] = 1;
						return true;
					}
					else
						return false;
				}
				else if (x == 8)
					return false;
			}
			else if (c == 'L' || c == 'l') {
				if (x > 0) {
					if (field[y][x - 1] != 1) {
						field[y][x] = 0;
						x--;
						field[y][x] = 1;
						return true;
					}
					else
						return false;
				}
				else if (x == 0)
					return false;
			}
		}
	}
	/*About attack method will be used in derived class, so decalre as virtual method
	First, Attack_boundary check yes or no of the enemy's pokemon in the attack boundary
	If Attack_boundary is true->
	Second, Attack check enemy's pokemon's coordinate in the attack boundary*/
	virtual bool Attack(char direction, int x, int y) = 0; //Check x, y is in the of pokemon's attack boundary
	virtual bool Attack_boundary(int(*field)[9], char direction) = 0; //Check Yes or No of enemy's pokemon in the pokemon's attack boundary

	int get_hp() {
		return hp;
	}
	int get_x() {
		return x;
	}
	int get_y() {
		return y;
	}
	void set_hp(int hp) {
		this->hp -= hp;
	}
	void set_y(int num) {
		this->y = num;
	}
	void set_type(char type) {
		this->type = type;
	}
};

class Charmander : public pokemon
{
private:

public:
	Charmander(int pNum) :pokemon(pNum) {
		set_y(1);
		set_type('F');
	}

	bool Attack_boundary(int(*field)[9], char direction) {
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;

		if (field[get_y()][get_x() + dir] == 1 || field[get_y() + 1][get_x() + dir] == 1 || field[get_y() - 1][get_x() + dir] == 1 || field[get_y() + 1][get_x() + 2 * dir] == 1 || field[get_y() - 1][get_x() + 2 * dir] == 1)
			return true;
		else
			return false;
	}
	bool Attack(char direction, int x, int y)
	{
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;
		else return false;
		if ((get_x() + dir == x && get_y() == y) || (get_x() + dir == x && get_y() + 1 == y) || (get_x() + dir == x && get_y() - 1 == y) || (get_x() + 2 * dir == x && get_y() + 1 == y) || (get_x() + 2 * dir == x && get_y() - 1 == y))
			return true;
		else
			return false;
	}

};

class Squirtle : public pokemon
{
private:

public:
	Squirtle(int pNum) :pokemon(pNum) {
		set_y(3);
		set_type('W');
	}

	bool Attack_boundary(int(*field)[9], char direction) {
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;

		if (field[get_y()][get_x() + dir] == 1 || field[get_y() + 1][get_x()] == 1 || field[get_y() - 1][get_x()] == 1 || field[get_y()][get_x() + 2 * dir] == 1)
			return true;
		else
			return false;
	}
	bool Attack(char direction, int x, int y)
	{
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;
		if ((get_x() == x && get_y() + 1 == y) || (get_x() == x && get_y() - 1 == y) || (get_x() + dir == x && get_y() == y) || (get_x() + 2 * dir == x && get_y() == y))
			return true;
		else 
			return false;
	}


};

class Bulbasaur : public pokemon
{
private:

public:
	Bulbasaur(int pNum) :pokemon(pNum) {
		set_y(7);
		set_type('G');
	}

	bool Attack_boundary(int(*field)[9], char direction) {
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;

		if (field[get_y() + 1][get_x()] == 1 || field[get_y() - 1][get_x()] == 1 || field[get_y()][get_x() + dir] == 1 || field[get_y() + 1][get_x() + dir] == 1 || field[get_y() - 1][get_x() + dir] == 1)
			return true;
		else 
			return false;
	}
	bool Attack(char direction, int x, int y)
	{
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;
		if ((get_x() == x && get_y() + 1 == y) || (get_x() == x && get_y() - 1 == y) || (get_x() + dir == x && get_y() + 1 == y)  || (get_x() + dir == x && get_y() == y) || (get_x() + dir == x && get_y() - 1 == y))
			return true;
		else 
			return false;
	}
};

class Pikachu : public pokemon
{
private:

public:
	Pikachu(int pNum) :pokemon(pNum) {
		set_y(5);
		set_type('E');
	}

	bool Attack_boundary(int(*field)[9], char direction) {
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;

		if (field[get_y()][get_x() + dir] == 1 || field[get_y()][get_x() + 2 * dir] == 1 || field[get_y() + 1][get_x() + 2 * dir] == 1 || field[get_y() - 1][get_x() + 2 * dir] == 1)
			return true;
		else 
			return false;
	}
	bool Attack(char direction, int x, int y)
	{
		int dir = 1;
		if (direction == 'R' || direction == 'r')
			dir = 1;
		else if (direction == 'L' || direction == 'l')
			dir = -1;
		if ((get_x() + dir == x && get_y() == y) || (get_x() + 2 * dir == x && get_y() + 1 == y) || (get_x() + 2 * dir == x && get_y() == y - 1) || (get_x() + 2 * dir == x && get_y() == y))
			return true;
		else 
			return false;
	}
};