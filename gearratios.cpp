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

char in[140][140];

int scan(int i,int j){
    if(i<0||i>=140||j<0||j>=140){
        return 0;
    }
    if(in[i][j]<'0'||in[i][j]>'9'){
        return 0;
    }

    int l=j;
    int r=j;
    while(--l>=0&&in[i][l]>='0'&&in[i][l]<='9'){}
    while(++r<140&&in[i][r]>='0'&&in[i][r]<='9'){}

    int sum=0;
    dbg(l);
    dbg(r);
    
    for(int k=l+1;k<r;k++){
        sum+=(in[i][k]-'0')*pow(10,(r-k)-1);
        in[i][k]='.';
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            cin >> in[i][j];
        }
    }

    
    long long sum=0;
    for(int i=0;i<140;i++){
        for(int j=0;j<140;j++){
            if(in[i][j]!='.'&&(in[i][j]>'9'||in[i][j]<'0')){
                sum+=scan(i-1,j-1);
                sum+=scan(i-1,j);
                sum+=scan(i-1,j+1);
                
                sum+=scan(i,j-1);
                sum+=scan(i,j+1);

                sum+=scan(i+1,j-1);
                sum+=scan(i+1,j);
                sum+=scan(i+1,j+1);
            }
        }
    }
    cout << sum << "\n";

    

}
