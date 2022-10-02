s+=" ";

   string ans ;
   map<string,string> mp ;
   mp["zero"] = "0" ; 
   mp["one"] = "1" ;
   mp["two"] = "2" ;
   mp["three"] = "3" ; 
   mp["four"] = "4" ;
   mp["five"] = "5" ;
   mp["six"] = "6" ;
   mp["seven"] = "7" ; 
   mp["eight"] = "8" ;
   mp["nine"] = "9" ;
   
   vector<string> vs ;
   string tmp = "";

   for(int i=0 ; i<s.size();i++){
     if(s[i]== ' '){ 
       vs.push_back(tmp);
       tmp = "";
     }
     if(s[i] != ' ')
     tmp += s[i] ;
   }

    int flag = 0 ; 
    
   for(auto i : vs){
     if (flag == 2) ans+=i  ;
     if (flag == 3)  ans+=i+i ;  
     if( i == "double")  flag = 2 ; 
     else if( i == "triple") flag = 3 ; 
     else{
      ans+=i ;
      flag = 0 ; 
     }
     
     return ans ; 