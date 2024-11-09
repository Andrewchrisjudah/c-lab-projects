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

    virtual ~BusInfo() {} // Make destructor virtual

    virtual void display() const { // Make display virtual
        cout << "Bus Id: " << busid << endl
             << "Bus Type: " << bustype << endl
             << "Capacity: " << capacity << endl
             << "Price of the seat: " << POS << endl;
    }

    int getBusId() const { return busid; }
};

class LuxuryBus : public BusInfo {
    bool hasWifi;
    bool hasRecliningSeats;

public:
    LuxuryBus() : BusInfo(), hasWifi(false), hasRecliningSeats(false) {}

    LuxuryBus(int busid, string bustype, int capacity, int price, bool wifi, bool reclining)
        : BusInfo(busid, bustype, capacity, price), hasWifi(wifi), hasRecliningSeats(reclining) {}

    void display() const override { // Override display
        BusInfo::display();
        cout << "Has WiFi: " << (hasWifi ? "Yes" : "No") << endl
             << "Has Reclining Seats: " << (hasRecliningSeats ? "Yes" : "No") << endl;
    }
};

class FoodService {
    bool hasMealService;

public:
    FoodService() : hasMealService(false) {}
    FoodService(bool mealService) : hasMealService(mealService) {}

    void displayService() const {
        cout << "Has Meal Service: " << (hasMealService ? "Yes" : "No") << endl;
    }
};

class TravelBus : public LuxuryBus, public FoodService {
public:
    TravelBus() : LuxuryBus(), FoodService() {}

    TravelBus(int busid, string bustype, int capacity, int price, bool wifi, bool reclining, bool mealService)
        : LuxuryBus(busid, bustype, capacity, price, wifi, reclining), FoodService(mealService) {}

    void display() const override { // Override display
        LuxuryBus::display();
        FoodService::displayService();
    }
};

class ExecutiveBus : public LuxuryBus {
    string additionalService;

public:
    ExecutiveBus() : LuxuryBus(), additionalService("") {}

    ExecutiveBus(int busid, string bustype, int capacity, int price, bool wifi, bool reclining, string service)
        : LuxuryBus(busid, bustype, capacity, price, wifi, reclining), additionalService(service) {}

    void display() const override { // Override display
        LuxuryBus::display();
        cout << "Additional Service: " << additionalService << endl;
    }
};

int main() {
    int numBuses = 3;
    BusInfo** buses = new BusInfo*[numBuses];
    LuxuryBus* luxuryBuses = new LuxuryBus[2];
    ExecutiveBus* executiveBuses = new ExecutiveBus[2];
    TravelBus* travelBuses = new TravelBus[2];

    // Input and display logic for regular buses
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

        buses[i] = new BusInfo(busid, bustype, capacity, price);
        cout << endl;
    }

    // Input and display logic for luxury buses
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

    // Input and display logic for executive buses
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

    // Input and display logic for travel buses
    for (int i = 0; i < 2; ++i) {
        int busid, capacity, price;
        string bustype;
        bool wifi, reclining, mealService;

        cout << "Enter details for Travel Bus " << i + 1 << ":" << endl;
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
        cout << "Has Meal Service (1 for Yes, 0 for No): ";
        cin >> mealService;

        travelBuses[i] = TravelBus(busid, bustype, capacity, price, wifi, reclining, mealService);
        cout << endl;
    }

    // Display all bus details
    for (int i = 0; i < numBuses; ++i) {
        cout << "Bus " << i + 1 << " details:" << endl;
        buses[i]->display(); // Use base class pointer to call display
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

    for (int i = 0; i < 2; ++i) {
        cout << "Travel Bus " << i + 1 << " details:" << endl;
        travelBuses[i].display();
        cout << endl;
    }

    // Clean up memory
    for (int i = 0; i < numBuses; ++i) {
        delete buses[i]; // Free memory allocated for each BusInfo
    }
    delete[] buses;
    delete[] luxuryBuses;
    delete[] executiveBuses;
    delete[] travelBuses;

    return 0;
}

