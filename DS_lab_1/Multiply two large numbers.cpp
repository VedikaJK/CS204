#include<iostream>
#include<string>
using namespace std;
string addn(string,string);
string revcon(int [], int);


int main(){
	int T;
	cin>>T;
	while(T>0)
	{
string s1,s2;
cin>>s1>>s2;
int l1,l2;
l1=s1.length();
l2=s2.length();
int res[l1+l2]={0};




string ans1="0",ans2;
int num1[l1],num2[l2];
int i,j;

for(i=l1-1,j=0;i>=0;j++,i--)
    {
    num1[j]=s1[i]-'0';
    }

    for(i=l2-1,j=0;i>=0;j++,i--)
    {
    num2[j]=s2[i]-'0';
    }
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

for(int n2=0;n2<l2;n2++)
{
    int carry=0;
    int k=0;
    for(int n1=0;n1<l1;n1++)
    {
        res[k]=(num1[n1]*num2[n2]+carry)%10;
        carry=(num1[n1]*num2[n2]+carry)/10;
        k++;
    }
    //cout<<"hello"<<k;
        if(carry>0)
        {
            res[k]=carry;
            k++;
        }
       // for(int m=0;m<k;m++){cout<<res[m]<<endl;}
    ans2=revcon(res,k);
    int x=n2;
    //cout<<"ans2="<<ans2<<endl;
    //cout<<x<<endl;
    while(x>0)
    {
        ans2=ans2+'0';
        x--;
    }

ans1=addn(ans1,ans2);


}
cout<<ans1<<endl;
	
	T--;}
  return 0;
}
	
	
	
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string addn(string s1,string s2){

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

string s=revcon(res,m);
return s;

}



string revcon(int arr[],int n)
{

	string str;
	for (int i=n-1;i>=0;i--) {
		str.push_back(arr[i] + '0');
	}

	return str;
}


