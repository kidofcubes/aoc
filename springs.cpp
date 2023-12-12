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
vector<char> a[1000];
vector<int> b[1000];

bool good(vector<char> in, vector<int> check){
    int index=0;
    int count=0;
    bool good=true;
    //dbg(in.size());
    for(int i=0;i<in.size();i++){
        if(in[i]=='#'){
            count++;
            if(index==check.size()){
                good=false;
                break;
            }
        }else{
            if(count==0){
                continue;
            }
            if(count!=check[index]){
                good=false;
                break;
            }else{
                index++;
                count=0;
            }
            
        }
    }
    if(good&&index+1==check.size()){
        if(count!=check[index]){
            good=false;
        }else{
            index++;
            count=0;
        }
    }
    
    //dbg(good);
    //dbg(count);
    //dbg(index);
    
    return good&&(count==0&&index==check.size());
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    for(int i=0;i<1000;i++){
        //in='.'
        string instring;
        cin >> instring;
        a[i]=vector<char>(instring.begin(),instring.end());
        //in=' '
        cin >> instring;
        std::stringstream test(instring);
        std::string segment;
        b[i]=vector<int>(0);
        while(std::getline(test, segment, ','))
        {
            b[i].push_back(stoi(segment));
        }
    }
    dbg(a[999]);
    dbg(b[999]);
    long long total=0;
    for(int line=0;line<1000;line++){
        vector<char> chars = a[line];
        vector<int> nums = b[line];
        
        //long long goods=0;
        int tries=0;
        for(int i=0;i<chars.size();i++){
            if(chars[i]=='?'){
                tries++;
            }
        }
        vector<char> working = a[line];
        dbg(make_pair(chars,nums));
        for(int mask=0;mask<(1<<tries);mask++){
            int count=0;
            for(int i=0;i<chars.size();i++){
                if(chars[i]=='?'){
                    if(((mask)&(1<<count))){
                        working[i]='#';
                    }else{
                        working[i]='.';
                    }
                    count++;
                }
            }
            //dbg(working);
            if(good(working,nums)){
                dbg(make_pair(working,nums));
                total++;
            }

        }
        //dbg(chars);

        //total+=goods;
    }
    dbg(total);

}
