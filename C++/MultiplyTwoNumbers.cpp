string multiplyStrings(string s1, string s2) {
       //Your code here
      
       int x=1,y=1;
       
       if(s1[0]=='-' && s2[0]!='0') {x=-1;

           s1=s1.substr(1);

       }

       if(s2[0]=='-' && s1[0]!='0') {y=-1;

           s2=s2.substr(1);

       }
       string fa="";
       if ( (x*y) < 0 ) 
         fa.push_back('-') ;
       int l1=s1.size();
       int l2=s2.size();
         if(s1[0]=='0'|| s2[0]=='0') 
            {  
               if(l1 ==1 || l2 ==1)
                  return "0";
            }
       
       vector<int>res(l1+l2);
       int pf=0;
       
       for(int i=l1-1;i>=0;i--)
         {
            int ival=s1[i]-'0';
            int prod=0;
            int carry=0;
            int ans=0;
            
            int j=l2-1;
            int k=res.size()-1-pf;
            while(carry!=0 || j>=0)
             {
                int jval= j>=0? s2[j]-'0':0; 
                prod = ival * jval + res[k] + carry;
                ans=prod%10;
                carry=prod/10;
                res[k]=ans;
                j--;
                k--;
                 
             }
            pf++;
        }
        
        int f=0;
        for(auto it : res)
          {
              if(it!=0) break;
              else f++;
          }
       
       //cout<<res.size()<<endl;
        for(int i=f;i<res.size();i++)
          {  
              fa +=to_string (res[i]);
             //cout<<fa<<endl;
          }
         return fa;
    }
