
#include<iostream>
#include<string>
using namespace std;
void printrev(int a[],int n){
    for(int k=n-1;k>=0;k--)
    {cout<<a[k];}
    cout<<endl;
}
int main(){
int T;
cin>>T;
while(T>0)
{
   string s1,s2;
   cin>> s1>>s2;


   int l1,l2;
   l1=s1.length();
   l2=s2.length();


   int num1[l1],num2[l2];

   for(int i=0;s1[i]!='\0';i++){num1[i]=s1[i]-'0';}
   for(int i=0;s2[i]!='\0';i++){num2[i]=s2[i]-'0';}



   int c=0,m=0;
   int n=l1-1,p=l2-1;
   int res[l1+l2];



   for (; n >= 0 && p >= 0; n--, p--, m++) {
res[m] = (num1[n] + num2[p] +c) % 10;
c = (num1[n] + num2[p] +c) / 10;
}


   if(l1>l2){

       while(n>=0){
           res[m++]=(num1[n]+c)%10;

           c=(num1[n--]+c)/10;

       }
       if(c>0){res[m]=c;
           m++;
       }

   }
  else if(l1<l2){
        while (p >= 0) {
res[m++] = (num2[p] + c) % 10;
c = (num2[p--] + c) / 10;
}
if(c>0){res[m]=c;
           m++;
       }
   }
   else{

       if(c>0){res[m]=c;
           m++;
       }
   }


   printrev(res,m);
T--;}

    return 0;
}
