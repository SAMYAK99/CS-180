vector<int>f;
   int start=0;
   int end =n-1;
   int res=-1;
   while(start<=end)
      {
          int mid=start+end/2;
          if(arr[mid]==x)
             {
                 res=mid;
                 start=mid-1;
             }
          else if(arr[mid]<x)
            {
                start=mid+1;
            }
          else 
            {
                end=mid-1;
            }
      }
    f.push_back(res);
    start=0;
    end =n-1;
    res=-1;
    while(start<=end)
      {
         int  mid=start+end/2;
          if(arr[mid]==x)
             {
                 res=mid;
                 start=mid+1;
             }
          else if(arr[mid]<x)
            {
                start=mid+1;
            }
          else 
            {
                end=mid-1;
            }
      }
    f.push_back(res); 
    }


