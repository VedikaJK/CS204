#include<iostream>
#include<math.h>

using namespace std;

struct node{
double x;
double y;
node* next;
};

class linkedlist{
private:
node* head;
public:
linkedlist(){ head=NULL;}
void AddFirst(double ,double);
void DelFirst();
void Del(double,double);
void Search(double);
void Search(double,double);
void Length();
void display();
void deleteit(node* );
double distance(node* );
};

int main(){
int n;
linkedlist list;
cin>>n;
while(n>0){
int i;
cin>>i;
double a,b;
switch(i){
case 1:  cin>>a>>b; list.AddFirst(a,b); break;
case 2: list.DelFirst();break;
case 3:  cin>>a>>b; list.Del(a,b);break;
case 4: double d; cin>>d; list.Search(d);break;
case 5:   cin>>a>>b; list.Search(a,b); break;
case 6: list.Length();
}
n--;}

return 0;
}

double linkedlist::distance(node* ptr){
return sqrt((ptr->x)*(ptr->x)+(ptr->y)*(ptr->y));}

void linkedlist:: display(){
node* tmp;
tmp=head;
if(head==NULL){cout<<"Empty"<<endl;}
else{while(tmp!=NULL) {cout<<"("<<tmp->x<<","<<tmp->y<<")"<<"  "; tmp=tmp->next;} cout<<endl;}
}

void linkedlist::deleteit(node* ptr){
//not concerned with deleting first ele
//only mid or end
node* tmp= new node;
tmp=head;
while(tmp->next!=ptr){tmp=tmp->next;}
tmp->next=ptr->next;
delete ptr;}


void linkedlist::AddFirst(double a ,double b){
node *tmp = new node;
tmp->x=a;
tmp->y=b;
if(head==NULL){tmp->next=NULL;}
else{tmp->next=head;}
head=tmp;
}


void linkedlist::DelFirst(){
node *tmp = new node;
if(head==NULL){cout<<"-1"<<endl;}
else{node *tmp = new node; 
tmp=head;
head=head->next;
delete tmp;}
}

void linkedlist::Del(double a,double b)
{
node* prev=NULL;
node* curr=head;
if(head==NULL){cout<<"-1"<<endl;}
else   {
          if ((head->x==a)&&(head->y==b))   {DelFirst();}
          else
             {while(1)
                {
                 if((curr->x==a)&&(curr->y==b)){deleteit(curr); break;}
                 else{prev=curr;curr=curr->next;}
                 if(curr==NULL){cout<<"-1"<<endl; break;}
                 }
              }//end of else
        }

}//end of funcn

void linkedlist::Search(double d){
node *tmp= new node;
int cnt=0;
tmp= head;
while(tmp!=NULL){if(distance(tmp)<=d) cnt++; tmp=tmp->next;}
cout<<cnt<<endl;}


void linkedlist::Search(double a,double b){
node* prev=NULL;
node* curr=head;
if(head==NULL){cout<<"False"<<endl;}
else   {
             while(1)
                {
                 if((curr->x==a)&&(curr->y==b)){cout<<"True"<<endl; break;}
                 else{prev=curr;curr=curr->next;}
                 if(curr==NULL){cout<<"False"<<endl; break;}
                 }
              
        }
}//end of funcn

void linkedlist::Length(){
node*tmp=head;
int c=0;
while(tmp!=NULL){c++;tmp=tmp->next;}
cout<<c<<endl;
}
