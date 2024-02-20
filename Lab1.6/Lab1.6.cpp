#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Задание 6" << endl;
	list<Rule> dict =
	{
		 Rule("S", "AB"),
		 Rule("S", "ABS"),
		 Rule("AB", "BA"),
		 Rule("BA", "AB"),
		 Rule("A", "a"),
		 Rule("B", "b"),
	};
	PrintRules(dict);

	FormalLanguage fl(dict);
	cout << "Цепочка: " + fl.Translate("S") << endl;

	dict =
	{
		 Rule("S", "ab"),
	};
	PrintRules(dict);

	FormalLanguage fl1(dict);
	cout << "Цепочка: " + fl.Translate("S") << endl;

}
