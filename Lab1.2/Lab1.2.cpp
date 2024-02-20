#include "Rule.h"
#include "FormalLanguage.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");


	cout << "Первая лабораторная работа." << endl;
	cout << "Задание 2.a" << endl;
	list<Rule> dict =
	{
		 Rule("S", "aaCFD"),
		 Rule("AD", "D"),
		 Rule("F", "AFB"),
		 Rule("F", "AB"),
		 Rule("Cb", "bC"),
		 Rule("AB", "bBA"),
		 Rule("CB", "C"),
		 Rule("Ab", "bA"),
		 Rule("bCD", "\xE5"),  // epsilon ε
	};
	PrintRules(dict);
	FormalLanguage fl1(dict);
	cout << "Левосторонний вывод из рандомных выбранных правил" << endl;
	cout << fl1.OutputLeft() << endl;
	cout << "Минимальная цепочка: " << endl;
	cout << "Цепочка " + fl1.Translate("S") << endl;
	cout << "Язык:  L = { a^n | n > 0 }" << endl;

	cout << "Задание 2.б" << endl;
	list<Rule> dict2 =
	{
		 Rule("S", "A$"),
		 Rule("S", "B$"),
		 Rule("A", "a"),
		 Rule("A", "Ba"),
		 Rule("B", "b"),
		 Rule("B", "Bb"),
		 Rule("B", "Ab"),
	};
	PrintRules(dict2);
	FormalLanguage fl2(dict2);
	cout << "Левосторонний вывод из рандомных выбранных правил" << endl;
	cout << fl2.OutputLeft() << endl;
	cout << "Минимальная цепочка: " << endl;
	cout << "Цепочка " + fl2.Translate("S") << endl;
	cout << "Язык: L = { a^n,b^m $| n>0, m>0 }" << endl;



	return 0;
}
