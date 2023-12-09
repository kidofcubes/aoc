#include <bits/stdc++.h>
#include <cassert>
using namespace std;

// === Debug macro starts here ===

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

// === Debug macro ends here ===
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    map<string,pair<string,string>> graph;
    string path;
    cin >> path;
    for(int i=0;i<766;i++){
        string in,left,right;
        cin >> in >> left >> right;
        graph[in]=make_pair(left,right);
    }
    dbg(graph["PXS"]);
    string pos="AAA";
    long long count=0;
    while(pos!="ZZZ"){
        for(int i=0;i<path.length();i++){
            if(path[i]=='L'){
                pos = graph[pos].first;
            }else{
                pos = graph[pos].second;
            }
        }
        count+=path.length();
        //cout << "at "<<pos<<" after "<<count<<"\n";
    }

    cout << count << "\n";
}
