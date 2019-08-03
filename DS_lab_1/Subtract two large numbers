
#include<iostream>
#include<string>
using namespace std;


void printrev(int a[],int n){
   int k=n-1;
   while(a[k]==0){k--;}
    for( ;k>=0;k--)
    {cout<<a[k];}
    cout<<endl;
}




int main(){

   string s1,s2;
   cin>> s1>>s2;

  int sign;
   int l1,l2;
   l1=s1.length();
   l2=s2.length();
   int b;string temp;
//making sure str1 > str2
if(l1>l2){sign=1;}
//cout<<"1. s1 is bigger. "<<s1<<endl;

else if(l1<l2)

       {
    //cout<<"2. hello, we must swap";

    temp=s1;
    s1=s2;
    s2=temp;
    //cout<<"3.  s1 is bigger. "<<s1<<endl;
    sign=0;
        }

else{ //if l1=l2

    for(int i=0;i<l1;i++)
    {
        if(s1[i]>s2[i]){
            //cout<<"4. no swapping. s1 is bigger "<<s1<<endl;
            sign=1;
             b=1;break;
        }
        else if(s1[i]<s2[i]){b=2; break;
        }
        else{b=0;}
    }
}

if(b==2){
    string temp;
    temp=s1;
    s1=s2;
    s2=temp;
    int x=l1;
    l1=l2;
    l2=x;
    sign=0;
}
else if(b==0){
    cout<<0;
    return 0;
}
else{}

//cout<<endl<<"bigger is "<<s1<<endl;

//NOW S1>S2 FOR SURE.

//to make sure l1 and l2 are correct
 l1=s1.length();
   l2=s2.length();

   //nos arrays
   int num1[l1],num2[l2];
   //converting to numbers
   for(int i=0;s1[i]!='\0';i++){num1[i]=s1[i]-'0';}
   for(int i=0;s2[i]!='\0';i++){num2[i]=s2[i]-'0';}


   int c=0,m=0;
   int n1=l1-1,n2=l2-1;

   int res[l1+l2];
int sub;

//common part
   for (; n1 >= 0 && n2 >= 0; n1--, n2--, m++) {
sub=num1[n1]-num2[n2]-c;
if(sub<0){sub+=10;c=1;}
res[m]=sub;
}

   //rest of it
   if(l1>l2)
   {

       while(n1>=0)
       {
                   sub=(num1[n1]-c);
                   if(sub<0){res[m++]=sub+10;c=1;}
                   else{res[m++]=sub;c=0;}
                   n1--;
       }

    }
    else{
    }





if(sign==0){cout<<'-';}
   printrev(res,m);



    return 0;
}

