#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"
int main()
{
	setlocale(LC_ALL, "rus");

	cout<<"Задание 12."<<endl;
	list<Rule> dict =
	{
		 Rule("S", "S1"),
		 Rule("S", "A0"),
		 Rule("A", "A1"),
		 Rule("A", "0"),
	};

PrintRules(dict);
FormalLanguage fl(dict);
cout << fl.OutputLeft() << endl;

     list<Rule> dict1 =
	{
		 Rule("S", "A1"),
		 Rule("S", "B0"),
		 Rule("S", "E1"),
		 Rule("A", "S1"),
		 Rule("B", "C1"),
		 Rule("B", "D1"),
		 Rule("C", "0"),
		 Rule("D", "B1"),
		 Rule("E", "E0"),
		 Rule("E", "1"),
	};

	 PrintRules(dict1);
	 FormalLanguage fl1(dict1);
	 cout << fl1.OutputLeft() << endl;


	 list<Rule> dict2 =
	 {
		  Rule("S", "S1"),
		  Rule("S", "A0"),
		  Rule("S", "A1"),
		  Rule("A", "0"), };

     PrintRules(dict2);
	 FormalLanguage fl2(dict2);
	 cout << fl2.OutputLeft() << endl;
}
