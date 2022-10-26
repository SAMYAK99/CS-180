##Algorithm

##Instead of finding every possible string and checking its validity, we can make use of a stack while scanning the given string to:

#Check if the string scanned so far is valid.
#Find the length of the longest valid string.
#In order to do so, we start by pushing -1−1 onto the stack. For every \text{‘(’}‘(’ encountered, we push its index onto the stack.

#For every \text{‘)’}‘)’ encountered, we pop the topmost element. Then, the length of the currently encountered valid string of parentheses will be the difference between the current element's index and the top element of the stack.  
#If, while popping the element, the stack becomes empty, we will push the current element's index onto the stack. In this way, we can continue to calculate the length of the valid substrings and return the length of the longest valid string at the end.
#COMPLEXITY ANALYSIS 
#Time complexity: O(n). n is the length of the given string.
#Space complexity: O(n). The size of stack can go up to n.
  
  class Solution {
public:
    int longestValidParentheses(string s) {
	stack<int> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(')
            st.push(i);
		else if(st.size()) 
        {
			s[st.top()] = s[i] = '*';
			st.pop();
		}
	}

	int cur = 0;
        int res = 0;
	for(int i = 0; i <= s.size(); i++) {
		if(s[i] == '*') 
            cur++;
		else {
			res = max(res, cur);
			cur = 0;
		}
	}

	return max(cur, res);
    }
};
