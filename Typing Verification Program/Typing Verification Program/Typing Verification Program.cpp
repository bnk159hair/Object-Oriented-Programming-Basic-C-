#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
using namespace std;

double CheckStr(char str1[], char str2[]);

int main()
{
	ifstream fin("source.txt"); 
	ofstream fout("result.txt");
	double Acc = 0, Spe = 0; //Acc = Accuracy, Spe = Speed
	char ch; //For Detect key input
	int cnt = 0,i=0;
	time_t start, end;
	if (!fin.is_open()) //Open File
	{
		cout << "No File!" << endl;
		return 0;
	}
	fout << "KW Typing Verification Program" << endl;
	while (!fin.eof()) //Read and Test
	{
		cnt = 0; //Input string's length

		cout << fixed;
		cout.precision(4);
		cout << "KW Typing Verification Program" << endl;
		cout << "정확도 : " << Acc * 100 << "      ";
		cout << fixed;
		cout.precision(1);
		cout << "속도(타자/s) : " << Spe << endl;
		fout << fixed;
		fout.precision(4);
		fout << "정확도 : " << Acc * 100 << "      ";
		fout << fixed;
		fout.precision(1);
		fout << "속도(타자/s) : " << Spe << endl << endl;
		cout << endl << endl;
		char str[100]; //string from txt
		fin.getline(str, 100);
		cout << "문장 : " << str << endl;
		cout << "입력 : ";
		char YouStr[100], cpy[100]; //Your Input String, copy 
		
		
		start = clock(); //Time Start
		cin.getline(YouStr, 100);
		end = clock();
		
		while (YouStr[cnt] != NULL) //Count the length of Your String
			cnt++;
	
		fout << YouStr << endl;

		Acc = CheckStr(str, YouStr); //Check the Accuracy
		Spe = (double)(end - start)/1000; //Speed

		system("cls");
		cout << endl;
	}
	cout << "KW Typing Verification Program" << endl;
	cout << fixed;
	cout.precision(4);
	cout << "정확도 : " << Acc * 100 << "      ";
	cout << fixed;
	cout.precision(1);
	cout<< "속도(타자/s) : " << Spe;
	fout << fixed;
	fout.precision(4);
	fout << "정확도 : " << Acc * 100 << "      ";
	fout << fixed;
	fout.precision(1);
	fout<< "속도(타자/s) : " << Spe << endl;
	cout << endl << endl;
	fin.close();
	fout.close();
	return 0;
}

double CheckStr(char str1[], char str2[]) //Check the Accuracy
{
	int i = 0, j = 0, cor = 0;
	double res = 0;
	while (str1[i] != NULL)
		i++;
	for (j = 0; j < i; j++)
		if (str2[j] == str1[j])
			cor++;
	res = (double)cor / (i);
	return res;
}