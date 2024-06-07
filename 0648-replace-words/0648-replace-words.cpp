struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char i : word) {
            if (!node->containsKey(i)) {
                node->put(i, new Node());
            }
            node = node->get(i); // move to the reference trie
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char i : word) {
            if (!node->containsKey(i)) {
                return false;
            }
            node = node->get(i);
        }
        return node->isEnd();
    }


};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        Trie tr;
        for (auto& i : dictionary) {
            tr.insert(i);
        }
        stringstream ss(sentence);
        string str;
        string ans;
        while (ss >> str) {
            string temp;
            for (auto& i : str) {
                temp += i;
                if (tr.search(temp)) {
                    break;
                }
            }
            ans += temp;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};