#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct PaymentKey{
    string upiId;
    string accountNo;
    string ifscCode;
    string txnId;

    bool operator==(const PaymentKey& other) const{
        return upiId==other.upiId &&
               accountNo==other.accountNo &&
               ifscCode==other.ifscCode &&
               txnId==other.txnId;
    }
};

struct CustomerData{
    string customerName;
    string status;
};

class PaymentHashMap{
private:

    struct Node{
        PaymentKey key;
        CustomerData value;
        Node* next;

        Node(PaymentKey k,CustomerData v){
            key=k;
            value=v;
            next=nullptr;
        }
    };

    vector<Node*> buckets;

    int capacity;
    int currentSize;

    unsigned long long hashString(const string& s){

        unsigned long long hash=0;

        for(char ch:s)
            hash=hash*131+ch;

        return hash;
    }

    int hashFunction(const PaymentKey& key){

        unsigned long long hash=17;

        hash=31*hash+hashString(key.upiId);
        hash=31*hash+hashString(key.accountNo);
        hash=31*hash+hashString(key.ifscCode);
        hash=31*hash+hashString(key.txnId);

        return hash%capacity;
    }

    double loadFactor(){
        return (double)currentSize/capacity;
    }

    void rehash(){

        vector<Node*> oldBuckets=buckets;
        int oldCapacity=capacity;

        capacity*=2;

        buckets.clear();
        buckets.resize(capacity,nullptr);

        currentSize=0;

        for(int i=0;i<oldCapacity;i++){

            Node* curr=oldBuckets[i];

            while(curr){

                put(curr->key,curr->value);

                Node* temp=curr;
                curr=curr->next;

                delete temp;
            }
        }
    }

public:

    PaymentHashMap(){
        capacity=16;
        currentSize=0;
        buckets.resize(capacity,nullptr);
    }

    ~PaymentHashMap(){
        clear();
    }

    void put(const PaymentKey& key,const CustomerData& value){

        int idx=hashFunction(key);

        Node* curr=buckets[idx];

        while(curr){

            if(curr->key==key){
                curr->value=value;
                return;
            }

            curr=curr->next;
        }

        Node* newNode=new Node(key,value);

        newNode->next=buckets[idx];
        buckets[idx]=newNode;

        currentSize++;

        if(loadFactor()>0.75)
            rehash();
    }

    CustomerData* get(const PaymentKey& key){

        int idx=hashFunction(key);

        Node* curr=buckets[idx];

        while(curr){

            if(curr->key==key)
                return &(curr->value);

            curr=curr->next;
        }

        return nullptr;
    }

    bool containsKey(const PaymentKey& key){

        return get(key)!=nullptr;
    }

    bool remove(const PaymentKey& key){

        int idx=hashFunction(key);

        Node* curr=buckets[idx];
        Node* prev=nullptr;

        while(curr){

            if(curr->key==key){

                if(prev==nullptr)
                    buckets[idx]=curr->next;
                else
                    prev->next=curr->next;

                delete curr;

                currentSize--;

                return true;
            }

            prev=curr;
            curr=curr->next;
        }

        return false;
    }

    int size(){
        return currentSize;
    }

    bool isEmpty(){
        return currentSize==0;
    }

    void clear(){

        for(int i=0;i<capacity;i++){

            Node* curr=buckets[i];

            while(curr){

                Node* temp=curr;
                curr=curr->next;

                delete temp;
            }

            buckets[i]=nullptr;
        }

        currentSize=0;
    }

    int getCapacity(){
        return capacity;
    }
};

int main(){

    PaymentHashMap gateway;

    int choice;

    do{

        cout<<"\n===== Payment Gateway =====\n";
        cout<<"1. Add Transaction\n";
        cout<<"2. Search Transaction\n";
        cout<<"3. Remove Transaction\n";
        cout<<"4. Contains Transaction\n";
        cout<<"5. Size\n";
        cout<<"6. Capacity\n";
        cout<<"7. Exit\n";

        cin>>choice;

        switch(choice){

            case 1:{
                
                PaymentKey key;
                CustomerData data;

                cout<<"UPI ID : ";
                cin>>key.upiId;

                cout<<"Account Number : ";
                cin>>key.accountNo;

                cout<<"IFSC Code : ";
                cin>>key.ifscCode;

                cout<<"Transaction ID : ";
                cin>>key.txnId;

                cout<<"Customer Name : ";
                cin>>data.customerName;

                cout<<"Status : ";
                cin>>data.status;

                gateway.put(key,data);

                cout<<"Transaction Added\n";
                break;
            }

            case 2:{

                PaymentKey key;

                cout<<"UPI ID : ";
                cin>>key.upiId;

                cout<<"Account Number : ";
                cin>>key.accountNo;

                cout<<"IFSC Code : ";
                cin>>key.ifscCode;

                cout<<"Transaction ID : ";
                cin>>key.txnId;

                CustomerData* result=gateway.get(key);

                if(result){
                    cout<<"Customer : "
                        <<result->customerName
                        <<"\n";

                    cout<<"Status : "
                        <<result->status
                        <<"\n";
                }
                else{
                    cout<<"Transaction Not Found\n";
                }

                break;
            }

            case 3:{

                PaymentKey key;

                cout<<"UPI ID : ";
                cin>>key.upiId;

                cout<<"Account Number : ";
                cin>>key.accountNo;

                cout<<"IFSC Code : ";
                cin>>key.ifscCode;

                cout<<"Transaction ID : ";
                cin>>key.txnId;

                if(gateway.remove(key))
                    cout<<"Removed Successfully\n";
                else
                    cout<<"Transaction Not Found\n";

                break;
            }

            case 4:{

                PaymentKey key;

                cout<<"UPI ID : ";
                cin>>key.upiId;

                cout<<"Account Number : ";
                cin>>key.accountNo;

                cout<<"IFSC Code : ";
                cin>>key.ifscCode;

                cout<<"Transaction ID : ";
                cin>>key.txnId;

                cout<<(
                    gateway.containsKey(key)
                    ? "Exists"
                    : "Not Found"
                )<<"\n";

                break;
            }

            case 5:
                cout<<"Size = "
                    <<gateway.size()
                    <<"\n";
                break;

            case 6:
                cout<<"Capacity = "
                    <<gateway.getCapacity()
                    <<"\n";
                break;

            case 7:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid Choice\n";
        }

    }while(choice!=7);

    return 0;
}