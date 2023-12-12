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

bool good(vector<char> in, vector<int> check, int ignoreLast){
    int index=0;
    int count=0;
    bool good=true;
    //dbg(in.size());
    for(int i=0;i<(in.size()-ignoreLast);i++){
        if(in[i]=='#'){
            count++;
            if(index==(check.size()-ignoreLast)){
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
    if(good&&index+1==(check.size()-ignoreLast)){
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
    
    return good&&(count==0&&index==(check.size()-ignoreLast));
}
long long ways(vector<char> in, vector<int> check){
    long long out=0;
    vector<char> working = in;
    int tries=0;
    for(int i=0;i<chars.size();i++){
        if(chars[i]=='?'){
            tries++;
        }
    }
    dbg(make_pair(chars,nums));
    for(int mask=0;mask<(1<<tries);mask++){
        int count=0;
        for(int i=0;i<chars.size();i++){
            if(in[i]=='?'){
               if(((mask)&(1<<count))){
                    working[i]='#';
                }else{
                    working[i]='.';
               }
                count++;
            }
        }
        //dbg(working);
        if(good(working,nums,0)){
            dbg(make_pair(working,nums));
            out++;
        }
    }
    return out;
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
        vector<int> temp = vector<int>(0);
        while(std::getline(test, segment, ','))
        {
            temp.push_back(stoi(segment));
        }
        b[i]=temp;
         
    }
    dbg(a[999]);
    dbg(b[999]);
    long long total=0;
    for(int line=0;line<1000;line++){
        vector<char> chars = a[line];
        vector<int> nums = b[line];
        
        //long long goods=0;
        long long beginempty_endtaken=0; //if it was .
        long long begintaken_endtaken=0; //if it was #
        long long beginempty_endempty=0; //if it was .
        long long begintaken_endempty=0; //if it was #
        vector<char> temp=chars;
        if(chars[0]=='?'){
            begin[0]='.';
            begintaken=ways(begin,check);
        }
        vector<char> temp1=chars;
        temp1.push_back('.');
        beginempty_endempty=ways(chars,check);
        vector<char> temp1=chars;
        temp1.push_back('.');
        beginempty_endtaken=ways(chars,check);
        dbg(ways);
        dbg(extendedways);
        total+=extendedways*extendedways*extendedways*extendedways*ways;
        //dbg(chars);

        //total+=goods;
    }
    dbg(total);

}
