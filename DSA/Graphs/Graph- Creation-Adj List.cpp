#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// class Graph{
//     public: 
//         unordered_map<int,list<int>> adjList;
        
//         void addEdge(int u,int v,bool direction){
//             //direction->0 undirected
//             //direction->1 directed 
//             if(direction==1){
//                 //u->v not ulta 
//                 adjList[u].push_back(v);
//             }
//             else{
//                 //direction=0
//                 //u--v => u->v and also v->u 
//                 adjList[u].push_back(v);
//                 adjList[v].push_back(u);
//             }
//             cout<<endl<<"Printing adjList"<<endl;
//             printAdjList();
//             cout<<endl;
//         }
        
//         void printAdjList(){
//             for(auto i: adjList){
//                 cout<<i.first<<"-> {";
//                 for(auto neighbour:i.second){
//                     cout<<neighbour<<", ";
//                 }
//                 cout<<"}"<<endl;
//             }
//         }
// };

//replace int with T in the below code
template <typename T>

class Graph{
    public:
        unordered_map <T,list<pair<T,int>>> adjList;
        
        void addEdge(T u,T v,int weight,int direction){
            if(direction==1){
                //direction->1 directed else undirected 
                adjList[u].push_back(make_pair(v,weight));
            }
            else{
                adjList[u].push_back(make_pair(v,weight));
                adjList[v].push_back(make_pair(u,weight));
            }
            printAdjList();
            cout<<endl;
        }
        
        void printAdjList(){
            for(auto i: adjList){
                cout<<i.first<<": {";
                for(pair<T,int>p :i.second){
                    cout<<"{"<<p.first<<", "<<p.second<<"}, ";
                }
                cout<<endl;
            }
        }
};

//Tc and Sc ???

int main(){
    //specified T as int here 
    Graph<char> g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(2,3,0);
    
    g.addEdge('a','b',5,1);
    g.addEdge('b','c',10,1);
    g.addEdge('c','d',20,1);
    
    
    return 0;
}








