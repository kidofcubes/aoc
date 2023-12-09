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
    //21 in each line 
    vector<vector<int>> in(200,vector<int>(21,0));
    for(int i=0;i<200;i++){
        for(int j=0;j<21;j++){
            cin >> in[i][j];
        }
    }
    vector<vector<int>> steps(200,vector<int>(0));
    long long out=0;
    for(int line=0;line<200;line++){
        int layers=0;
        while(true){
            bool good=true;
            for(int i=0;i<20-layers;i++){
                in[line][i]=in[line][i+1]-in[line][i];
                if(in[line][i]!=0){
                    good=false;
                }
            }
            layers++;
            steps[line].push_back(in[line][20-layers]);
            
            if(good){
                break;
            }
        }
        for(int i=steps[line].size()-1;i>0;i--){
            steps[line][i-1]+=steps[line][i];
        }
        out+=in[line][20]+steps[line][0];
    }
    dbg(out);

}
