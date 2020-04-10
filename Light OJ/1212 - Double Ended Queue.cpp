#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,i,j,k,n,m,x;
    deque<int>d;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>m>>n;
        cout<<"Case "<<i<<":\n";
        for(j=0;j<n;j++){
            string ch;
            cin>>ch;
            if(ch=="pushLeft"){
                cin>>x;
                if(d.size()<m){
                    d.push_front(x);
                    cout<<"Pushed in left: "<<x<<endl;
                }
                else{
                    cout<<"The queue is full\n";
                }
            }
            else if(ch=="pushRight"){
                cin>>x;
                if(d.size()<m){
                    d.push_back(x);
                    cout<<"Pushed in right: "<<x<<endl;
                }
                else{
                    cout<<"The queue is full\n";
                }
            }
            else if(ch=="popLeft"){
                if(!d.empty()){
                    cout<<"Popped from left: "<<d.front()<<endl;
                    d.pop_front();
 
                }
                else{
                    cout<<"The queue is empty\n";
                }
            }
            else if(ch=="popRight"){
                if(!d.empty()){
                    cout<<"Popped from right: "<<d.back()<<endl;
                    d.pop_back();
 
                }
                else{
                    cout<<"The queue is empty\n";
                }
            }
        }
 
        d.clear();
 
    }
    return 0;
}
 
