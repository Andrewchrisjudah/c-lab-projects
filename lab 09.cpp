#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class businfo {
    int busid;
    string bustype;
    int capacity;
    int POS;

    static int totalBuses; 

public:
    businfo() : busid(0), bustype(""), capacity(0), POS(0) {
        totalBuses++;
    }

    businfo(int busid, const string &bustype = "AC", int capacity = 90, int POS = 1500) 
        : busid(busid), bustype(bustype), capacity(capacity), POS(POS) {
        totalBuses++;
    }

    businfo(int busid, int capacity) 
        : busid(busid), bustype("AC"), capacity(capacity), POS(1500) {
        totalBuses++;
    }

    void display() const {
        cout << "Bus Id: " << busid << endl
             << "Bus Type: " << bustype << endl
             << "Capacity: " << capacity << endl
             << "Price of the seat: " << POS << endl;
    }

    void modifyCapacity(int newCapacity) {
        capacity = newCapacity;
    }

    void modifyCapacity(const string &newCapacityStr) {
        stringstream ss(newCapacityStr);
        int newCapacity;
        ss >> newCapacity;
        capacity = newCapacity;
    }

    int getBusId() const { return busid; }
    string getBusType() const { return bustype; }
    int getCapacity() const { return capacity; }
    int& getPrice() { return POS; }

    
    static int getTotalBuses() {
        return totalBuses;
    }


    static float calculateAverageCapacity(businfo buses[], int count) {
        int totalCapacity = 0;
        for (int i = 0; i < count; ++i) {
            totalCapacity += buses[i].capacity;
        }
        return static_cast<float>(totalCapacity) / count;
    }
};


int businfo::totalBuses = 0;

void changeBusType(businfo bus, const string &newType) {
    bus = businfo(bus.getBusId(), newType, bus.getCapacity(), bus.getPrice());
    bus.display();
}

void changeBusCapacity(businfo &bus, int newCapacity) {
    bus.modifyCapacity(newCapacity);
}

int main() {
    int numBuses = 3;

    businfo buses[numBuses] = {
        businfo(10, "AC", 90, 1500),
        businfo(20, "Non-AC", 80, 1200),
        businfo(30, "AC", 100, 1800)
    };

    for (int i = 0; i < numBuses; ++i) {
        cout << "Bus " << i + 1 << " details:" << endl;
        buses[i].display();
        cout << endl;
    }

    cout << "Total number of buses created: " << businfo::getTotalBuses() << endl;

    cout << "Average capacity of buses: " 
         << businfo::calculateAverageCapacity(buses, numBuses) << endl;

    cout << "Changing Bus 1 type" << endl;
    changeBusType(buses[0], "Luxury");
    buses[0].display();
    cout << endl;

    cout << "Changing Bus 2 capacity (pass by reference):" << endl;
    changeBusCapacity(buses[1], 100);
    buses[1].display();
    cout << endl;

    cout << "Changing Bus 3 price directly:" << endl;
    int &priceRef = buses[2].getPrice();
    priceRef += 200;
    buses[2].display();
    cout << endl;

    businfo bus4(40, "Sleeper");
    bus4.display();
    cout << endl;

    businfo bus5(50, 120);
    bus5.display();
    cout << endl;

    cout << "Changing Bus 2 capacity using string:" << endl;
    buses[1].modifyCapacity("110");
    buses[1].display();

    return 0;
}

