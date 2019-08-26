
#include <bits/stdc++.h>

using namespace std;

map<string,long long> mp;
map<string,long long>::iterator it;

long long pow(long long base,long long power){
    if(power<0)
        return 0;
	long long res=1;
	for(int i=0;i<power;i++)
		res*=base;
	return res;
}
// node of tree
struct et
{
    string val;
    et* left, *right;
};

// to check if operator
bool isOperator(string c)
{
    if (c == "+" || c == "-" ||
            c == "*" || c == "/" ||
            c == "^")
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

// to make new node
et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;   
    temp->val = v;
    return temp;
};
// construct a tree from vector
et* makeTree(vector<string> postfix)
{
    stack<et *> st;
    et *t, *t1, *t2;

    for (int i=0; i<postfix.size() ; i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else
        {
            t = newNode(postfix[i]);

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}
// precedence
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
// recursive funcn to evaluate tree
long long eval(et* root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right){
        bool isnum=true;
        for(int i=0;i<root->val.size();i++)
        {
            if(root->val[i]>='0'&&root->val[i]<='9')
                continue;
            else{
                isnum=false;
                break;
            }
        }
        if(isnum)
            return stoll(root->val);
        else
        {
            it=mp.find(root->val);
            return it->second;
        }
    }

    long long l_val = eval(root->left);

    long long r_val = eval(root->right);

    if (root->val=="+")
        return l_val+r_val;

    if (root->val=="-")
        return l_val-r_val;

    if (root->val=="*")
        return l_val*r_val;

    if (root->val=="/")
    	return l_val/r_val;

    return pow(l_val,r_val);
}

int cnt=0;

bool cannot_eval=false;

long long evaluate_val(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    { 
        // operand
        if(s[i] >= '0' && s[i] <= '9')
        {
        	int j=i;
        	string str;
        	while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
        		str.push_back(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.push_back(str);
        	if(cnt)
                goto label;
        	continue;
        }
        // variable
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
        	while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
        		var.push_back(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.push_back(var);
        	if(cnt)
                goto label;
        	continue;
        }
        // ')'
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.push_back(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }
         // '('
        else if(s[i] == '(')

        st.push('(');

        else{
            //unary
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.push_back("0");
               }
            //push in vector
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
            	if(s[i]=='^'&&st.top()=='^')
            		break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.push_back(str);
            }
            st.push(s[i]);
        }

    }
    // push in vector
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.push_back(str);
    }
    
    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool isnum=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                isnum=false;
                break;
            }
        }
        if(!isnum){
            it=mp.find(ns[i]);
            if(it==mp.end())
            {
                cannot_eval=true;
                return 0;
            }
        }
    }

    et* r = makeTree(ns);

    long long result=eval(r);
    return result;
}

void infixToPostfix(string s)
{


    bool is_assignment=false;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='='){
            is_assignment=true;
            break;
        }
    }
    if(is_assignment){
        long long val=evaluate_val(s.substr(i+1,s.length()-i-2));
        string variable=s.substr(1,i-1);
        if(cannot_eval){
            cout<<"CANT BE EVALUATED\n";
            cannot_eval=false;
        }
        else{
            it=mp.find(variable);
            if(it==mp.end())
                mp.insert({variable,val});
            else
                it->second=val;
        }
        return;
    }


    std::stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    for(int i = 0; i < l; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
        	int j=i;
        	string str;
        	while(( j<s.length() )&&(s[j] >= '0' && s[j] <= '9')){
        		str.push_back(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.push_back(str);
        	if(cnt)
                goto label;
        	continue;
        }

        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            int j=i;
            string var;
        	while((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
        		var.push_back(s[j]);
        		j++;
        	}
        	i=j-1;
        	ns.push_back(var);
        	if(cnt)
                goto label;
        	continue;
        }
        else if(s[i] == ')')
        {
            label:
            while(st.top() != 'N' && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
               ns.push_back(str);
            }
            if(st.top() == '(')
                st.pop();
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        else if(s[i] == '(')

        st.push('(');

        else{
            if(s[i]=='-'&&(i==0||s[i-1]=='('||isOperator(s[i-1]))){
                cnt++;
                st.push('(');
                ns.push_back("0");
               }
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))
            {
            	if(s[i]=='^'&&st.top()=='^')
            		break;
                char c = st.top();
                st.pop();
                string str="";
                str+=c;
                ns.push_back(str);
            }
            st.push(s[i]);
        }

    }
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.push_back(str);
    }

    for(int i=0;i<ns.size();i++){
        if(isOperator(ns[i]))
            continue;
        bool isnum=true;
        for(int j=0;j<ns[i].size();j++)
        {
            if(ns[i][j]>='0'&&ns[i][j]<='9')
                continue;
            else{
                isnum=false;
                break;
            }
        }
        if(!isnum){
            it=mp.find(ns[i]);
            if(it==mp.end())
            {
                cout<<"CANT BE EVALUATED\n";
                return;
            }
        }
    }

    et* r = makeTree(ns);

    long long result=eval(r);
    cout<<result<<"\n";
}



int main()
{
	long long n;
	cin>>n;
	cin.ignore();
	while(n--){
		long long rows;
		cin>>rows;
		cin.ignore();
		while(rows--){
			string str="(",str2;
			getline(cin,str2);
			str+=str2;
			str+=")";
			infixToPostfix(str);
		}
		mp.clear();
	}
    return 0;
}
