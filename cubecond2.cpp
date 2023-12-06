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
    
    long long sum=0;
    int num;
    string in;
    for(int game=1;game<=100;game++){
        cin >> in; //cin game number
        dbg(in);
        cin >> in;
        dbg(in);
        int red=0;
        int green=0;
        int blue=0;
            cin >> num >> in;
            if(in[0]=='r'){
                red=max(red,num);
            }else if(in[0]=='g'){
                green=max(green,num);
            }else {
                blue=max(blue,num);
            }
        while(in[in.length()-1]==','||in[in.length()-1]==';'){
            cin >> num >> in;
            if(in[0]=='r'){
                red=max(red,num);
            }else if(in[0]=='g'){
                green=max(green,num);
            }else {
                blue=max(blue,num);
            }
            dbg(make_pair("loopin ",in));
        }
        dbg(in);
        sum+=red*green*blue;

    }
    cout << sum << "\n";
    
}
