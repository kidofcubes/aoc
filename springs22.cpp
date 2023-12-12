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
    for(int i=0;i<(in.size());i++){
        if(in[i]=='#'){
            count++;
            if(index==(check.size())){
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
    if(good&&index+1==(check.size())){
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
    
    return good&&(count==0&&index==(check.size()));
}
bool possible(vector<char> in, int start, int length){
    if(start+length>in.size()){
        return false;
    }
    bool possible=true;
    for(int i=start;i<start+length;i++){
        if(in[i]=='.'){
            possible=false;
            break;
        }
    }
    if(possible){
        if(start+length==in.size()){
            return true;
        }else{
            return in[start+length]!='#';
        }
    }
    return false;

}

long long ways(vector<char> in, vector<int> check){
    long long out=0;
    //dp[i][j]
    //i is index in "in" + 2 (aka clean pos)
    //j is index in check should check now
    vector<vector<long long>> dp = vector<vector<long long>>(in.size()+2,vector<long long>(check.size()+1,0LL));
    
    dp[0][0]=1;
    for(int i=0;i<in.size();i++){
        dbg(make_pair(i,dp[i]));
        for(int j=0;j<check.size()+1;j++){
            if(dp[i][j]==0){
                continue;
            }
            if(in[i]!='#'){
                dp[i+1][j]+=dp[i][j];
                //dbg(make_pair(i,j));
            }
            if(j<check.size()&&in[i]!='.'){
                if(possible(in,i,check[j])){
                    dp[i+check[j]+1][j+1]+=dp[i][j];
                    //cout << i << "-" << (i+check[j]-1) << " is possible "<<j<<" so added to "<<make_pair(i+check[j]+1,j+1)<<"\n";
                }
            }
        }
    }
    dbg(make_pair(in.size(),dp[in.size()]));
    dbg(make_pair(in.size()+1,dp[in.size()+1]));
    
    
    out=dp[in.size()][check.size()]+dp[in.size()+1][check.size()];
    return out;
}

long long ways2(vector<char> in, vector<int> check){
    long long out=0;
    vector<char> working = in;
    int tries=0;
    for(int i=0;i<in.size();i++){
        if(in[i]=='?'){
            tries++;
        }
    }
    dbg(make_pair(in,check));
    for(int mask=0;mask<(1<<tries);mask++){
        int count=0;
        for(int i=0;i<in.size();i++){
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
        if(good(working,check)){
            dbg(make_pair(working,check));
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
    //dbg(a[999]);
    //dbg(b[999]);
    long long total=0;
    for(int line=0;line<1000;line++){
        vector<char> chars = a[line];
        vector<int> nums = b[line];
        
        //dbg(ways2(chars,nums));
        //dbg(chars);
        //dbg(nums);
        chars.push_back('?');
        chars.insert(chars.end(),all(a[line]));
        chars.push_back('?');
        chars.insert(chars.end(),all(a[line]));
        chars.push_back('?');
        chars.insert(chars.end(),all(a[line]));
        chars.push_back('?');
        chars.insert(chars.end(),all(a[line]));
        
        nums.insert(nums.end(),all(b[line]));
        nums.insert(nums.end(),all(b[line]));
        nums.insert(nums.end(),all(b[line]));
        nums.insert(nums.end(),all(b[line]));
        total+=ways(chars,nums);
        //total+=goods;
    }
    dbg(total);

}
