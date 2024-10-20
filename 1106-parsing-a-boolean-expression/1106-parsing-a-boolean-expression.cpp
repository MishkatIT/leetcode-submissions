class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char> ex, val;
        for (auto& i : expression) {
            if (i == ',') continue;
            if (i == '!' || i == '&' || i == '|') {
                ex.push_back(i);
            } else if (i != ')') {
                val.push_back(i);
            } else {
                int op = ex.back();
                ex.pop_back();
                char c = val.back();
                if (op == '!') {
                    val.pop_back();
                    val.pop_back();
                    c = (c == 't' ? 'f' : 't');
                } else if (op == '&') {
                    while (val.back() != '(') {
                        c = ((c == 'f' || val.back() == 'f') ? 'f' : 't');
                        val.pop_back();
                    }
                    val.pop_back();
                } else {
                    while (val.back() != '(') {
                        c = ((c == 't' || val.back() == 't') ? 't' : 'f');
                        val.pop_back();
                    }
                    val.pop_back();
                }
                val.push_back(c);
            }
        }
        return val.back() == 'f' ? 0 : 1;
    }
};