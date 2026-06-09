#include<bits/stdc++.h>
using namespace std;

struct RecipientInfo{
    string recipient;
    int timestamp;
};

int main(){

    unordered_map<string,int> duplicateMap;

    unordered_map<string,queue<int>> rateMap;

    unordered_map<string,queue<RecipientInfo>> muleQueue;
    unordered_map<string,unordered_map<string,int>> recipientFreq;

    unordered_map<string,queue<int>> structuringMap;

    int duplicateCount=0;
    int rateCount=0;
    int muleCount=0;
    int structuringCount=0;

    string txnId,userId,recipient;
    long long amount;
    int timestamp;

    while(cin>>txnId>>userId>>recipient>>amount>>timestamp){

        // DUPLICATE DETECTOR

        if(duplicateMap.count(txnId) &&
           timestamp-duplicateMap[txnId]<=5){

            cout<<"DUPLICATE "<<txnId<<"\n";
            duplicateCount++;
        }

        duplicateMap[txnId]=timestamp;

        // RATE LIMIT DETECTOR

        while(!rateMap[userId].empty() &&
              timestamp-rateMap[userId].front()>60){

            rateMap[userId].pop();
        }

        rateMap[userId].push(timestamp);

        if(rateMap[userId].size()>20){

            cout<<"RATE_LIMIT "<<txnId<<"\n";
            rateCount++;
        }

        // MONEY MULE DETECTOR

        while(!muleQueue[userId].empty() &&
              timestamp-muleQueue[userId].front().timestamp>3600){

            RecipientInfo old=muleQueue[userId].front();
            muleQueue[userId].pop();

            recipientFreq[userId][old.recipient]--;

            if(recipientFreq[userId][old.recipient]==0)
                recipientFreq[userId].erase(old.recipient);
        }

        muleQueue[userId].push({recipient,timestamp});
        recipientFreq[userId][recipient]++;

        if(recipientFreq[userId].size()>50){

            cout<<"MONEY_MULE "<<txnId<<"\n";
            muleCount++;
        }

        // STRUCTURING DETECTOR

        if(amount<50000){

            while(!structuringMap[userId].empty() &&
                  timestamp-structuringMap[userId].front()>1800){

                structuringMap[userId].pop();
            }

            structuringMap[userId].push(timestamp);

            if(structuringMap[userId].size()>=10){

                cout<<"STRUCTURING "<<txnId<<"\n";
                structuringCount++;
            }
        }
    }

    cout<<"Duplicate Alerts: "<<duplicateCount<<"\n";
    cout<<"Rate Limit Alerts: "<<rateCount<<"\n";
    cout<<"Money Mule Alerts: "<<muleCount<<"\n";
    cout<<"Structuring Alerts: "<<structuringCount<<"\n";

    return 0;
}