#include <iostream>
#include<string>
using namespace std;
int lengthofLast(string str)
{
	int c= 0;
	bool flag = false;
	for (int i = str.length() - 1; i >= 0; i--) {
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')) {
			flag = true;
			count++;
		}
		
		else {
			if (flag == true)
				return count;
		}
	}
	return count;
}
int main()
{
	string str = "Hello World";
	cout << "The length of last word is " << lengthofLast(str);
  string str2="   fly me   to   the moon  ";
  cout<<"The length of last word is "<<lengthofLast(str2);
  string str3="luffy is still joyboy";
  cout<<"The length of last word is "<<lengthofLast(str3); 
	return 0;
}
