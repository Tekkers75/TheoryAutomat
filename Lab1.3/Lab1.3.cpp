#include "Rule.h"
#include "FormalLanguage.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Задание 3.a" << endl;
	cout << "Язык: L = { a^n b^m c^k | n, m, k > 0}" << endl;
	cout << "Грамматика: G: ({a, b, c}, {A, B, C, S}, P, S)" << endl;
	list<Rule> dict =
	{
		 Rule("S", "aaB"),
		 Rule("B", "bCCCC"),
		 Rule("B", "b"),
		 Rule("C", "Cc"),
		 Rule("C", "c"),
	};
	PrintRules(dict);

	FormalLanguage fl3(dict);
	cout << "Левосторонний вывод из рандомных выбранных правил" << endl;
	cout << fl3.OutputLeft() << endl;
	cout << "Минимальная цепочка: " << endl;
	cout << "Цепочка: " + fl3.Translate("S") << endl;


	cout << "Задание 3.б" << endl;
	cout << "Язык: L = {0^n(10)^m | n, m >= 0}" << endl;
	cout << "Грамматика: G: ({0, 10}, {A, B, S}, P, S)" << endl;
	dict =
	{
		 Rule("S", "0AB"),
		 Rule("A", "000"),
		 Rule("B", "1010"),
	};
	PrintRules(dict);

	FormalLanguage fl4(dict);
	cout << "Левосторонний вывод из рандомных выбранных правил" << endl;
	cout << fl4.OutputLeft() << endl;
	cout << "Минимальная цепочка: " << endl;
	cout << "Цепочка: " + fl4.Translate("S") << endl;


	cout << "Задание 3.в" << endl;
	cout << "Язык: L = {a1 a2 … an an … a2a1 | ai E {0, 1}}" << endl;
	cout << "Грамматика: G: ({0, 1}, {A, B, S}, P, S)" << endl;
	dict =
	{
		 Rule("S", "AB"),
		 Rule("A", "1001010"),
		 Rule("B", "0101001"),
	};
	PrintRules(dict);
	FormalLanguage fl5(dict);
	cout << "Левосторонний вывод из рандомных выбранных правил" << endl;
	cout << fl5.OutputLeft() << endl;
	cout << "Минимальная цепочка: " << endl;
	cout << "Цепочка: " + fl5.Translate("S") << endl;
	return 0;

}
