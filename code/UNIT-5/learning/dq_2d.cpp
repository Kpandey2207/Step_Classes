#include <bits/stdc++.h>
using namespace std;

class MyDeque {
private:
    static const int BLOCK_SIZE = 4;

    vector<vector<int>> blocks;

    int frontBlock, frontPos;
    int backBlock, backPos;

    int sz;

    void grow() {
        int old = blocks.size();
        int neu = old * 2;

        vector<vector<int>> temp(neu, vector<int>(BLOCK_SIZE));

        int shift = (neu - old) / 2;

        for (int i = 0; i < old; i++)
            temp[i + shift] = move(blocks[i]);

        frontBlock += shift;
        backBlock += shift;

        blocks = move(temp);
    }

public:
    MyDeque() {
        blocks.resize(8, vector<int>(BLOCK_SIZE));

        frontBlock = backBlock = 4;
        frontPos = backPos = BLOCK_SIZE / 2;

        sz = 0;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    void push_back(int x) {
        if (backBlock == (int)blocks.size() - 1 &&
            backPos == BLOCK_SIZE)
            grow();

        if (backPos == BLOCK_SIZE) {
            backBlock++;
            backPos = 0;
        }

        blocks[backBlock][backPos++] = x;
        sz++;
    }

    void push_front(int x) {
        if (frontBlock == 0 &&
            frontPos == 0)
            grow();

        if (frontPos == 0) {
            frontBlock--;
            frontPos = BLOCK_SIZE;
        }

        blocks[frontBlock][--frontPos] = x;
        sz++;
    }

    void pop_back() {
        if (empty()) return;

        if (backPos == 0) {
            backBlock--;
            backPos = BLOCK_SIZE;
        }

        backPos--;
        sz--;
    }

    void pop_front() {
        if (empty()) return;

        frontPos++;

        if (frontPos == BLOCK_SIZE) {
            frontBlock++;
            frontPos = 0;
        }

        sz--;
    }

    int front() {
        return blocks[frontBlock][frontPos];
    }

    int back() {
        int b = backBlock;
        int p = backPos - 1;

        if (p < 0) {
            b--;
            p = BLOCK_SIZE - 1;
        }

        return blocks[b][p];
    }

    int operator[](int idx) {
        int absolute = frontPos + idx;

        int block = frontBlock + absolute / BLOCK_SIZE;
        int pos   = absolute % BLOCK_SIZE;

        return blocks[block][pos];
    }
};

int main() {
    MyDeque dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    for (int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";

    cout << "\n";

    cout << dq.front() << "\n";
    cout << dq.back() << "\n";
}