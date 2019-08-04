#include <iostream>
#include<string>
using namespace std;

int compare(string ,string);
string revcon(int [], int);
string subtract(string ,string );


int main()
{
    int T;
	cin>>T;
	for(int k=0;k<T;k++)
        {
	string s1,s2,s="";
	cin>>s1>>s2;
	int l1=s1.length();
	int l2=s2.length();
	if(s2=="0") {cout<<"Undefined"<<endl; return 0;}
	else if(compare(s1,s2)==0) {cout<<0<<" "<<s1<<endl;return 0;}
	else if(compare(s1,s2)==-1) {cout<<1<<" "<<0<<endl;return 0;}
	else{
		string x="";
		int i=l2;
		x=s1.substr(0,l2);
		if(compare(x,s2)==0){
            x+=s1[i];
            i++;
		}
		//cout<<x;
		while(i<l1){
			int q =0;
			while(compare(x,s2)==1){


					x=subtract(x,s2);
					q++;

			}
			s.push_back(q+'0');
			//if(i!=l2 || q!=0) s.push_back(q+'0');
			//cout<<i<<"here"<<s[i]
			//cout<<s2;
			x.push_back(s1[i]);
			i++;
			//cout<<x;
			while(i<l1&&compare(x,s2)==0){ x.push_back(s1[i]);
			i++;
			s+='0';
			}
		}
		//cout<<x<<s2;
		int q=0;
		while(compare(x,s2)==1){


					x=subtract(x,s2);
					//cout<<x<<endl;

					q++;

			}
			//cout<<q;
			s+=(q+'0');
		if(x=="") x.push_back('0');
		cout<<s<<" "<<x<<"\n";
	}
	}
	return 0;
}

//****************************************************************************************************************************************
int compare(string s1,string s2)
{
    string ans="";
    int l1,l2,i=0;
    l1=s1.length();
    l2=s2.length();
    if(l1>l2){return 1;} //str1 > str2. no swap needed
    else if(l1<l2){return 0;} //swap is needed
    else{

         for(;i<l1;i++){
            if(s1[i]>s2[i]){return 1;}
            if(s1[i]<s2[i]){return 0;}

         }
         if (i==l1){return -1;}//equals. so ans is 1 and 0
    }
return 3;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string subtract(string s1,string s2){

if(s1==s2){return "0";}
string ans;
 // int sign;
   int l1,l2;
   l1=s1.length();
   l2=s2.length();
   int b;string temp;
//making sure str1 > str2

if(l1>l2){}

//cout<<"1. s1 is bigger. "<<s1<<endl;

else if(l1<l2)

       {
    //cout<<"2. hello, we must swap";

    temp=s1;
    s1=s2;
    s2=temp;
    //cout<<"3.  s1 is bigger. "<<s1<<endl;

//    sign=0;
        }

else{ //if l1=l2

    for(int i=0;i<l1;i++)
    {
        if(s1[i]>s2[i]){
            //cout<<"4. no swapping. s1 is bigger "<<s1<<endl;

//            sign=1;

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
//    sign=0;
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
    else{}
    ans=revcon(res,m);
    return ans;
}
//============================================================================================================================================
string revcon(int arr[],int n)
{
	string str;
	for (int i=n-1;i>=0;i--) {
		str.push_back(arr[i] + '0');
	}
	int c=0;
	for(int i=0;i<str.length();i++){
        if(str[i]=='0') c++;
        else break;
	}
	str=str.substr(c,str.length()-c);
	return str;
}
//66666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666
