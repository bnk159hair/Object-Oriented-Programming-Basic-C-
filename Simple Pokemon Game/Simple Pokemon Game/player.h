#pragma once
#include "pokemon.h"
#include <cstring>
#include <windows.h> 

class player
{
private:
	Charmander* C;
	Squirtle* S;
	Bulbasaur* B;
	Pikachu* P;
	char* name;
	int playerNumber;
public:
	player(int pNum) {
		name = new char[strlen("player1")];
		if (pNum == 1)
			strcpy_s(name, 10, "player1\0");
		else if (pNum == 2)
			strcpy_s(name, 10, "player2\0");
		playerNumber = pNum;
		C = new Charmander(playerNumber);
		S = new Squirtle(playerNumber);
		B = new Bulbasaur(playerNumber);
		P = new Pikachu(playerNumber);
	}
	player(char* N, int pNum) {
		name = new char[strlen(N)];
		strcpy_s(name, 10, N);
		playerNumber = pNum;
		C = new Charmander(playerNumber);
		S = new Squirtle(playerNumber);
		B = new Bulbasaur(playerNumber);
		P = new Pikachu(playerNumber);
	}
	~player()
	{
		if (C == NULL && S == NULL && B == NULL && P == NULL)
			cout << name << " Lose." << endl;
		else
			cout << name << " Win!!" << endl;
	}
	void delC() {
		delete C;
		C = NULL;
	}
	void delS() {
		delete S;
		S = NULL;
	}
	void delB() {
		delete B;
		B = NULL;
	}
	void delP() {
		delete P;
		P = NULL;
	}
	char* getName() {
		return name;
	}
	void color(unsigned short color) //For pokemon's color
	{
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hCon, color);
	}

	void print(int j, int i) {
		if (playerNumber == 1) { //When player1
			if (C == NULL);
			else if (j == C->get_x() && i == C->get_y())
			{
				color(12);
				cout << "C1";
				color(15);
			}
			if (S == NULL);
			else if (j == S->get_x() && i == S->get_y())
			{
				color(9);
				cout << "S1";
				color(15);
			}
			if (B == NULL);
			else if (j == B->get_x() && i == B->get_y())
			{
				color(10);
				cout << "B1";
				color(15);
			}
			if (P == NULL);
			else if (j == P->get_x() && i == P->get_y())
			{
				color(14);
				cout << "P1";
				color(15);
			}
		}
		else if (playerNumber == 2) { //When player2
			if (C == NULL);
			else if (j == C->get_x() && i == C->get_y())
			{
				color(12);
				cout << "C2";
				color(15);
			}
			if (S == NULL);
			else if (j == S->get_x() && i == S->get_y())
			{
				color(9);
				cout << "S2";
				color(15);
			}
			if (B == NULL);
			else if (j == B->get_x() && i == B->get_y())
			{
				color(10);
				cout << "B2";
				color(15);
			}
			if (P == NULL);
			else if (j == P->get_x() && i == P->get_y())
			{
				color(14);
				cout << "P2";
				color(15);
			}
		}
	}
	void HPprint() { 
		cout << "C : ";
		if (C != NULL)
			cout << C->get_hp();
		else
			cout << "X";
		cout << "   S : ";
		if (S != NULL)
			cout << S->get_hp();
		else
			cout << "X";
		cout << "   B : ";
		if (B != NULL)
			cout << B->get_hp();
		else
			cout << "X";
		cout << "   P : ";
		if (P != NULL)
			cout << P->get_hp() << endl;
		else
			cout << "X" << endl;
	}
	void battle(int(*field)[9], player* n, int sel, char direction) {
		if (sel == 1) { //When Charmander
			if (C->Attack_boundary(field, direction) == true) {
				if (n->getC() == NULL);
				else if (C->Attack(direction, n->getC()->get_x(), n->getC()->get_y()) == true) {
					cout << name << "의 파이리의 불꽃공격!" << endl;
					n->getC()->set_hp(2);  
					if (n->getC()->get_hp() <= 0) {
						cout << n->name << "의 파이리가 쓰러졌다." << endl;
						field[n->getC()->get_y()][n->getC()->get_x()] = 0;
						n->delC();
					}
				}
				if (n->getS() == NULL);
				else if (C->Attack(direction, n->getS()->get_x(), n->getS()->get_y()) == true) {
					cout << name << "의 파이리의 불꽃공격!" << endl;
					n->getS()->set_hp(1); 
					if (n->getS()->get_hp() <= 0) {
						cout << n->name << "의 꼬부기가 쓰러졌다." << endl;
						field[n->getS()->get_y()][n->getS()->get_x()] = 0;
						n->delS();
					}
				}
				if (n->getB() == NULL);
				else if (C->Attack(direction, n->getB()->get_x(), n->getB()->get_y()) == true) {
					cout << name << "의 파이리의 불꽃공격!" << endl;
					n->getB()->set_hp(3); 
					if (n->getB()->get_hp() <= 0) {
						cout << n->name << "의 이상해씨가 쓰러졌다." << endl;
						field[n->getB()->get_y()][n->getB()->get_x()] = 0;
						n->delB();
					}
				}
				if (n->getP() == NULL);
				else if (C->Attack(direction, n->getP()->get_x(), n->getP()->get_y()) == true) {
					cout << name << "의 파이리의 불꽃공격!" << endl;
					n->getP()->set_hp(2); 
					if (n->getP()->get_hp() <= 0) {
						cout << n->name << "의 피카츄가 쓰러졌다." << endl;
						field[n->getP()->get_y()][n->getP()->get_x()] = 0;
						n->delP();
					}
				}
			}
			else
				cout << "공격이 빗나갔다!" << endl;
		}
		else if (sel == 2) { //When Squirtle
			if (S->Attack_boundary(field, direction) == true) {
				if (n->getC() == NULL);
				else if (S->Attack(direction, n->getC()->get_x(), n->getC()->get_y()) == true) {
					cout << name << "의 꼬부기의 물대포!" << endl;
					n->getC()->set_hp(3); // 
					if (n->getC()->get_hp() <= 0) {
						cout << n->name << "의 파이리가 쓰러졌다." << endl;
						field[n->getC()->get_y()][n->getC()->get_x()] = 0;
						n->delC();
					}
				}
				if (n->getS() == NULL);
				else if (S->Attack(direction, n->getS()->get_x(), n->getS()->get_y()) == true) {
					cout << name << "의 꼬부기의 물대포!" << endl;
					n->getS()->set_hp(2); // 
					if (n->getS()->get_hp() <= 0) {
						cout << n->name << "의 꼬부기가 쓰러졌다." << endl;
						field[n->getS()->get_y()][n->getS()->get_x()] = 0;
						n->delS();
					}
				}
				if (n->getB() == NULL);
				else if (S->Attack(direction, n->getB()->get_x(), n->getB()->get_y()) == true) {
					cout << name << "의 꼬부기의 물대포!" << endl;
					n->getB()->set_hp(1); // 
					if (n->getB()->get_hp() <= 0) {
						cout << n->name << "의 이상해씨가 쓰러졌다." << endl;
						field[n->getB()->get_y()][n->getB()->get_x()] = 0;
						n->delB();
					}
				}
				if (n->getP() == NULL);
				else if (S->Attack(direction, n->getP()->get_x(), n->getP()->get_y()) == true) {
					cout << name << "의 꼬부기의 물대포!" << endl;
					n->getP()->set_hp(2); // 
					if (n->getP()->get_hp() <= 0) {
						cout << n->name << "의 피카츄가 쓰러졌다." << endl;
						field[n->getP()->get_y()][n->getP()->get_x()] = 0;
						n->delP();
					}
				}
			}
			else
				cout << "공격이 빗나갔다!" << endl;
		}
		else if (sel == 3) { //When Bulbasaur
			if (B->Attack_boundary(field, direction) == true) {
				if (n->getC() == NULL);
				else if (B->Attack(direction, n->getC()->get_x(), n->getC()->get_y()) == true) {
					cout << name << "의 이상해씨의 풀공격!" << endl;
					n->getC()->set_hp(1);
					if (n->getB()->get_hp() <= 0) {
						cout << n->name << "의 파이리가 쓰러졌다." << endl;
						field[n->getB()->get_y()][n->getB()->get_x()] = 0;
						n->delB();
					}
				}
				if (n->getS() == NULL);
				else if (B->Attack(direction, n->getS()->get_x(), n->getS()->get_y()) == true) {
					cout << name << "의 이상해씨의 풀공격!" << endl;
					n->getS()->set_hp(3);
					if (n->getS()->get_hp() <= 0) {
						cout << n->name << "의 꼬부기가 쓰러졌다." << endl;
						field[n->getS()->get_y()][n->getS()->get_x()] = 0;
						n->delS();
					}
				}
				if (n->getB() == NULL);
				else if (B->Attack(direction, n->getB()->get_x(), n->getB()->get_y()) == true) {
					cout << name << "의 이상해씨의 풀공격!" << endl;
					n->getB()->set_hp(2);
					if (n->getB()->get_hp() <= 0) {
						cout << n->name << "의 이상해씨가 쓰러졌다." << endl;
						field[n->getB()->get_y()][n->getB()->get_x()] = 0;
						n->delB();
					}
				}
				if (n->getP() == NULL);
				else if (B->Attack(direction, n->getP()->get_x(), n->getP()->get_y()) == true) {
					cout << name << "의 이상해씨의 풀공격!" << endl;
					n->getP()->set_hp(2);
					if (n->getP()->get_hp() <= 0) {
						cout << n->name << "의 피카츄가 쓰러졌다." << endl;
						field[n->getP()->get_y()][n->getP()->get_x()] = 0;
						n->delP();
					}
				}
			}
			else
				cout << "공격이 빗나갔다!" << endl;
		}
		else if (sel == 4) { //When Pikachu
			if (P->Attack_boundary(field, direction) == true) {
				if (n->getC() == NULL);
				else if (P->Attack(direction, n->getC()->get_x(), n->getC()->get_y()) == true) {
					cout << name << "의 피카츄의 100만볼트!" << endl;
					n->getC()->set_hp(2);
					if (n->getC()->get_hp() <= 0) {
						cout << n->name << "의 파이리가 쓰러졌다." << endl;
						field[n->getC()->get_y()][n->getC()->get_x()] = 0;
						n->delC();
					}
				}
				if (n->getS() == NULL);
				else if (P->Attack(direction, n->getS()->get_x(), n->getS()->get_y()) == true) {
					cout << name << "의 피카츄의 100만볼트!" << endl;
					n->getS()->set_hp(2);
					if (n->getS()->get_hp() <= 0) {
						cout << n->name << "의 꼬부기가 쓰러졌다." << endl;
						field[n->getS()->get_y()][n->getS()->get_x()] = 0;
						n->delS();
					}
				}
				if (n->getB() == NULL);
				else if (P->Attack(direction, n->getB()->get_x(), n->getB()->get_y()) == true) {
					cout << name << "의 피카츄의 100만볼트!" << endl;
					n->getB()->set_hp(2);
					if (n->getB()->get_hp() <= 0) {
						cout << n->name << "의 이상해씨가 쓰러졌다." << endl;
						field[n->getB()->get_y()][n->getB()->get_x()] = 0;
						n->delB();
					}
				}
				if (n->getP() == NULL);
				else if (P->Attack(direction, n->getP()->get_x(), n->getP()->get_y()) == true) {
					cout << name << "의 피카츄의 100만볼트!" << endl;
					n->getP()->set_hp(2);
					if (n->getP()->get_hp() <= 0) {
						cout << n->name << "의 피카츄가 쓰러졌다." << endl;
						field[n->getP()->get_y()][n->getP()->get_x()] = 0;
						n->delP();
					}
				}
			}
		}
	}
	Charmander* getC() {
		return C;
	}
	Squirtle* getS() {
		return S;
	}
	Bulbasaur* getB() {
		return B;
	}
	Pikachu* getP() {
		return P;
	}
};

