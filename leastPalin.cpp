#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ctoi(char c)
{
	return c - '0';
}

string nextPalin(string str)
{
	//handling single digit numbers
	if (str.length() == 1)
	{
		string fin = "";
		if(stoi(str) == 9) { fin += "11";}
		else { fin += '0' + (stoi(str) + 1); }
		return fin;
	}
	string left, right;
	int pivot;
	//initializing for even digits
	if (str.length() % 2 == 0)
	{
		pivot = str.length() / 2 - 1;
		left = str.substr(0, str.length() / 2);
		right = str.substr(str.length() / 2);
	}
	//initializing for odd digits
	else
	{
		pivot = str.length() / 2;
		left = str.substr(0, str.length() / 2);
		right = str.substr(str.length() / 2 + 1);
	}
	string left_reverse = "";
	for (int i = left.length() - 1; i >= 0; --i)
		left_reverse += left[i];
	//when right half is less then reverse of left half
	if (right.compare(left_reverse) < 0)
	{
		string fin = "";
		if (str.length() % 2 == 0)
		{
			fin += left;
			fin += left_reverse;
		}
		else
		{
			fin += left;
			fin += str[pivot];
			fin += left_reverse;
		}
		return fin;  
	}
	//when right half is greater or equal to reverse of left half
	else
	{
		string fin = "";
		if (ctoi(str[pivot]) < 9)
		{
			if (str.length() % 2 == 0)
			{
				left[pivot] = '0' + (ctoi(left[pivot]) + 1);
				left_reverse[0] = '0' + (ctoi(left_reverse[0]) + 1);
				fin += left;
				fin += left_reverse;
				//cout << left << " " << left_reverse << "\n";
			}
			else
			{
				fin += left;
				fin += (char)('0' + (ctoi(str[pivot]) + 1));
				fin += right;
			}
		}
		//handling cases like 99, 999, ...
		else
		{
			int i;
			for(i = pivot; i >= 0; i--)
			{
				if (ctoi(str[i]) < 9) break;
				else str[i] = '0';
			}
			if (i >= 0) 
			{
				str[i] = '0' + (ctoi(str[i]) + 1);
				left = str.substr(0, str.length() / 2);
				left_reverse =  "";
				for (int i = left.length() - 1; i >= 0; --i)
					left_reverse += left[i];
				if(str.length() % 2 == 0)
				{
					fin += left;
					fin += left_reverse;
				}
				else
				{
					fin += left;
					fin += '0';
					fin += left_reverse;
				}
			}
			else
			{
				fin += '1';
				for(int j = 0; j < str.length() - 1; j++)
					fin += '0';
				fin += '1';
			}
		}
		return fin;
	}
}

int main()
{
	int t;
	vector<string> v;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < t; i++)
	{
		cout << nextPalin(v[i]) <<"\n";
	}
}