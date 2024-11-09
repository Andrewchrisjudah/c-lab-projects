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

    ~BusInfo() {}

    void display() const {
        cout << "Bus Id: " << busid << endl
             << "Bus Type: " << bustype << endl
             << "Capacity: " << capacity << endl
             << "Price of the seat: " << POS << endl;
    }
0
    int getBusId() const { return busid; }
};

class LuxuryBus : public BusInfo {
    bool hasWifi;
    bool hasRecliningSeats;

public:
    LuxuryBus() : BusInfo(), hasWifi(false), hasRecliningSeats(false) {}

    LuxuryBus(int busid, string bustype, int capacity, int price, bool wifi, bool reclining)
        : BusInfo(busid, bustype, capacity, price), hasWifi(wifi), hasRecliningSeats(reclining) {}

    void display() const {
        BusInfo::display();
        cout << "Has WiFi: " << (hasWifi ? "Yes" : "No") << endl
             << "Has Reclining Seats: " << (hasRecliningSeats ? "Yes" : "No") << endl;
    }
};

class ExecutiveBus : public LuxuryBus {
    string additionalService;

public:
    ExecutiveBus() : LuxuryBus(), additionalService("") {}

    ExecutiveBus(int busid, string bustype, int capacity, int price, bool wifi, bool reclining, string service)
        : LuxuryBus(busid, bustype, capacity, price, wifi, reclining), additionalService(service) {}

    void display() const {
        LuxuryBus::display();
        cout << "Additional Service: " << additionalService << endl;
    }
};

int main() {
    int numBuses = 3;
    BusInfo* buses = new BusInfo[numBuses];
    LuxuryBus* luxuryBuses = new LuxuryBus[2];
    ExecutiveBus* executiveBuses = new ExecutiveBus[2];

    for (int i = 0; i < numBuses; ++i) {
        int busid, capacity, price;
        string bustype;

        cout << "Enter details for Bus " << i + 1 << ":" << endl;
        cout << "Bus ID: ";
        cin >> busid;
        cout << "Bus Type: ";
        cin >> bustype;
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Price of the seat: ";
        cin >> price;

        buses[i] = BusInfo(busid, bustype, capacity, price);
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        int busid, capacity, price;
        string bustype;
        bool wifi, reclining;

        cout << "Enter details for Luxury Bus " << i + 1 << ":" << endl;
        cout << "Bus ID: ";
        cin >> busid;
        cout << "Bus Type: ";
        cin >> bustype;
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Price of the seat: ";
        cin >> price;
        cout << "Has WiFi (1 for Yes, 0 for No): ";
        cin >> wifi;
        cout << "Has Reclining Seats (1 for Yes, 0 for No): ";
        cin >> reclining;

        luxuryBuses[i] = LuxuryBus(busid, bustype, capacity, price, wifi, reclining);
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        int busid, capacity, price;
        string bustype, service;
        bool wifi, reclining;

        cout << "Enter details for Executive Bus " << i + 1 << ":" << endl;
        cout << "Bus ID: ";
        cin >> busid;
        cout << "Bus Type: ";
        cin >> bustype;
        cout << "Capacity: ";
        cin >> capacity;
        cout << "Price of the seat: ";
        cin >> price;
        cout << "Has WiFi (1 for Yes, 0 for No): ";
        cin >> wifi;
        cout << "Has Reclining Seats (1 for Yes, 0 for No): ";
        cin >> reclining;
        cout << "Additional Service: ";
        cin >> service;

        executiveBuses[i] = ExecutiveBus(busid, bustype, capacity, price, wifi, reclining, service);
        cout << endl;
    }

    for (int i = 0; i < numBuses; ++i) {
        cout << "Bus " << i + 1 << " details:" << endl;
        buses[i].display();
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        cout << "Luxury Bus " << i + 1 << " details:" << endl;
        luxuryBuses[i].display();
        cout << endl;
    }

    for (int i = 0; i < 2; ++i) {
        cout << "Executive Bus " << i + 1 << " details:" << endl;
        executiveBuses[i].display();
        cout << endl;
    }

    delete[] buses;
    delete[] luxuryBuses;
    delete[] executiveBuses;

    return 0;
}

