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

int lcm(int a, int b)
{
    int temp = __gcd(a, b);

    return temp ? (a / temp * b) : 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    map<string,pair<string,string>> graph;
    vector<string> positions;
    vector<int> steps;
    string path;
    cin >> path;
    for(int i=0;i<766;i++){
        string in,left,right;
        cin >> in >> left >> right;
        graph[in]=make_pair(left,right);
        if(in[2]=='A'){
            positions.push_back(in);
            steps.push_back(0);
        }
    }
   h
    dbg(graph["PXS"]);
    string pos="AAA";
    long long count=1;
    for(int j=0;j<positions.size();j++){
        while(positions[j][2]!='Z'){
            for(int i=0;i<path.length();i++){
                if(path[i]=='L'){
                    positions[j] = graph[positions[j]].first;
                }else{
                    positions[j] = graph[positions[j]].second;
                }
            }
            steps[j]+=path.length();
        }
    }
    for(int i=0;i<positions.size();i++){
        count = lcm(count,steps[i]);
    }

    cout << count << "\n";
}
