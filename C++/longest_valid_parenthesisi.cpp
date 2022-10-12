 int longest_valid(string s)
stack<int>st;
    int maxi=0;
     st.push(i);
   for(int i=0;i< st.size();i++)
      {
           if( st[i]=="(")
                    {
                      st.push(i);
                    }
             else 
                  {
                    st.pop();
                     if(st.empty())
                            st.push(i);
                    else 
                       {
                         int len =i-st.top();
                         maxi=max(maxi,len);
                       }
                  }
       }
return maxi;
}
