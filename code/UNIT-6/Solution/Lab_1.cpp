#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyHashMap{
private:
    struct Node{
        string key;
        int value;
        Node* next;

        Node(string k,int v){
            key=k;
            value=v;
            next=nullptr;
        }
    };

    vector<Node*> table;
    int capacity;
    int sz;

    int hashFunction(string key){
        long long hash=0;

        for(char c:key)
            hash=(hash*31+c)%capacity;

        return hash;
    }

    double loadFactor(){
        return (double)sz/capacity;
    }

    void rehash(){
        vector<Node*> oldTable=table;
        int oldCapacity=capacity;

        capacity*=2;

        table.clear();
        table.resize(capacity,nullptr);

        sz=0;

        for(int i=0;i<oldCapacity;i++){
            Node* curr=oldTable[i];

            while(curr){
                put(curr->key,curr->value);
                curr=curr->next;
            }
        }
    }

public:
    MyHashMap(){
        capacity=16;
        sz=0;
        table.resize(capacity,nullptr);
    }

    void put(string key,int value){
        int idx=hashFunction(key);

        Node* curr=table[idx];

        while(curr){
            if(curr->key==key){
                curr->value=value;
                return;
            }
            curr=curr->next;
        }

        Node* newNode=new Node(key,value);
        newNode->next=table[idx];
        table[idx]=newNode;

        sz++;

        if(loadFactor()>0.75)
            rehash();
    }

    int get(string key){
        int idx=hashFunction(key);

        Node* curr=table[idx];

        while(curr){
            if(curr->key==key)
                return curr->value;

            curr=curr->next;
        }

        return -1;
    }

    void removeKey(string key){
        int idx=hashFunction(key);

        Node* curr=table[idx];
        Node* prev=nullptr;

        while(curr){
            if(curr->key==key){
                if(prev==nullptr)
                    table[idx]=curr->next;
                else
                    prev->next=curr->next;

                delete curr;
                sz--;
                return;
            }

            prev=curr;
            curr=curr->next;
        }
    }

    int size(){
        return sz;
    }

    int getCapacity(){
        return capacity;
    }
};

int main(){
    MyHashMap mp;

    string op;

    while(cin>>op){
        if(op=="PUT"){
            string key;
            int value;

            cin>>key>>value;
            mp.put(key,value);
        }

        else if(op=="GET"){
            string key;
            cin>>key;

            cout<<mp.get(key)<<'\n';
        }

        else if(op=="REMOVE"){
            string key;
            cin>>key;

            mp.removeKey(key);
        }
    }

    cout<<"Size: "<<mp.size()<<'\n';
    cout<<"Capacity: "<<mp.getCapacity()<<'\n';

    return 0;
}