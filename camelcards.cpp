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

int type(string hands){ //6 to 0
    
    multiset<char> cards({hands[0],hands[1],hands[2],hands[3],hands[4]});
    set<char> distcards({hands[0],hands[1],hands[2],hands[3],hands[4]});
    //int jokers=cards.count('J');
    //cards.erase('J');
    //distcards.erase('J');
    //if(cards.size()>0&&jokers>0){
    //    char big='J';
    //    if(cards.count(big)<cards.count(hands[0])){ big=hands[0]; }
    //    if(cards.count(big)<cards.count(hands[1])){ big=hands[2]; }
    //    if(cards.count(big)<cards.count(hands[2])){ big=hands[3]; }
    //    if(cards.count(big)<cards.count(hands[3])){ big=hands[4]; }
    //    if(cards.count(big)<cards.count(hands[4])){ big=hands[5]; }
    //    for(int i=0;i<5;i++){
    //        if(hands[i]=='J'){
    //            hands[i]=big;
    //        }
    //    }
    //    cards = multiset<char>({hands[0],hands[1],hands[2],hands[3],hands[4]});
    //}
    if(distcards.size()==5){ // high card
        return 0;
    }else if (distcards.size()==4){ // one pair
        return 1;
    }else if (distcards.size()==3){
        if(cards.count(hands[0])==2||cards.count(hands[1])==2){ // two pair
            return 2;
        }else{ // three kind
            return 3;
        }
    }else if (distcards.size()==2){
        if(cards.count(hands[0])==2||cards.count(hands[0])==3){ //fullhouse
            return 4;
        }else{ //four kind
            return 5;
        }
    }else{ //five kind
        return 6;
    }
} //higher is better
int ranking(char card){
    //if      (card=='J'){
    ///    return -1;
    //}else 
    if(card=='T'){
        return '9'+1;
    }else if(card=='J'){
        return '9'+2;
    }else if(card=='Q'){
        return '9'+3;
    }else if(card=='K'){
        return '9'+4;
    }else if(card=='A'){
        return '9'+5;
    }else{
        return card;
    }
    
}

bool compare(pair<string,int> a, pair<string,int> b){
    if(type(a.first)!=type(b.first)){
        return type(a.first)<type(b.first);
    }
    for(int i=0;i<5;i++){
        if(ranking(a.first[i])!=ranking(b.first[i])){
            return ranking(a.first[i])<ranking(b.first[i]);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    pair<string,int> hands[1000];
    for(int i=0;i<1000;i++){
        cin >> hands[i].first >> hands[i].second;
        //dbg(hands[i]);
    }
    sort(hands,hands+1000,compare);
    long long ans=0;
    for(int i=0;i<1000;i++){
        dbg(hands[i]);
        ans+=(i+1)*hands[i].second;
    }
    cout << ans << "\n";
}
