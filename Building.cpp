#include<bits/stdc++.h>
using namespace std;


//class Edge
class Edge{
    public:
    int a,b,w;
    Edge(int a, int b, int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }
};

//bool compare function
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}


const int N=1e5+5;
//parent track
int parent[N];

//parentsize track
int parentSize[N];
void dsu_set(int n){
    for(int i=0; i<n; i++){
        //initially all parent are -1
        parent[i]=-1;
        //initially all parent size are 1
        parentSize[i]=1;
    }
}

//find implementation
int dsu_find(int node){
    while(parent[node]!=-1){
        node=parent[node];
    }
 return node;
}

//union implementation
void dsu_union(int a, int b){
    int leaderA= dsu_find(a);
    int leaderB= dsu_find(b);
    if(leaderA !=leaderB){
        if(parentSize[leaderA]> parentSize[leaderB]){
        //when leader A
        parent[leaderB]=leaderA;
        parentSize[leaderA]+=parentSize[leaderB];
    }
    else{
        //when leader B
        parent[leaderA]=leaderB;
        parentSize[leaderB]+=parentSize[leaderA];
    }


    }
    

}
int main(){
    int n, e;
    cin>>n>>e;
    dsu_set(n);
    vector<Edge>v;
    vector<Edge>ans;
    while(e--){
        int a, b, w;
        cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }

    //sorting
    sort(v.begin(), v.end(), cmp);
    for(Edge val: v){
        int a= val.a;
        int b= val.b;
        int w= val.w;
        int leaderA= dsu_find(a);
        int leaderB= dsu_find(b);
        if(leaderA ==  leaderB){
            continue;
            

        }
        ans.push_back(val);
        dsu_union(a,b);
    }

    long long sum=0;
    
    for(Edge val: ans){
        sum+=(long long)(val.w);
    }


    //print minimum cost
    if(ans.size()==n-1){
        cout<<sum<<endl;
    }
    else{
        cout<<"-1";
    }
    
    
    return 0;
}