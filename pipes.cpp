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

char a[140][140];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    int startx,starty;
    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            cin >> a[i][j];
            if(a[i][j]=='S'){
                starty=i;
                startx=j;
            }
        }
    }
    int posx=startx;
    int posy=starty;
    dbg(startx);
    dbg(starty);
    char dir='N';
    int steps=0;
    vector<pair<int,int>> positions;
    do {
        steps++;
        if(dir=='N'){
            posy--;
            if(a[posy][posx]=='7'){
                dir='W';
            }else if(a[posy][posx]=='F'){
                dir='E';
            }
        }else if(dir=='W'){
            posx--;
            if(a[posy][posx]=='L'){
                dir='N';
            }else if(a[posy][posx]=='F'){
                dir='S';
            }
        }else if(dir=='S'){
            posy++;
            if(a[posy][posx]=='L'){
                dir='E';
            }else if(a[posy][posx]=='J'){
                dir='W';
            }
        }else{ //E
            posx++;
            if(a[posy][posx]=='J'){
                dir='N';
            }else if(a[posy][posx]=='7'){
                dir='S';
            }
        }
        positions.push_back({posx,posy});
        dbg(a[posy][posx]);
        dbg(dir);
        dbg(make_pair(posx,posy));
    } while (posx!=startx||starty!=posy);
    
    dbg(positions.size()/2);

    
    

}
