#include <iostream>
#include <cstring>
using namespace std;
char* my_strstr(char* str, char* strSearch, char* strChange);
/* This is implement of strstr function of string */
int main()
{
	char str[100] = { 0 }, strSearch[100] = { 0 }, strChange[100] = { 0 };
	cout << "���� ���ڿ��� �Է��ϼ���." << endl;
	cin.getline( str,100);
	cout << endl;
	cout << "���� �� ���ڿ��� �Է��ϼ���." << endl;
	cin.getline(strSearch, 100) ;
	cout << endl;
	cout << "���� �� ���ڿ��� �Է��ϼ���." << endl;
	cin.getline(strChange, 100); 
	cout << endl;
	cout << "���� �� ����� ������ �����ϴ�. " << endl<<endl;
	my_strstr(str, strSearch, strChange);
	return 0;
}
char* my_strstr(char* str, char* strSearch, char* strChange)
{
	int i = 0, j = 0, k = 0;
	int str1 = 0, str2 = 0, str3 = 0, strTem=0;
	char* Tem = { 0 },  Ex[100] = { 0 };
	
	Tem = strstr(str, strSearch); //Use strstr
	if (!Tem) //When str not found
	{
		cout << "��ġ�ϴ� ���ڿ��� �����ϴ�." << endl;
		return 0;
	}

	while (str[str1] != NULL) //str1 is length of str
		str1++;
	while (strSearch[str2] != NULL) //str2 is length of strSearch
		str2++;
	while (strChange[str3] != NULL) //str3 is length of strChange
		str3++;
	while (Tem[strTem] != NULL)//strTem is length of Tem
		strTem++;

	for (i = 0; i < strTem - str2; i++) //Copy string after of searched
		Ex[i] = Tem[i + str2];
	Ex[strTem - str2] = NULL;

	for (i = 0; i < str3; i++)  //Change string
		Tem[i] = strChange[i];
	for (i = 0; i < strTem - str2+1; i++) //Add string after of searched
		Tem[str3 + i] = Ex[i];
	cout << "����� ���ڿ�: " << endl;
	cout << str << endl;
	return 0;
}