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

//using shift = pair<long long,pair<long long,long long>>; //first is shift amount, second is source range (inclusive)
using range = pair<long,long>;
using shift = pair<range,long long>; //second is shift amount, first is source range (inclusive)
vector<shift> shifts[7];
int maplengths[] = {12,29,17,18,34,35,12};

//long long location(long long position, int index){ //index is the map i haven't been through yet
//    if(index==7){
//        return position;
//    }
//    for(int i=0;i<maplengths[index];i++){
//        if(maps[index][i].second.first<=position&&position<=maps[index][i].second.second){
//            return location(position+maps[index][i].first,index+1);
//        }
//    }
//    return location(position,index+1);
//}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    //
    range seeds[10]; //end and begin
    string in;
    cin >> in;
    for(int i=0;i<10;i++){
        cin >> seeds[i].first >> seeds[i].second;
        seeds[i].second=seeds[i].first+seeds[i].second-1;
    }
    
    for(int map=0;map<7;map++){
        cin >> in >> in;
        dbg(in);
        vector<shift> veccy = vector<shift>(maplengths[map],make_pair(make_pair(-2,-3),-1)); 
        for(int i=0;i<maplengths[map];i++){
            long long destbegin, sourcebegin, length;
            cin >> destbegin >> sourcebegin >> length;
            veccy[i].second=destbegin-sourcebegin;
            veccy[i].first.first=sourcebegin;
            veccy[i].first.second=sourcebegin+length-1;
        }
        sort(all(veccy));
        //veccy.push_back(make_pair(make_pair(0,LLONG_MAX),0));
        shifts[map]=veccy;
    }


    //keep ranges with offset, then find range with min(begin)
    
    set<range> ranges[8];
    for(int i=0;i<10;i++){
        ranges[0].insert(seeds[i]);
        dbg(seeds[i]);
    }

    for(int i=0;i<7;i++){
        //combine ranges in set
        dbg(ranges[i].size());
        
        int index=0;
        vector<shift> shiftz=shifts[i];
        for(auto j : ranges[i]){
            cout << "now on range " << j << " with index "<<index<<"\n";
            
            if(index>=maplengths[i]||shiftz[index].first.first>j.second){
                if(index>=maplengths[i]){
                    dbg(shiftz[index]);
                }else{
                    dbg(index);
                }
                ranges[i+1].insert(j);
                continue;
            }

            while(index<maplengths[i]&&shiftz[index].first.second<j.second){
                if(shiftz[index].first.second<j.first){
                    index++;
                    continue;
                }
                dbg(j);
                dbg(shiftz[index]);
                if(shiftz[index].first.first>j.first){
                    ranges[i+1].insert(make_pair(j.first,shiftz[index].first.first-1));
                    j.first=shiftz[index].first.first;
                    cout << "werent up to there so now j is "<<j<<"\n";
                }

                ranges[i+1].insert({j.first+shiftz[index].second,shiftz[index].first.second+shiftz[index].second});
                //dbg(make_pair("first",j));
                j.first=shiftz[index].first.second+1;
                //dbg(make_pair("second",j));
                index++;
            }
            if(index>=maplengths[i]||shiftz[index].first.first>j.second){
                ranges[i+1].insert(j);
                continue;
            }
            ranges[i+1].insert(make_pair(j.first+shiftz[index].second,j.second+shiftz[index].second));
            //cout << j << " fits in "<<shiftz[index]<<"\n";
        }
        for(auto j : ranges[i+1]){
            dbg(j);
        }
    }
    dbg(ranges[7].size());
    dbg(ranges[7].begin()->first);




    




}
