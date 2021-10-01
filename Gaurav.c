#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[500];
void shiftable(char p[])
{ int i,j,m;
  m=strlen(p);
  for(i=0;i<500;i++)
  { t[i]=m;
  }
  for(j=0;j<m-1;j++)
  { t[p[j]]=m-1-j;
  }
}
int horspool(char src[],char p[])
{ int i,j,n,m,k;
  n=strlen(src);
  m=strlen(p);
  printf("Length of text %d",n);
  printf("Length of pattern %d",m);
  i=m-1;
  while(i<n)
  {  k=0;
     while((k<m)&&(p[m-1-k]==src[i-k]))
     { k++;
     }
     if(k==m)
     { return(i-m+1);
     }
     else
     i=i+t[src[i]];
  }
  return -1;
}
void main()
{ char src[100],p[100];
  int pos;
  printf("Enter the text \n");
  fgets(src,100,stdin);
  printf("Enter the pattern");
  fgets(p,100,stdin);
  shiftable(p);
  pos=horspool(src,p);
  if(pos>=0)
  { printf("pattern found at %d",pos+1);
  }
  else
  { printf("pattern not found");
  }
}
  
