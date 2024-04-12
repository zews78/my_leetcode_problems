#include <bits/stdc++.h>

class Solution {
public:
  string removeKdigits(string num, int k) {
    if (num.size() == k) { // Handle all digits removal
      return "0";
    }

    stack<char> st;

    for (char x : num) {
      while(!st.empty() && st.top() > x && k > 0) {
        st.pop();
        k--;
      }
      st.push(x);
    }

    while (!st.empty() && k > 0) {
      st.pop();
      k--;
    }

    string str = "";
    while (!st.empty()) {
      str += st.top();
      st.pop();
    }

    reverse(str.begin(), str.end());

    // remove leading zeros
    size_t pos = str.find_first_not_of('0');
    str = (pos == std::string::npos) ? "0" : str.substr(pos);
    return str;
  }
};
