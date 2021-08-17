#include <iostream>
#include<iomanip>
using namespace std;

/*
	This is 3 6 9 Game
*/

class ThreeSixNine
{
public:
	void print369(int num)
	{
		int i = 0, j = 0;
		for (i = 1; i <= num; i++)
		{
			cout.setf(ios::left);
			if (Check(i) > 0)
			{
				if (Check(i) == 1) // count is 1
					cout << setw(10) << "!";
				else if (Check(i) == 2) //count is 2
					cout << setw(10) << "!!";
			}
			else
				cout << setw(10) << i;
			if (i % 10 == 0)
				cout << endl;
		}
		return;
	}
	int Check(int num) // Count 3, 6, 9 and return count
	{
		int i = 0, count=0; 
		while (num>=10)
		{
			if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) 
				count++;
			num = num / 10;
		}
		if (num == 3 || num == 6 || num == 9) //When num<10
			count++;
		return count;
	}
};
int main()
{
	int num;
	ThreeSixNine game;
	
	cout << "Input your number" << endl;
	cin >> num;
	if (1 <= num && num <= 300)
	{
		game.print369(num);
		cout << endl;
	}
	else
		cout << "잘못된 입력 값입니다" << endl;

	return 0;
}