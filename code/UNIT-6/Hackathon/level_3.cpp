#include<bits/stdc++.h>
using namespace std;

int main(){

    map<int,long long,greater<int>> buy;
    map<int,long long> sell;

    string op;

    while(cin>>op){

        if(op=="ADD"){

            string side;
            int price;
            long long volume;

            cin>>side>>price>>volume;

            if(side=="BUY")
                buy[price]+=volume;
            else
                sell[price]+=volume;
        }

        else if(op=="REMOVE"){

            string side;
            int price;
            long long volume;

            cin>>side>>price>>volume;

            if(side=="BUY"){

                if(buy.count(price)){

                    buy[price]-=volume;

                    if(buy[price]<=0)
                        buy.erase(price);
                }
            }
            else{

                if(sell.count(price)){

                    sell[price]-=volume;

                    if(sell[price]<=0)
                        sell.erase(price);
                }
            }
        }

        else if(op=="BESTBID"){

            if(buy.empty())
                cout<<"-1\n";
            else
                cout<<buy.begin()->first<<"\n";
        }

        else if(op=="BESTASK"){

            if(sell.empty())
                cout<<"-1\n";
            else
                cout<<sell.begin()->first<<"\n";
        }

        else if(op=="SPREAD"){

            if(buy.empty() || sell.empty())
                cout<<"-1\n";
            else
                cout<<sell.begin()->first-buy.begin()->first<<"\n";
        }

        else if(op=="DEPTH"){

            string side;
            int k;

            cin>>side>>k;

            bool printed=false;

            if(side=="BUY"){

                int count=0;

                for(auto &x:buy){

                    if(count==k)
                        break;

                    cout<<x.first<<":"<<x.second<<"\n";

                    printed=true;
                    count++;
                }
            }
            else{

                int count=0;

                for(auto &x:sell){

                    if(count==k)
                        break;

                    cout<<x.first<<":"<<x.second<<"\n";

                    printed=true;
                    count++;
                }
            }

            if(!printed)
                cout<<"EMPTY\n";
        }

        else if(op=="RANGE"){

            string side;
            int low,high;

            cin>>side>>low>>high;

            bool printed=false;

            if(side=="BUY"){

                for(auto &x:buy){

                    if(x.first>=low &&
                       x.first<=high){

                        cout<<x.first
                            <<":"
                            <<x.second
                            <<"\n";

                        printed=true;
                    }
                }
            }
            else{

                for(auto &x:sell){

                    if(x.first>=low &&
                       x.first<=high){

                        cout<<x.first
                            <<":"
                            <<x.second
                            <<"\n";

                        printed=true;
                    }
                }
            }

            if(!printed)
                cout<<"EMPTY\n";
        }
    }

    return 0;
}