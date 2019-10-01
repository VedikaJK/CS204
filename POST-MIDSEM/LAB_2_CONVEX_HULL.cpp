/***
Name: Vedika Kulkarni
Roll No: 180101095
Data Structures and algorithms lab
CONVEX HULL
***/

#include<bits/stdc++.h>

using namespace std;
//---------------------------------------------------
struct point{
    int x;
    int y;
};
//---------------------------------------------------
point p0;

//---------------------------------------------------
int dist(point p1,point p2);
int orientation(point a, point b, point c){
    int D;
    D=(b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
    if(D>0) return 1; //clockwise
    else if (D<0) return 2; //anticlockwise
    else return 0; //collinear  
}
//-----------------------------------------------------

int comparison(const void *vp1, const void *vp2 ){
    point* p1=(point *)vp1;
    point* p2=(point *)vp2;
    int c=orientation(p0,*p1,*p2);
    if(c==2) return -1; //no swapping
    else if(c==1) return 1; // swapping
    else
    {
        if(dist(p0,*p1)<=dist(p0,*p2))
        return -1;
        else
        return 1;
    }
}
//-----------------------------------------------------
point nextToTop( stack<point> &S){
point p=S.top();  //**********
S.pop();
point res= S.top(); //*************
S.push(p);
return res;
}
//------------------------------------------------------
void swap(point &p1,point &p2){
    point temp=p1; //**********
    p1=p2;
    p2=temp;
}
//------------------------------------------------------
int dist(point p1,point p2){
    return ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
//------------------------------------------------------
void ConvexHull(point pts[],int n){
    if(n<3){
        cout<<"Not possible.";
        return ;
    }
    int min=0, yMin=pts[0].y;
    int y;
    for(int i=0;i<n;i++){
        y=pts[i].y;
        if((y<yMin)||(y==yMin&&pts[i].x<pts[min].x)){
            yMin=y;
            min=i;
        }
    }
    swap(pts[0],pts[min]);
    p0=pts[0];
    qsort(&pts[1],n-1,sizeof(point),comparison);
    stack<point> S;
    S.push(pts[0]);
    S.push(pts[1]);
    S.push(pts[2]);
    for(int i=3;i<n;i++){
        while(orientation(nextToTop(S),S.top(),pts[i])!=2)
            S.pop();
        S.push(pts[i]);
    }
    while(!S.empty()){
        point p;
        p=S.top();
        S.pop();
        cout<<"("<<p.x<<","<<p.y<<")"<<"  ";
    }

}

int main(){
    int T;
    cin>>T;
    point pts[T];
    for(int i=0;i<T;i++){
        cin>>pts[i].x>>pts[i].y;
    }
    ConvexHull(pts,T);
}