#include <bits/stdc++.h>
using namespace std;

class Bank {
    
    int userId[1000];
    int balance[1000];
    int totalUsers;

public:

    Bank() {
        totalUsers = 0;
    }
    int findUser(int X) {
        for(int i = 0; i < totalUsers; i++) {
            if(userId[i] == X)
                return i;
        }
        return -1;
    }

    bool create(int X, int Y) {

        int idx = findUser(X);

        if(idx == -1) {
            userId[totalUsers] = X;
            balance[totalUsers] = Y;
            totalUsers++;
            return true;
        }

        balance[idx] += Y;
        return false;
    }

    bool debit(int X, int Y) {

        int idx = findUser(X);

        if(idx == -1 || balance[idx] < Y)
            return false;

        balance[idx] -= Y;
        return true;
    }
    bool credit(int X, int Y) {

        int idx = findUser(X);

        if(idx == -1)
            return false;

        balance[idx] += Y;
        return true;
    }

    int getBalance(int X) {

        int idx = findUser(X);

        if(idx == -1)
            return -1;

        return balance[idx];
    }
};

int main() {

    Bank b;
    cout << b.create(1, 100) << endl;   // 1
    cout << b.create(1, 50) << endl;    // 0
    cout << b.debit(1, 30) << endl;     // 1
    cout << b.credit(1, 20) << endl;    // 1
    cout << b.getBalance(1) << endl;    // 140

    return 0;
}