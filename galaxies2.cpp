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
    vector<pair<long long,long long>> galaxies;
    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            char in; cin >> in;
            if(in=='#'){
                galaxies.push_back({i,j});
                a[i][j]=true;
            }
        }
    }
    int yoffset=0;
    for(int y=0;y<140;y++){
        bool allempty=true;
        for(int x=0;x<140;x++){
            if(a[y][x]){
                allempty=false;
                break;
            }
        }
        if(allempty){
            //a.insert(a.begin()+y,vector<bool>(a[0].size(),false));
            for(int i=0;i<galaxies.size();i++){
                if(galaxies[i].first>(y+yoffset)){
                    galaxies[i].first+=1000000-1;
                }
            }
            yoffset+=1000000-1;
        }
        
    }
    int xoffset=0;
    for(int x=0;x<140;x++){
        bool allempty=true;
        for(int y=0;y<140;y++){
            if(a[y][x]){
                allempty=false;
                break;
            }
        }
        if(allempty){
            for(int i=0;i<galaxies.size();i++){
                if(galaxies[i].second>(x+xoffset)){
                    galaxies[i].second+=1000000-1;
                }
            }
            xoffset+=1000000-1;
        }
    }
    dbg(xoffset);
    dbg(yoffset);
    dbg(galaxies.size());
    for(int i=0;i<442;i++){
        dbg(galaxies[i]);
    }
    long long dist=0;
    for(int i=0;i<galaxies.size();i++){
        for(int j=i+1;j<galaxies.size();j++){
            dist+=abs(galaxies[i].first-galaxies[j].first)+abs(galaxies[i].second-galaxies[j].second);
        }
    }
    dbg(dist);
    

}
