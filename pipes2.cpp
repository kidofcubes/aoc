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
set<pair<int,int>> pipes;
set<pair<int,int>> emptyspots1;
set<pair<int,int>> emptyspots2;

void fill(int x, int y, bool in){
    if(x<0||x>=140||y<0||y>=140){
        cout << "out\n";
        return;
    }
    if(pipes.count({x,y})||emptyspots1.count({x,y})||emptyspots2.count({x,y})){
        dbg(pipes.count({x,y}));
        dbg(emptyspots2.count({x,y}));
        dbg(emptyspots1.count({x,y}));
        return;
    }
    if(in){
        emptyspots1.insert({x,y});
    }else{
        emptyspots2.insert({x,y});
    }
    fill(x+1,y,in);
    fill(x-1,y,in);
    fill(x,y+1,in);
    fill(x,y-1,in);
}

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
    do {
        steps++;
        if(dir=='N'){
            posy--;
            if(a[posy][posx]=='7'){
                dir='W';
            }else if(a[posy][posx]=='F'){
                dir='E';
            }else{
            }
        }else if(dir=='W'){
            posx--;
            if(a[posy][posx]=='L'){
                dir='N';
            }else if(a[posy][posx]=='F'){
                dir='S';
            }else{

            }
        }else if(dir=='S'){
            posy++;
            if(a[posy][posx]=='L'){
                dir='E';
            }else if(a[posy][posx]=='J'){
                dir='W';
            }else{

            }
        }else{ //E
            posx++;
            if(a[posy][posx]=='J'){
                dir='N';
            }else if(a[posy][posx]=='7'){
                dir='S';
            }else{

            }
        }

        pipes.insert({posx,posy});
        dbg(a[posy][posx]);
        dbg(dir);
        dbg(make_pair(posx,posy));
    } while (posx!=startx||starty!=posy);
    dbg(pipes.size());
    dir='N';
    do {
        steps++;
        if(dir=='N'){
                fill(posx+1,posy,true); //true right
                fill(posx-1,posy,false);
            posy--;
                fill(posx+1,posy,true); //true right
                fill(posx-1,posy,false);
            if(a[posy][posx]=='7'){
                dir='W';
            }else if(a[posy][posx]=='F'){
                dir='E';
            }else{
            }
        }else if(dir=='W'){
                fill(posx,posy-1,true);
                fill(posx,posy+1,false);
            posx--;
                fill(posx,posy-1,true);
                fill(posx,posy+1,false);
            if(a[posy][posx]=='L'){
                dir='N';
            }else if(a[posy][posx]=='F'){
                dir='S';
            }else{

            }
        }else if(dir=='S'){
                fill(posx-1,posy,true);
                fill(posx+1,posy,false);
            posy++;
                fill(posx-1,posy,true);
                fill(posx+1,posy,false);
            if(a[posy][posx]=='L'){
                dir='E';
            }else if(a[posy][posx]=='J'){
                dir='W';
            }else{

            }
        }else{ //E
                fill(posx,posy+1,true);
                fill(posx,posy-1,false);
            posx++;
                fill(posx,posy+1,true);
                fill(posx,posy-1,false);
            if(a[posy][posx]=='J'){
                dir='N';
            }else if(a[posy][posx]=='7'){
                dir='S';
            }else{

            }
        }

    } while (posx!=startx||starty!=posy);
    

    bool right=true;
    for(pair<int,int> pos : emptyspots2){
        dbg(pos);
    }
    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            if(pipes.count({j,i})){
                if(a[i][j]=='J'){
                    cout << "┘";
                }else if(a[i][j]=='7'){
                    cout << "┐";
                }else if(a[i][j]=='F'){
                    cout << "┌";
                }else if(a[i][j]=='L'){
                    cout << "└";
                }else if(a[i][j]=='-'){
                    cout << "─";
                }else if(a[i][j]=='|'){
                    cout << "│";
                }else {
                    cout << "?";
                }

                
            }else if(emptyspots2.count({j,i})){
                cout << "L";
            }else if(emptyspots1.count({j,i})){
                cout << "R";
            }else{
                cout << ".";
            }
        }
        cout << "\n";
    }
    
    for(pair<int,int> pos : emptyspots1){
        if(pos.first==0||pos.first==139||pos.second==0||pos.second==139){
            right=false;
            break;
        }
    }
    dbg(right);
        dbg(emptyspots1.size());
        dbg(emptyspots2.size());
    
    
    
    

}
