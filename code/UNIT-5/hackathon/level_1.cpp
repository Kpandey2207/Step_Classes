#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> dq;
    vector<int> boarded;
    vector<int> quit;

    while (N--) {
        string op;
        cin >> op;

        if (op == "VIP") {
            int id;
            cin >> id;
            dq.push_front(id);
        }
        else if (op == "REGULAR") {
            int id;
            cin >> id;
            dq.push_back(id);
        }
        else if (op == "BOARD") {
            if (!dq.empty()) {
                boarded.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (op == "QUIT") {
            if (!dq.empty()) {
                quit.push_back(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << "Boarded: ";
    for (int id : boarded)
        cout << id << " ";
    cout << "\nQuit: ";
    for (int id : quit)
        cout << id << " ";
    cout << "\nWaiting: ";
    for (int id : dq)
        cout << id << " ";
    cout << "\n";
    return 0;
}