#include<bits/stdc++.h>

using namespace std;

int compare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 
 
void printLargest(vector<string> arr) 
{ 
   
    sort(arr.begin(), arr.end(), compare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 

int main(){
	
	int n,t,i=0;
	cin>>t;
	while(t--){
	cin>>n;
	vector<string> vec(n);
	cin.ignore();
	while(i<n){
	cin>>vec[i];
	i++;}
	printLargest(vec);
	}
return 0;
}


