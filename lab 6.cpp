	#include <iostream>
	using namespace std;
	
	class businfo {
	    int busid;
	    string bustype;
	    int capacity;
	    int POS;
	
	public:
	    businfo() : busid(0), bustype(""), capacity(0), POS(0) {}
	
	    businfo(int busid, string bustype = "AC", int capacity = 90, int POS = 1500) 
	        : busid(busid), bustype(bustype), capacity(capacity), POS(POS) {}
	
	   
	    void display() const {
	        cout << "Bus Id: " << busid << endl
	             << "Bus Type: " << bustype << endl
	             << "Capacity: " << capacity << endl
	             << "Price of the seat: " << POS << endl;
	    }
	};
	
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
	
	    return 0;
	}

