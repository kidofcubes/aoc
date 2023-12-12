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
vector<vector<bool>> a(140,vector<bool>(140,false));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);

    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            char in; cin >> in;
            if(in=='#'){
                a[i][j]=true;
            }
        }
    }
    for(int y=0;y<a.size();y++){
        bool allempty=true;
        for(int x=0;x<a[0].size();x++){
            if(a[y][x]){
                allempty=false;
                break;
            }
        }
        if(allempty){
            a.insert(a.begin()+y,vector<bool>(a[0].size(),false));
            y++;
        }
        
    }

    for(int x=0;x<a[0].size();x++){
        bool allempty=true;
        for(int y=0;y<a.size();y++){
            if(a[y][x]){
                allempty=false;
                break;
            }
        }
        if(allempty){
            for(int y=0;y<a.size();y++){
                a[y].insert(a[y].begin()+x,false);
            }
            x++;
        }
    }
    dbg(a.size());
    dbg(a[0].size());
    vector<pair<int,int>> galaxies;
    for(int y=0;y<150;y++){
        for(int x=0;x<145;x++){
            if(a[y][x]){
                galaxies.push_back({x,y});
                //dbg(make_pair(x,y));
            }
        }
    }
    dbg(galaxies.size());
    long long dist=0;
    for(int i=0;i<galaxies.size();i++){
        for(int j=i+1;j<galaxies.size();j++){
            dist+=abs(galaxies[i].first-galaxies[j].first)+abs(galaxies[i].second-galaxies[j].second);
        }
    }
    dbg(dist);
    

}
