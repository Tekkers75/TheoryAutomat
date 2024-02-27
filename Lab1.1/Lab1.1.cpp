#include "../Lib/FormalLanguage.h"
#include "../Lib/Rule.h"

int main()
{
    setlocale(LC_ALL, "ru");
    list<Rule> dict;
    string way;

    cout << "Задание 1.a" << endl;
    dict = {
        Rule("S", "T"),
        Rule("S", "T+S"),
        Rule("S", "T-S"),
        Rule("T", "F"),
        Rule("T", "F*T"),
        Rule("F", "a"),
        Rule("F", "b"),
    };
    PrintRules(dict);
    FormalLanguage fl1(dict);
    way = fl1.Transformations("a-b*a+b");
    cout << way;

    cout << "Задание 1.б" << endl;
    list<Rule> dict2 = {
        Rule("S", "aSBC"),
        Rule("S", "abC"),
        Rule("CB", "BC"),
        Rule("bB", "bb"),
        Rule("bC", "bc"),
        Rule("cC", "cc"),
    };
    PrintRules(dict2);
    FormalLanguage fl2(dict2);
    way = fl2.Transformations("aaabbbccc");
    cout << way;

}