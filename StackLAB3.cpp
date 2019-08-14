#include<iostream>
#include<string>
#include<stack>

using namespace std;

void check();

int main()
{
int n;
cin>>n;
while(n>0)
{
check();
n--;
}

return 0;
}

void check()
{
stack<char> stk;
string s;
int flag=0,j=0;
cin>>s;

for(int i=0;i<s.length();i++)
{

if(s[i]=='|')
{
  if(!stk.empty())

     {if(stk.top()=='|') {stk.pop();continue;}
      else{stk.push(s[i]);}}

  else{stk.push(s[i]);continue;}

}

else if((s[i]=='{')||(s[i]=='(')||(s[i]=='<')||(s[i]=='['))
{
stk.push(s[i]);flag=1;continue;
}
else if(!stk.empty())
{
if(s[i]=='}'){if(stk.top()=='{'){stk.pop();continue;}else{break;}}
if(s[i]==')'){if(stk.top()=='('){stk.pop();continue;}else{break;}}
if(s[i]==']'){if(stk.top()=='['){stk.pop();continue;}else{break;}}
if(s[i]=='>'){if(stk.top()=='<'){stk.pop();continue;}else{break;}}
//if(s[i]=='|'){if(stk.top()=='|'){stk.pop();continue;}else{break;}}
}
else{flag=0;break;}

}//end of for loop

if((stk.empty())&&flag==1){cout<<"YES"<<endl;}
else{cout<<"NO"<<endl;}


}
