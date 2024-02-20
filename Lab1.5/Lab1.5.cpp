#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Задание 5" << endl;
	list<Rule> dict =
	{
		 Rule("S", "aSL"),
		 Rule("S", "aL"),
		 Rule("L", "Kc"),
		 Rule("cK", "Kc"),
		 Rule("K", "b"),
	};
	PrintRules(dict);

	FormalLanguage fl(dict);
	cout << "Цепочка: " + fl.Translate("S") << endl;
	cout << "Язык: L = {a^n b^m c^k | a, b, k > 0}" << endl;
	

	dict = 
	{
		 Rule("S", "aSBc"),
		 Rule("S", "abc"),
		 Rule("cB", "Bc"),
		 Rule("bB", "bb"),
	};
	PrintRules(dict);

	FormalLanguage fl1(dict);
	cout << "Цепочка: " + fl.Translate("S") << endl;
	cout << "Язык: L = {a^n b^m c^k | a, b, k > 0}" << endl;

	cout << "Грамматики эквиваленты т.к. они определяют один и тот же язык" << endl;
	
}
