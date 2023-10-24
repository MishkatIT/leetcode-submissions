class Solution {
public:
    bool isValid(string s) {
         deque<char> dq;
    for (auto& i: s)
    {
        if(i == '(' || i == '{' || i == '[')
            dq.push_front(i);
        else if((i == ')' && dq.front() == '(') || (i == '}' && dq.front() == '{') || (i == ']' && dq.front() == '['))
            dq.pop_front();
        else
            return false;
    }
    if(dq.size())
        return false;
    return true;
        
    }
};