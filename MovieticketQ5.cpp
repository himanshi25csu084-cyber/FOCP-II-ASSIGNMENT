#include <bits/stdc++.h>
using namespace std;

class MovieBookingSystem {
    vector<int> movies[1000];
public:
    bool BOOK(int customerID, int movieID) {
      
        for(int x : movies[movieID]) {
            if(x == customerID)
                return false;
        }
        
        if(movies[movieID].size() >= 100)
            return false;

        movies[movieID].push_back(customerID);
        return true;
    }
    bool CANCEL(int customerID, int movieID) {
        for(int i = 0; i < movies[movieID].size(); i++) {

            if(movies[movieID][i] == customerID) {

                movies[movieID].erase(movies[movieID].begin() + i);
                return true;
            }
        }
        return false;
    }
 bool IS_BOOKED(int customerID, int movieID) {

        for(int x : movies[movieID]) {

            if(x == customerID)
                return true;
        }
        return false;
    }

    int AVAILABLE_TICKETS(int movieID) {

        return 100 - movies[movieID].size();
    }
};

int main() {

    MovieBookingSystem system;
    int Q;
    cin >> Q;
    while(Q--) {

        string operation;
        cin >> operation;

        if(operation == "BOOK") {

            int X, Y;
            cin >> X >> Y;

            if(system.BOOK(X, Y))
                cout << "Booked Successfully!" << endl;
            else
                cout << "Booking Failed!" << endl;
        }

        else if(operation == "CANCEL") {

            int X, Y;
            cin >> X >> Y;

            if(system.CANCEL(X, Y))
                cout << "Canceled Successfully!" << endl;
            else
                cout << "Couldn't cancel!" << endl;
        }

        else if(operation == "IS_BOOKED") {

            int X, Y;
            cin >> X >> Y;

            if(system.IS_BOOKED(X, Y))
                cout << "Ticket is Booked!" << endl;
            else
                cout << "Ticket isn't booked!" << endl;
        }

        else if(operation == "AVAILABLE_TICKETS") {

            int Y;
            cin >> Y;

            cout << "Available ticket count is "
                 << system.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}
