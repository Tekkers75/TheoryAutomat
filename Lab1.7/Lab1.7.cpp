#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"

//две грамматики эквивалентны, если совпадают порождаемые ими языки

int main()
{
	setlocale(LC_ALL, "rus");
	

	cout<<"Задание 7."<<endl;
	list<Rule> dict =
	{
		 Rule("S", "A.A"),
		 Rule("A", "B"),
		 Rule("A", "BA"),
		 Rule("B", "0"),
		 Rule("B", "1"),
	};
	PrintRules(dict);

	FormalLanguage fl(dict);
	
	string check1 = fl.OutputLeft();
	cout << "Цепочка: " + fl.Translate("S") << endl;


	list<Rule> dict1 =
	{
		 Rule("S", "A.0"),
		 Rule("A", "0"),
		 Rule("A", "1"),

		/* Rule("S", "A.0"),
		 Rule("A", "B"),
		 Rule("B", "0"),*/
		 

	};
	PrintRules(dict1);

	FormalLanguage fl1(dict1);
	string check2 = fl1.OutputLeft();
	cout << "Цепочка: " + fl1.Translate("S") << endl;

	//cout << "Грамматика: G: ({A, B}, {0, 1, .}, P, S)";

	if (check1 == check1) {
		cout << "Грамматики эквивалентны, так как описывают один язык" << endl;
	}
	else
		cout << "Грамматики не эквивалентны, так как описывают разные языки"; 
}
