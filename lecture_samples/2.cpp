#include <iostream>
#include <stack>

using namespace std;

stack<char> st;

bool is_correct(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            if (st.top() == '(' && s[i] != ')')
                return false;
            if (st.top() == '[' && s[i] != ']')
                return false;
            if (st.top() == '{' && s[i] != '}')
                return false;
            st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;

}

int main() {
    string s;
    cin >> s;
    bool ok = is_correct(s);
    if (ok)
        cout << "YES";
    else
    {
        cout << "NO";
    }
    
    return 0;
}