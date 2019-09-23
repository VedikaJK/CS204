#include<bits/stdc++.h>

  
using namespace std; 
  
int partition(long long int arr[], int l, int r,long long int k); 

long long int findMedian(long long int arr[], int n) 
{ 
    sort(arr, arr+n);  
    return arr[n/2];  
} 
 
// ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
long long int kthSmallest(long long int arr[], int l, int r, int k) 
{ 
     
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
        int i;
	long long int median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        long long int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        int pos = partition(arr, l, r, medOfMed); 
  
        
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1) 
            return kthSmallest(arr, l, pos-1, k); 
  
        
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
    return INT_MAX; 
} 
  
void swap(long long int *a,long long int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
 
int partition(long long int arr[], int l, int r, long long int x) 
{ 
    
    int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
   
    i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
  

int main()
{
int t;
cin>>t;
while(t--){
int n;
cin>>n;
long long int x[n];
long int y[n];
long long int d[n];
for(int i=0;i<n;i++)
{
cin>>x[i];
cin>>y[i];
d[i]=(x[i]*x[i]+y[i]*y[i]);
}
int n1;
if(n%2!=0) n1=n/2 + 1;
else n1=n/2;
cout<<sqrt(kthSmallest(d,0,n-1,n1))<<endl;
}
return 0;
}
