#include <iostream>
#include <string>
using namespace std;

class BusInfo {
    int busid;
    string bustype;
    int capacity;
    int POS;

public:
    BusInfo() : busid(0), bustype(""), capacity(0), POS(0) {}
    
    BusInfo(int busid, string bustype = "AC", int capacity = 90, int POS = 1500) 
        : busid(busid), bustype(bustype), capacity(capacity), POS(POS) {}

    void display() const {
        cout << "Bus Id: " << busid << endl
             << "Bus Type: " << bustype << endl
             << "Capacity: " << capacity << endl
             << "Price of the seat: " << POS << endl;
    }

    void modifyCapacity(int newCapacity) {
        capacity = newCapacity;
    }

    int getBusId() const { return busid; }
    string getBusType() const { return bustype; }
    int getCapacity() const { return capacity; }
    int& getPrice() { return POS; }

    BusInfo& operator++() {
        ++capacity;
        return *this;
    }

    BusInfo operator++(int) {
        BusInfo temp = *this;
        ++capacity;
        return temp;
    }

    BusInfo operator-() const {
        return BusInfo(busid, bustype, -capacity, POS);
    }

    BusInfo operator+(const BusInfo& other) const {
        return BusInfo(busid, bustype, capacity + other.capacity, POS);
    }

    friend void printBusId(const BusInfo& bus);
};

void printBusId(const BusInfo& bus) {
    cout << "Bus Id: " << bus.busid << endl;
}

BusInfo& findBusById(BusInfo buses[], int numBuses, int busId) {
    for (int i = 0; i < numBuses; ++i) {
        if (buses[i].getBusId() == busId) {
            return buses[i];
        }
    }
    return buses[0]; 
}

void changeBusType(BusInfo& bus, string newType) {
    bus = BusInfo(bus.getBusId(), newType, bus.getCapacity(), bus.getPrice());
}

void changeBusCapacity(BusInfo& bus, int newCapacity) {
    bus.modifyCapacity(newCapacity);
}

int main() {
    const int numBuses = 3;
    BusInfo buses[numBuses];

    for (int i = 0; i < numBuses; ++i) {
        int busid;
        string bustype;
        int capacity, price;

        cout << "Enter details for Bus " << i + 1 << ":" << endl;
        cout << "Bus ID: ";
        cin >> busid;
        cout << "Bus Type (e.g., AC, Non-AC): ";
        cin >> bustype;
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Price of the seat: ";
        cin >> price;

        buses[i] = BusInfo(busid, bustype, capacity, price);
        cout << endl;
    }

    for (int i = 0; i < numBuses; ++i) {
        cout << "Bus " << i + 1 << " details:" << endl;
        buses[i].display();
        cout << endl;
    }

    cout << "Incrementing capacity of Bus 1 using pre-increment:" << endl;
    ++buses[0];
    buses[0].display();
    cout << endl;

    cout << "Incrementing capacity of Bus 2 using post-increment:" << endl;
    buses[1]++;
    buses[1].display();
    cout << endl;

    cout << "Using unary negation on Bus 3 capacity:" << endl;
    BusInfo negBus = -buses[2];
    negBus.display();
    cout << endl;

    cout << "Adding capacities of Bus 1 and Bus 2:" << endl;
    BusInfo combinedBus = buses[0] + buses[1];
    combinedBus.display();

    cout << "Finding and changing Bus type:" << endl;
    BusInfo& busRef = findBusById(buses, numBuses, 10);
    changeBusType(busRef, "Deluxe");
    busRef.display();

    cout << endl;
    printBusId(buses[0]);

    return 0;
}

