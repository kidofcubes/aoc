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
    string in;
    vector<string> a[100];
    for(int i=0;i<100;i++){
        do{
            getline(cin,in);
            a[i].push_back(in);
        }while(in.length()>0);
        a[i].pop_back();
    }
    dbg(a[0]);
    long long total=0;
    for(int b=0;b<100;b++){
        bool found=false;
        for(int y=1;y<a[b].size();y++){ //horizontal, line is behind [y];
            int smudges=0;
            for(int i=0;i<min(y,(int)(a[b].size()-y));i++){ //loop through rows
                //(y-1)-i y+i
                for(int j=0;j<a[b][0].size();j++){ //check each bit in row
                    if(a[b][(y-1)-i][j]!=a[b][y+i][j]){
                        smudges++;
                        if(smudges>1){
                            break;
                        }
                    }
                }
                if(smudges>1){
                    break;
                }
            }
            if(smudges==1){
                found=true;
                total+=y*100;
                break;
            }
        }
        if(found){
            continue;
        }
        for(int x=1;x<a[b][0].length();x++){ //vertical, line is behind [x];
            int smudges=0;
            for(int i=0;i<min(x,(int)(a[b][0].size()-x));i++){ //check each column
                //(x-1)-i x+i 
                for(int j=0;j<a[b].size();j++){ //check each bit in column
                    if(a[b][j][(x-1)-i]!=a[b][j][x+i]){
                        smudges++;
                        if(smudges>1){
                            break;
                        }
                    }
                }
                if(smudges>1){
                    break;
                }
            }
            if(smudges==1){
                found=true;
                total+=x;
                break;
            }
        }
        if(!found){
            cout << "OH NOOOOOOOOOOOO\n";
        }
    }
    cout << total << "\n";

}
