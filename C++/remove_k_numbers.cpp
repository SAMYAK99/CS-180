// Our task is to form smallest number from a given number(string) by removing k characters.
string removeKdigits(string S, int K) {
          stack<char>s;
          int n=S.size();
          for(char c:S)
          {
              while(!s.empty() && s.top()>c && K>0)
                  {
                    s.pop();
                    K--;
                  }
              if(!s.empty() || c!='0')
                 {
                    s.push(c);
                 }
          }
          while(!s.empty() && K--)        
               {
                s.pop();
               }
          if(s.empty())
             {
               return "0";
              }
          while(!s.empty())
            {
              S[n-1]=s.top();
              s.pop();
              n--;
            }
        return S.substr(n);
}

