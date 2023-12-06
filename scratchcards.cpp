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
    int nums[10];
    set<int> othernums;
    string in;
    for(int card=0;card<219;card++){
        cin >> in >> in;
        dbg(in);
        for(int i=0;i<10;i++){
            cin >> nums[i];
        }
        cin >> in;
        dbg(in);
        for(int i=0;i<25;i++){
            int num;
            cin >> num;
            othernums.insert(num);
        }
        int score=0;
        for(int i=0;i<10;i++){
            if(othernums.count(nums[i])){
                score++;
            }
        }
        othernums.clear();
        if(score>0){
            sum+=(1<<(score-1));
        }
    }
    cout << sum << "\n";

}
