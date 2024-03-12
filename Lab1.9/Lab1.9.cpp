#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"
#include "../Lib/Grammar.h"
int main()
{
	setlocale(LC_ALL, "rus");

	cout<<("Задание 9.a")<<endl;
	
	list<Rule> dict =
	{
		 Rule("S", "aSbS"),
		 Rule("S", "bSaS"),
		 Rule("S", "E"),
	};
	PrintRules(dict);
	FormalLanguage fl(dict);

	cout << "Цепочка: " + fl.Translate("S") << endl;
	Grammar gr(list<string>{ "S" }, list<string>{ "a", "b", "E" }, dict);
		
		

	cout << "Деревья вывода" << endl;
	cout << "Первое" << endl;
	cout<<(gr.MakeTree("aEbaEbE"))<<endl;
	cout << "Второе" << endl;
	cout << gr.MakeTree("abEaEbE") << endl << endl;
}
