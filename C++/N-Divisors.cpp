int count(int A,int B,int N){ 
        int cnt=0;
        int flag=0;
        for(int i=A;i<=B;i++)
          {   cnt=0;
              for(int j=1;j*j<=i;j++)
                 {   int p=i/j;
                     if(i%j==0)
                       {
                           
                           if(p!=j)
                             cnt=cnt+2;
                           else 
                             cnt++;
                       }
                     
                  }
                if(cnt==N)
                  flag++;
          }
         return flag;
    }
