#include <iostream>
#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"

//
//Праволинейная грамматика :
//
//Каждое правило в праволинейной грамматике имеет следующую форму : A->wB или A->w, где A и B - нетерминальные символы, w - цепочка терминальных и нетерминальных символов.
//В праволинейной грамматике все правила имеют единственный терминал в конце правой стороны.
//Праволинейная грамматика задает язык, который может быть распознан конечным автоматом или регулярным выражением.
//
//Леволинейная грамматика :
//
//Каждое правило в леволинейной грамматике имеет следующую форму : A->Bw или A->w, где A и B - нетерминальные символы, w - цепочка терминальных и нетерминальных символов.
//В леволинейной грамматике все правила имеют единственный терминал в начале правой стороны.
//Леволинейная грамматика задает язык, который может быть распознан конечным автоматом или регулярным выражением.
int main()
{
	setlocale(LC_ALL, "rus");


	cout<<"Задание 11."<<endl;
	cout<<"Подпункт а"<<endl;
	cout<<"Грамматика описывает язык 0^n 1^n 'Символ перепендикуляра' |"<<endl;
	list<Rule> dict =
	{
		 Rule("S", "0S"),
		 Rule("S", "0B"),
		 Rule("B", "1B"),
		 Rule("B", "1C"),
		 Rule("C", "1C"),
	     Rule("C", "|"),

	};
	PrintRules(dict);
	FormalLanguage fl(dict);
	cout<<fl.OutputLeft()<<endl;

	list<Rule> dict1 =
	{
		 Rule("S", "A|"),
		 Rule("A", "A1"),
		 Rule("A", "B1"),
		 Rule("B", "B1"),
		 Rule("B", "C1"),
		 Rule("B", "CB1"),
		 Rule("C", "0"),
		/*Rule("S", "S0"),
		Rule("S", "B0"),
		Rule("B", "B1"),
		Rule("B", "C1"),
		Rule("C", "C1"),
		Rule("C", "|")*/
	};
	FormalLanguage fl1(dict1);
	cout << fl1.OutputLeft() << endl;
	cout<<"Подпункт б"<<endl;
	cout<<"Грамматика описывает язык {a^n b^n} 'Символ перепендикуляра' |"<<endl;
	//cout << fl.OutputLeft() << endl;

	list<Rule> dict2 =
	{
		 Rule("S", "aA"),
		 Rule("S", "aB"),
		 Rule("S", "bA"),
		 Rule("A", "bS"),
		 Rule("B", "aS"),
		 Rule("B", "bB"),
		 Rule("B", "|"),

	};
	PrintRules(dict2);
	FormalLanguage fl2(dict2);
	cout << fl2.OutputLeft() << endl;

	list<Rule> dict3 =
	{
		 Rule("S", "A|"),
		 Rule("A", "Ba"),
		 Rule("A", "Bb"),
		 Rule("A", "Ab"),
		 Rule("A", "ABa"),
		 Rule("A", "ABb"),
		 Rule("B", "a"),
		 Rule("B", "b"),
		/*Rule("S", "Aa"),
		 Rule("S", "Ba"),
		 Rule("S", "Ab"),
		 Rule("A", "Sb"),
		 Rule("B", "Sa"),
		 Rule("B", "Bb"),
		 Rule("B", "|"),*/
		 

	};
	FormalLanguage fl3(dict3);
	cout << fl3.OutputLeft() << endl;
	

}
