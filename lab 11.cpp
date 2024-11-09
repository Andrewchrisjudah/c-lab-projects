#include <iostream>
#include <string>
#include <sstream> // Include for stringstream
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
    int getPrice() const { return POS; }

    // Function to convert int to string
    string intToString(int value) const {
        stringstream ss;
        ss << value;
        return ss.str();
    }

    // New subscript operator to return formatted bus info
    string operator[](const string& property) const {
        if (property == "id") {
            return "Bus ID: " + intToString(busid);
        } else if (property == "type") {
            return "Bus Type: " + bustype;
        } else if (property == "capacity") {
            return "Capacity: " + intToString(capacity);
        } else if (property == "price") {
            return "Price: " + intToString(POS);
        } else {
            return "Invalid property";
        }
    }

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
    cout << "Bus Id: " << bus.getBusId() << endl;
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

    cout << "subscript operator:" << endl;
    for (int i = 0; i < numBuses; ++i) {
        cout << buses[i]["id"] << endl;
        cout << buses[i]["type"] << endl;
        cout << buses[i]["capacity"] << endl;
        cout << buses[i]["price"] << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

