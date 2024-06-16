// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    unordered_map<string,int> mp;
    mp["Innova"]=10;
    
    cout<< mp.count("Innova")<<endl;
    cout<<mp["Innov"]<<endl;
    cout<<mp.size()<<endl;
    
    if(mp.find("Innova")!=mp.end()){
        cout<<"Found It"<<endl;
    }
    cout<<endl; 


    for(auto i:mp){ //i is pair 
        cout<<i.first<<"->"<<i.second<<endl; 
    }
    return 0;
}
