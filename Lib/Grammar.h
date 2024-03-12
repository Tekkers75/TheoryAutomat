class Grammar {
public:
    list<string> Nonterminal;
    list<string> Terminal;
    list<Rule> P;
    string S;

    Grammar(const list<string>& vn, const list<string>& vt, const list<Rule>& rules, const string& s = "S")
        : Nonterminal(vn), Terminal(vt), P(rules), S(s) {}

    string GetTypeGrammar() {
        bool isTypeOne = true;
        bool isTypeTwo = true;
        bool isTypeThree = true;

        bool isEachTermPosBigger = true;
        bool isEachTermPosSmaller = true;

        for (const Rule& r : P) {
            // проверка принадлежности первому типу грамматики
            isTypeOne &= r.getKey().length() <= r.getValue().length();

            // проверка принадлежности второму типу
            for (const string& vt : Terminal) {
                isTypeTwo &= r.getKey().find(vt) == string::npos;
            }

            if (isEachTermPosBigger || isEachTermPosSmaller) {
               list<int> terminalPositions;
               list<int> nonterminalPositions;

                for (const string& vn : Nonterminal) {
                    int temp = r.getValue().find(vn);
                    if (temp != string::npos) {
                        nonterminalPositions.push_back(temp);
                    }
                }

                for (const string& vt : Terminal) {
                    int temp = r.getValue().find(vt);
                    if (temp != string::npos) {
                        terminalPositions.push_back(temp);
                    }
                }

                for (int pos : terminalPositions) {
                    for (int posNonTerm : nonterminalPositions) {
                        isEachTermPosBigger &= pos > posNonTerm;
                        isEachTermPosSmaller &= pos < posNonTerm;
                    }
                }

                if (!(isEachTermPosBigger || isEachTermPosSmaller)) {
                    isTypeThree = false;
                }
            }
        }

        cout << "Относится к типам по Хомскому:" << endl;
        string res = "0";
        if (isTypeOne) res += " 1";
        if (isTypeTwo) res += " 2";
        if (isTypeThree) res += " 3";
        return res;
    }

    string MakeTree(string text) {
        int maxCount = 10000;
        int count = 0;
        vector<string> tree;
        tree.push_back(text);

        while (count < maxCount) {
            for (const Rule& rule : P) {
                string key = rule.getKey();
                string value = rule.getValue();

                int pos = text.find(value);
                if (pos != -1) {
                    text.replace(pos, value.length(), key);

                    string separator = "|";
                    for (int i = 0; i < pos; i++) {
                        separator = " " + separator;
                    }
                    tree.push_back(separator);
                    tree.push_back(text);
                }
            }
            count++;
        }

        for (auto it = tree.rbegin(); it != tree.rend(); ++it) {
            cout << *it << endl;
        }
        return text;
    }
};

