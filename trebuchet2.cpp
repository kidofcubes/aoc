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

int getdigit(string in,int j){
    if(in[j]<='9'){
        return in[j]-'0';
    }
    if(j>=2){
        if(in[j-2]=='o'&&in[j-1]=='n'&&in[j]=='e'){
            return 1;
        }
        if(in[j-2]=='t'&&in[j-1]=='w'&&in[j]=='o'){
            return 2;
        }
        if(in[j-2]=='s'&&in[j-1]=='i'&&in[j]=='x'){
            return 6;
        }
    }
    if(j>=3){
        if(in[j-3]=='f'&&in[j-2]=='o'&&in[j-1]=='u'&&in[j]=='r'){
            return 4;
        }
        if(in[j-3]=='f'&&in[j-2]=='i'&&in[j-1]=='v'&&in[j]=='e'){
            return 5;
        }
        if(in[j-3]=='n'&&in[j-2]=='i'&&in[j-1]=='n'&&in[j]=='e'){
            return 9;
        }
    }
    if(j>=4){
        if(in[j-4]=='t'&&in[j-3]=='h'&&in[j-2]=='r'&&in[j-1]=='e'&&in[j]=='e'){
            return 3;
        }
        if(in[j-4]=='s'&&in[j-3]=='e'&&in[j-2]=='v'&&in[j-1]=='e'&&in[j]=='n'){
            return 7;
        }
        if(in[j-4]=='e'&&in[j-3]=='i'&&in[j-2]=='g'&&in[j-1]=='h'&&in[j]=='t'){
            return 8;
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    long long sum=0;
    for(int i=0;i<1000;i++){
        string in;
        cin >> in;
        cout << in << "\n";
        int lastnum=-1;
        for(int j=0;j<in.length();j++){
            int digit=getdigit(in,j);
            if(digit!=-1){
                if(lastnum==-1){
                    sum+=digit*10;
                }
                lastnum=digit;
            }
        }
        sum+=lastnum;
    }
    cout << sum << "\n";
    
}
