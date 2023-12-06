#include <bits/stdc++.h>
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
    //
    long long seeds[20];
    string in;
    cin >> in;
    for(int i=0;i<20;i++){
        cin >> seeds[i];
    }
    
    int maplengths[] = {12,29,17,18,34,35,12};
    vector<pair<long,pair<long,long>>> maps[7];
    int seedsmin[20];
    for(int map=0;map<7;map++){
        cin >> in >> in;
        dbg(in);
        vector<pair<long,pair<long,long>>> veccy = vector<pair<long,pair<long,long>>>(maplengths[map],make_pair(-1,make_pair(-2,-3))); //first is destination begin, second is source begin, third is length
        for(int i=0;i<maplengths[map];i++){
            long long num;
            cin >> num;
            dbg(num);
            veccy[i].first=num;
            cin >> num;
            dbg(num);
            veccy[i].second.first=num;
            cin >> num;
            dbg(num);
            veccy[i].second.second=num;
        }
        maps[map]=veccy;
        sort(all(veccy));
        dbg(maps[map][0].first);
        dbg(maps[map][0].second.first);
        dbg(maps[map][0].second.second);
    }
    long long minny=LLONG_MAX;
    for(int seed=0;seed<20;seed++){
        long long miny=LLONG_MIN;
        for(int map=0;map<7;map++){
            dbg(map);
            for(int i=0;i<maplengths[map];i++){
                if(maps[map][i].second.first<=seeds[seed]&&maps[map][i].second.first+maps[map][i].second.second>=seeds[seed]){
                    //dbg(seeds[seed]);
                    //dbg(maps[map][i].first);
                    //dbg(maps[map][i].second);
                    //dbg(seeds[seed]-maps[map][i].second.first);
                    seeds[seed]=maps[map][i].first+(seeds[seed]-maps[map][i].second.first);
                    break;
                }
            }
        }
        dbg(seeds[seed]);
        minny=min(minny,seeds[seed]);
    }
    
    cout << minny << "\n";


}
