
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;


long long exponent(long long base,long long power){
    if(power<0)
        return 0;
	long long res=1;
	for(int i=0;i<power;i++)
		res*=base;
	return res;
}

// tree node
struct et
{
    string value;
    et* left, *right;
};

// function to check if 'c' is an operator
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
// function to create a new node
et* newNode(string v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};

// Returns root of constructed tree for given postfix expression
et* constructTree(vector<string> postfix)
{
    stack<et *> st;
    et *t, *t1, *t2;

    // Traverse through every character of
    // input expression
    for (int i=0; i<postfix.size() ; i++)
    {
        // If operand, simply push into stack
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newNode(postfix[i]);

            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();

            //  make them children
            t->right = t1;
            t->left = t2;

            // Add this subexpression to stack
            st.push(t);
        }
    }

    //  only element wilong long be root of expression
    // tree
    t = st.top();
    st.pop();

    return t;
}

//Function to return precedence of operators
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

long long eval(et* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return stoll(root->value);

    // Evaluate left subtree
    long long l_val = eval(root->left);

    // Evaluate right subtree
    long long r_val = eval(root->right);

    // Check which operator to apply
    if (root->value=="+")
        return l_val+r_val;

    if (root->value=="-")
        return l_val-r_val;

    if (root->value=="*")
        return l_val*r_val;

    if (root->value=="/")
    	return l_val/r_val;

    return exponent(l_val,r_val);
}

//function to convert infix expression to postfix expression
int cnt=0;
void infixToPostfix(string s)
{
    std::stack<char> st;
    st.push('N');
    int l = s.length();
    vector<string> ns;
    long long num=0;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(s[i] >= '0' && s[i] <= '9')
        {
        	int j=i;
        	while((s[j] >= '0' && s[j] <= '9')&&( j<s.length() )){
        		num=num*10+s[j]-'0';
        		j++;
        	}
        	i=j-1;
        	ns.push_back(to_string(num));
        	num=0;
        	if(cnt)
                goto label;
        	continue;
        }

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
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
            {
                char c = st.top();
                st.pop();
            }
            if(cnt)
                cnt--;
            if(cnt)
                goto label;
            else continue;
        }

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')

        st.push('(');

        //If an operator is scanned
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
    //Pop along long the remaining elements from the stack
    while(st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        string str="";
        str+=c;
        ns.push_back(str);
    }

    et* r = constructTree(ns);

    stack<long long> numbers;
    for(int i=0;i<ns.size();i++){
    	if(ns[i]=="+"||ns[i]=="-"||ns[i]=="*"||ns[i]=="/"||ns[i]=="^")
    	{
    		long long num1=numbers.top();
    		numbers.pop();
    		long long num2=numbers.top();
    		numbers.pop();
    		long long res;
    		if(ns[i]=="+"){
    			res=num2+num1;
    		}
    		else if(ns[i]=="-"){
    			res=num2-num1;
    		}
    		else if(ns[i]=="*"){
    			res=num2*num1;
    		}
    		else if(ns[i]=="/"){
    			res=num2/num1;
    		}
    		else if(ns[i]=="^"){
    			res=pow(num2,num1);
    		}
    		numbers.push(res);
    	}
    	else{
    		numbers.push(stoll(ns[i]));
    	}
    }
    cout<<eval(r);
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
			cout<<"\n";
		}
	}
    return 0;
}
