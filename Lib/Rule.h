#pragma once
#include <iostream>
#include <string>
#include <list>


using namespace std;

/// Правило языка
class Rule {
private:
	/// Порождающая цепочка языка Ключ
	string key; 
	/// Порождающая цепочка языка Значение
	string value;
	/// Введет ли правило зацикливанию.
	bool IsLooped;

public:
	/// Конструктор
	Rule(string k, string v, bool l = false) {
		key = k;
		value = v;
		IsLooped = l;
	}
	/// Порождающая цепочка языка
	/// Сеттер
	void setKey(string k)
	{
		key = k;
	}
	/// Геттер
	string getKey() const
	{
		return key;
	}

	/// Порождаемая цепочка языка
	/// Сеттер
	void setValue(string v)
	{
		value = v;
	}
	/// Геттер
	string getValue() const
	{
		return value;
	}

	/// Введет ли правило зацикливанию.
	/// True - введет, false - правило не зацикливает грамматику
	/// Сеттер
	void setIsLooped(bool l)
	{
		IsLooped = l;
	}
	/// Геттер
	bool getIsLooped() const
	{
		return IsLooped;
	}
};

/// Вывод правил языка
void PrintRules(list<Rule>& R)
{
	cout << "Правила для языка" << endl;

	for (const Rule& rule : R)
	{
		cout << "   " + rule.getKey() + "-->" + rule.getValue() << endl;
	}
};

