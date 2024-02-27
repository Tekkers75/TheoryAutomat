#pragma once
#include <iostream>
#include <string>
#include <list>
#include <random>
#include "Rule.h"

using namespace std;

/// Класс формального языка с леволинейной грамматикой и проверкой на зацикливание
class FormalLanguage
{
private:
	/// Правила языка
	list <Rule> _rules;
	/// Максимально количество повторений
	int MaxRepetitionsCount;

	/// Проверяет правило на зацикливание
	/// "input" - Строка, к которой применяется правило
	/// "rule" - Правило языка
	/// "count" - Количество допустимых повторений

	bool CheckLoop(string input, Rule rule, int count = 5) {
		for (int i = 0; i < count; i++) {
			string key = rule.getKey();
			string value = rule.getValue();

			size_t pos = input.find(key);

			if (pos != -1) // вместо -1 = npos
			{
				input = input.erase(pos, key.length());
				input = input.insert(pos, value);
			}
			else
			{
				return false;
			}
		}
		return true;
	}

	void RefreshRules() {
		for (Rule& rule : _rules) {
			rule.setIsLooped(false);
		}
	}
public:
	/// Конструктор
	FormalLanguage(list<Rule> rules, int count = 10000)
	{
		_rules = rules;
		MaxRepetitionsCount = count;
	}

	/// Сеттер
	void setRules(list <Rule> rule)
	{
		_rules = rule;
	}

	/// Геттер
	list<Rule> getRules() const
	{
		return _rules;
	}

	/// Сеттер
	void setMaxRepetitionsCount(int repeat)
	{
		MaxRepetitionsCount = repeat;
	}

	/// Геттер
	int getMaxRepetitionsCount()
	{
		return MaxRepetitionsCount;
	}

	/// Левостороний вывод.
	/// Строка, порожденная на основе правил языка.
	string OutputLeft()
	{
		string result = "S";
		int count = 0;
		while (count < MaxRepetitionsCount)
		{
			size_t pos = -1;

			// найдем крайний левый нетерминальный символ в цепочке
			for (const Rule& rule : _rules)
			{
				string key = rule.getKey();
				size_t findPos = result.find(key);
				if ((pos > findPos || pos == -1) && findPos != -1)
				{
					pos = findPos;
					break;
				}

			}

			// если не найдено ниодного подходящего правила - выходим
			if (pos == -1)
			{
				break;
			}

			// найдем все правил подходящие для крайнего левого нетерминального символа
			list<Rule> rules = {};
			for (const Rule& rule : _rules)
			{
				string key = rule.getKey();
				if (pos == result.find(key))
				{
					rules.push_back(rule);
				}
			}

			// случайно выберем правило
			random_device random;
			mt19937 gen(random());
			uniform_int_distribution<int> dist(0, rules.size() - 1);
			int index = dist(gen);
			auto it = rules.begin();
			advance(it, index);
			Rule r = *it;

			size_t p = result.find(r.getKey());
			result = result.erase(p, r.getKey().length());
			result = result.insert(p, r.getValue());
			cout << result << endl;

			count++;
		}

		return result;
	}


	string OutputLeft(vector<string>& transformations)
	{
		transformations.clear();
		string result = "S";
		int count = 0;

		while (count < MaxRepetitionsCount)
		{
			size_t pos = string::npos;

			// найдем крайний левый нетерминальный символ в цепочке
			for (const Rule& rule : _rules)
			{
				string key = rule.getKey();
				size_t findPos = result.find(key);
				if ((pos > findPos || pos == string::npos) && findPos != string::npos)
				{
					pos = findPos;
					break;
				}
			}
			// если не найдено ниодного подходящего правила - выходим
			if (pos == string::npos)
			{
				break;
			}
			// для правого
			// найдем все правила подходящие для крайнего левого нетерминального символа
			std::vector<Rule> rules_;
			for (const Rule& rule : _rules) {
				std::string key = rule.getKey();
				if (pos == result.find(key)) {
					rules_.push_back(rule);
				}
			}

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, rules_.size() - 1);
			int index = dis(gen);
			Rule r = rules_[index];

			size_t p = result.find(r.getKey());
			result.replace(p, r.getKey().length(), r.getValue());
			//cout << result << endl;
			transformations.push_back(/*"( " + r.getKey() + " --> " + r.getValue() + " ): "*/ /*+*/ result);
			count++;
		}
		return result;
	}

	string Transformations(string chain_) {
		string buf;
		string result;
		vector<string> transformations;
		bool found = false;
		int counter = 0;
		while (!found) {
			buf = this->OutputLeft(transformations);
			counter++;
			if (counter == 10000000) return "Цепочка не построена. Попробуйте ещё раз\n";
			if (buf == chain_) found = true;
		}

		for (int i = 0; i < transformations.size(); i++)
		{
			result += transformations[i] + "\n";
		}
		result.insert(0, "Начальный символ: S\n");

		return result;
	}


	/// Переводит строку на формальный язык
	/// "text" - Строка для перевода
	string Translate(string text)
	{
		int count = 0;
		bool isEnd = false;	// true - если ни одно из правил непреминимо
		while (count < MaxRepetitionsCount)
		{
			if (isEnd) break;

			count++;
			isEnd = true;
			// применяем по очереди каждое правило языка к строке
			for (Rule& rule : _rules)
			{
				if (!rule.getIsLooped())		// если правило зацикливает
				{
					string key = rule.getKey();
					string value = rule.getValue();

					int pos = text.find(key);

					if (pos != -1)	// если ключ найден
					{
						// если правило зацикливает перевод - запоминаем это
						if (CheckLoop(text, rule)) rule.setIsLooped(true);
						else
						{
							cout << text << endl;
							text = text.erase(pos, key.length());
							text = text.insert(pos, value);
							isEnd = false;
							break;
						}
					}
				}
				else rule.setIsLooped(!rule.getIsLooped());
			}
		}

		RefreshRules();
		return text;
	}
};