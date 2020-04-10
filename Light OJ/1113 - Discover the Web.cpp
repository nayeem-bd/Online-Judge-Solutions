#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int i,j,cnt,t,a,b;
    vector<string>s;
    vector<string>::iterator it;
    string p,q;
    cin>>t;
    for(i=1;i<=t;i++){
        a=0;
        b=0;
        cout<<"Case "<<i<<":"<<endl;
        s.push_back("http://www.lightoj.com/");
        while(1){
            cin>>p;
        if(p=="VISIT"){
            cin>>q;
            s.erase(s.begin()+b+1,s.end());
            s.push_back(q);
            cout<<q<<endl;
            a = s.size()-1;
            b = a;
        }
        else if(p=="BACK"){
            b--;
            if(b<0){
                cout<<"Ignored"<<endl;
                b++;
            }
            else{
                cout<<s[b]<<endl;
            }
        }
        else if(p=="FORWARD"){
            b++;
            if(b>a){
                cout<<"Ignored"<<endl;
                b--;
            }
            else{
                cout<<s[b]<<endl;
            }
        }
        else if(p=="QUIT") {
            break;
        }
        }
        s.clear();
    }
    return 0;
}
