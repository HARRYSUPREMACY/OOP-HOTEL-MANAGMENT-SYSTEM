#include <iostream>

#include <fstream>

#include <string>

using namespace std;

class Log {

private:
    string username;

    string password;

    string email;

public:
    void setUsername(string un) {
        username = un;
    }

    string getUsername() {
        return username;
    }

    void setPassword(string p) {
        password = p;
    }

    string getPassword() {
        return password;
    }

    void setEmail(string em) {
        email = em;
    }

    string getEmail() {
        return email;
    }

    bool validation() {
        cout << "    				       <<-------WELCOME TO AIR HOTEL------->>             " << endl;

        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "\n\n\n-----------------------------------------------------LOGIN FORM------------------------------------------------------\n\n\n" << endl;

        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

        cout << "\n";

        cout << "			ENTER YOUR NAME: ";

        cin >> username;
        
        cout<<endl;

        cout << "			ENTER PASSWORD: ";

        cin >> password;
		
		cout<<endl;

        cout << "			ENTER EMAIL: ";

        cin >> email;
        
		cout<<endl;

        string storedUsername, storedPassword, storedEmail;

        ifstream read("login.txt");

        if (read.is_open()) {
            while (read >> storedUsername >> storedPassword >> storedEmail) {
                if (username == storedUsername && password == storedPassword && email == storedEmail) {
                    read.close();
                    return true;
                }
            }
            read.close();
        } else {
            cout << "Unable to open file." << endl;
            return false;
        }

        return false;
    }

    void registerUser() {
        cout << "-------------REGISTER YOUR ACCOUNT---------------" << endl;

        cout << "*		ENTER YOUR NAME: 	";

        cin >> username;

        cout<<endl;

        cout << "*		ENTER PASSWORD: 	";

        cin >> password;

		cout<<endl;
	
        cout << "*		ENTER EMAIL: 	";

        cin >> email;

		cout<<endl;

        ofstream write("login.txt", ios::app);

        if (write.is_open()) {
            write << username << endl;

            write << password << endl;

            write << email << endl;

            write.close();

            cout << "\nRegistration successful!" << endl;
        } else {
            cout << "\nUnable to open file for writing." << endl;
        }
    }
};

class HotelInfo {

private:
    int totalRooms;

    int totalBeds;

    int totalSuites;

public:
    HotelInfo() {
        totalRooms = 100;

        totalBeds = 200;

        totalSuites = 50;
    }

    void setTotalRooms(int tr) {
        totalRooms = tr;
    }

    int getTotalRooms() const {
        return totalRooms;
    }

    void setTotalBeds(int tb) {
        totalBeds = tb;
    }

    int getTotalBeds() {
        return totalBeds;
    }

    void setTotalSuites(int ts) {
        totalSuites = ts;
    }

    int getTotalSuites() const {
        return totalSuites;
    }

    void saveDataToFile() {
        ofstream file("hotel_info.txt");

        if (file.is_open()) {
            file << totalRooms << endl;

            file << totalBeds << endl;

            file << totalSuites << endl;

            file.close();

            cout << "\nHotel info saved to file successfully." << endl;
        } else {
            cout << "\nUnable to open file." << endl;
        }
    }

    void readDataFromFile() {
        ifstream file("hotel_info.txt");

        if (file.is_open()) {
            file >> totalRooms;

            file >> totalBeds;

            file >> totalSuites;

            file.close();
        } else {
            cout << "\nUnable to open file." << endl;
        }
    }

    void updateBookings(int roomType) {
        switch (roomType) {
        case 1:
            totalRooms--;

            totalBeds -= 3;

            break;
            
        case 2:
            totalSuites--;

            break;
            
        case 3:
            totalRooms--;

            totalBeds -= 1;

            break;
            
        case 4:
            totalRooms--;

            totalBeds -= 2;

            break;
            
        default:
            cout << "Invalid room type." << endl;
        }

        saveDataToFile();
    }
};

class Booking {

private:
    int roomType;

    double paymentAmount;

    string email;

    int phoneNumber;

public:
    Booking() : roomType(0), paymentAmount(0.0), email(""), phoneNumber(0) {}

    void displayOptions() {
        cout << "            *   ________________________________________________________	*" << endl;

        cout << "            *   |   <<-------ONLINE BOOKING SYSTEM------->>            |	*" << endl;

        cout << "            *   |                -----SELECT ROOM TYPE-----            |	*" << endl;

        cout << "            *   |                                                      |	*" << endl;

        cout << "            *   |           1. TRIPLE BED - $300                       |	*" << endl;

        cout << "            *   |           2. DOUBLE BED - $200                       |	*" << endl;

        cout << "            *   |           3. SINGLE SUITE - $250                     |	*" << endl;

        cout << "            *   |           4. SINGLE BED - $150                       |	*" << endl;

        cout << "            *   |                                                      |	*" << endl;

        cout << "            *     -------------------------------------------------------	*" << endl;
    }

    void setRoomType(int rt) {
        roomType = rt;

        switch (roomType) {
        case 1:
            paymentAmount = 300;

            break;
        case 2:
            paymentAmount = 200;

            break;
        case 3:
            paymentAmount = 250;

            break;
        case 4:
            paymentAmount = 150;

            break;
        default:
            cout << "\nInvalid room type selected." << endl;

            paymentAmount = 0;
        }
    }

    int getRoomType() {
        cout << "\nENTER YOUR ROOM TYPE CHOICE: ";

        cin >> roomType;
		
		cout<<endl;

        setRoomType(roomType);

        return roomType;
    }

    void setEmail(string em) {
        email = em;
    }

    string getEmail() {
        cout << "ENTER YOUR EMAIL: ";

        cin >> email;
		
		cout<<endl;
		
        return email;
    }

    void setPhoneNumber(int pn) {
        phoneNumber = pn;
    }

    int getPhoneNumber() {
        cout << "ENTER YOUR PHONE NUMBER: ";

        cin >> phoneNumber;
		
		cout<<endl;
		
        return phoneNumber;
    }

    void makePayment() {
        cout << "	YOUR TOTAL PAYMENT AMOUNT IS: $" << paymentAmount << endl;

        cout << "	PAYMENT SUCCESSFUL. THANK YOU!" << endl;
    }

    void saveDataToFile() {
        ofstream file("booking_data.txt", ios::app);

        if (file.is_open()) {
            file << "Room Type: " << roomType << endl;

            file << "Email: " << email << endl;

            file << "Phone Number: " << phoneNumber << endl;

            file << "Payment Amount: $" << paymentAmount << endl;

            file.close();

            cout << "\nBooking data saved to file successfully." << endl;
        } else {
            cout << "\nUnable to open file." << endl;
        }
    }

    void readDataFromFile() {
        ifstream file("booking_data.txt");

        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

class Reception {

private:
    int choice;

    double paymentAmount;

    string email;

    int phoneNumber;

public:
    void display() {
        cout << "            ________________________________________________________" << endl;

        cout << "            |       <<-------WELCOME TO AAH HOTEL------->>         |" << endl;

        cout << "            |        -----HOW MAY I HELP YOU. SIR!!-----           |" << endl;

        cout << "            |                                                      |" << endl;

        cout << "            |   I WANT A ROOM. CAN YOU HELP ME WITH THIS....       |" << endl;

        cout << "            |                                                      |" << endl;

        cout << "            |   SURE SIR!!! WHAT KIND OF ROOM DO YOU WANT.!        |" << endl;

        cout << "            |       WE HAVE MULTIPLE TYPES OF CHOICES.             |" << endl;

        cout << "            |   1. TRIPLE BED - $300          2. DOUBLE BED - $200 |" << endl;

        cout << "            |   3. SINGLE SUITE - $250        4. SINGLE BED - $150 |" << endl;

        cout << "            --------------------------------------------------------" << endl;
    }

    void setChoice(int c) {
        choice = c;

        switch (choice) {
        case 1:
            paymentAmount = 300;

            break;
        case 2:
            paymentAmount = 200;

            break;
        case 3:
            paymentAmount = 250;

            break;
        case 4:
            paymentAmount = 150;

            break;
        default:
            cout << "Invalid choice!" << endl;

            paymentAmount = 0;
        }
    }

    int getChoice() {
        cout << "        ENTER YOUR CHOICE: ";

        cin >> choice;

        setChoice(choice);

        return choice;
    }

    void setEmail(const string& em) {
        email = em;
    }

    string getEmail() {
        cout << "        PLEASE!! CAN YOU ENTER YOUR EMAIL: ";

        cin >> email;

        return email;
    }

    void setPhoneNumber(int pn) {
        phoneNumber = pn;
    }

    int getPhoneNumber() {
        cout << "    CAN I HAVE YOUR PHONE NUMBER: ";

        cin >> phoneNumber;

        cout << "    HERE ARE THE KEYS FOR YOUR ROOM.. SIR!! ENJOY YOUR VACATIONS..." << endl;

        cout << "    THANKS..." << endl;

        return phoneNumber;
    }

    void makePayment() {
        cout << "    YOUR TOTAL PAYMENT AMOUNT IS: $" << paymentAmount << endl;

        cout << "    PAYMENT SUCCESSFUL. THANK YOU!" << endl;
    }

    void saveDataToFile() {
        ofstream file("reception_data.txt", ios::app);

        if (file.is_open()) {
            file << choice << endl;

            file << email << endl;

            file << phoneNumber << endl;

            file << "    Payment Amount: $" << paymentAmount << endl;

            file.close();

            cout << "    Data saved to file successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void readDataFromFile() {
        ifstream file("reception_data.txt");

        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

class Manager {
public:
    void viewAllCustomers() {
        ifstream file("login.txt");

        string username, password, email;

        if (file.is_open()) {
            while (file >> username >> password >> email) {
                cout << "Username: " << username << ", Password: " << password << ", Email: " << email << endl;
            }
            file.close();
        } else {
            cout << "Unable to open customer file." << endl;
        }
    }

    void viewHotelInfo() {
        ifstream file("hotel_info.txt");

        int totalRooms, totalBeds, totalSuites;

        if (file.is_open()) {
            file >> totalRooms;

            file >> totalBeds;

            file >> totalSuites;

            cout << "Remaining Total Rooms: " << totalRooms << endl;

            cout << "Remaining Total Beds: " << totalBeds << endl;

            cout << "Remaining Total Suites: " << totalSuites << endl;

            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

class Receptionist {
public:
    void viewCustomerInfo(const string& username, const string& password) {
        ifstream file("login.txt");

        string uname, pass, email;

        bool found = false;

        if (file.is_open()) {
            while (file >> uname >> pass >> email) {
                if (uname == username && pass == password) {
                    cout << "Username: " << uname << ", Password: " << pass << ", Email: " << email << endl;

                    found = true;

                    break;
                }
            }
            file.close();
        }

        if (!found)

            cout << "Customer not found." << endl;
    }
};
class Service {
private:
    string serviceName;
    double serviceCost;
    string email;
    int phoneNumber;
public:
    Service() {
	serviceName=("");
	serviceCost=(0.0);
	 email=("");
	phoneNumber=0 ;
	
	}
    
    void displayServiceOptions() {
        cout << "                --------------------------------------------------------" << endl;
        cout << "                |           <<-------SERVICE OPTIONS------->>          |" << endl;
        cout << "                |                -----SELECT SERVICE-----              |" << endl;
        cout << "                |                                                      |" << endl;
        cout << "                |            1. Dinner       - $50                     |" << endl;
        cout << "                |            2. Lunch        - $40                     |" << endl;
        cout << "                |            3. Breakfast    - $30                     |" << endl;
        cout << "                |            4. Room Service - $20                     |" << endl;
        cout << "                |            5. Cleaning     - $15                     |" << endl;
        cout << "                |                                                      |" << endl;
        cout << "                 -------------------------------------------------------" << endl;
    }
    
    void setServiceType(int st) {
        switch (st) {
        case 1:
            serviceName = "Dinner";
            serviceCost = 50.0;
            break;
        case 2:
            serviceName = "Lunch";
            serviceCost = 40.0;
            break;
        case 3:
            serviceName = "Breakfast";
            serviceCost = 30.0;
            break;
        case 4:
            serviceName = "Room Service";
            serviceCost = 20.0;
            break;
        case 5:
            serviceName = "Cleaning";
            serviceCost = 15.0;
            break;
        default:
            cout << "Invalid service type selected." << endl;
            serviceName = "";
            serviceCost = 0;
        }
    }
    
    void selectService() {
        int serviceType;
        cout << "ENTER YOUR SERVICE CHOICE: ";
        cin >> serviceType;
        setServiceType(serviceType);
    }
    
   
    
    void makePayment() {
        cout << "    YOUR TOTAL PAYMENT AMOUNT FOR " << serviceName << " IS: $" << serviceCost << endl;
        cout << "    PAYMENT SUCCESSFUL. THANK YOU!" << endl;
    }
    
    void saveDataToFile() {
        ofstream file("service_data.txt", ios::app);
        if (file.is_open()) {
            file << "Service: " << serviceName << endl;
            file << "Service Cost: $" << serviceCost << endl;
            file.close();
            cout << "    Service data saved to file successfully." << endl;
        } else {
            cout << "Unable to open file." << endl;
        }
    }
    
    void readDataFromFile() {
        ifstream file("service_data.txt");
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};


int main() {
    cout << "\n\n\n\t\t\t\t * --------------------------------------------- *";

    cout << "\n\t\t\t\t * ********************************************* * ";

    cout << "\n\t\t\t\t *                                               *";

    cout << "\n\t\t\t\t *                WELCOME TO                     *";

    cout << "\n\t\t\t\t *                                               *";

    cout << "\n\t\t\t\t *        AAH HOTEL MANAGEMENT SYSTEM            *";

    cout << "\n\t\t\t\t *                                               *";

    cout << "\n\t\t\t\t * ********************************************* *";

    cout << "\n\t\t\t\t * --------------------------------------------- *";

    cout << "\n";

    int choice;

    string managerEmail = "administrator@gmail.com";

    string managerPassword = "12345";

    string receptionistEmail = "reception@gmail.com";

    string receptionistPassword = "0123";

    cout << "Are you a Manager or a Receptionist?" << endl;

    cout << "1. Manager" << endl;

    cout << "2. Receptionist" << endl;

    cout << "3. Customer" << endl;

    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 1) {
        string email, password;

        cout << "Enter Manager's email: ";

        cin >> email;

        cout << "Enter Manager's password: ";

        cin >> password;

        if (email == managerEmail && password == managerPassword) {
            Manager manager;

            int option;

            cout << "1. View all customers" << endl;

            cout << "2. View hotel info" << endl;

            cout << "Choose your option: ";

            cin >> option;

            switch (option) {
            case 1:
                manager.viewAllCustomers();

                break;
            case 2:
                manager.viewHotelInfo();

                break;
            default:
                cout << "Invalid option." << endl;
            }
        } else {
            cout << "Incorrect email or password for Manager." << endl;
        }
    } else if (choice == 2) {
        string email, password;

        cout << "Enter Receptionist's email: ";

        cin >> email;

        cout << "Enter Receptionist's password: ";

        cin >> password;

        if (email == receptionistEmail && password == receptionistPassword) {
            Receptionist receptionist;

            string username, pass;

            cout << "Enter customer's username: ";

            cin >> username;

            cout << "Enter customer's password: ";

            cin >> pass;

            receptionist.viewCustomerInfo(username, pass);
        } else {
            cout << "Incorrect email or password for Receptionist." << endl;
        }
    } else if (choice == 3) {
        int option;

        cout << "1. Online Booking" << endl;

        cout << "2. Reception Booking" << endl;

        cout << "-- Register --" << endl;

        cout << "Choose your option: ";

        cin >> option;

        int totalBookings = 0;

        int totalRoomsBooked = 0;

        int totalBedsBooked = 0;

        int totalSuitesBooked = 0;

        if (option == 0) {
            Log login;

            login.registerUser();

            cout << "Now, choose your booking method." << endl;

            cout << "1. Online Booking" << endl;

            cout << "2. Reception Booking" << endl;

            cout << "Choose your option: ";

            cin >> option;
        }

        HotelInfo hotel;

        hotel.readDataFromFile();

        if (option == 1) {
            Log login;

            if (login.validation()) {
                cout << "Login successful!" << endl;

                Booking booking;

                booking.displayOptions();

                int roomType = booking.getRoomType();

                booking.getEmail();

                booking.getPhoneNumber();

                booking.makePayment();

                booking.saveDataToFile();

                booking.readDataFromFile();

                totalBookings++;

                totalRoomsBooked++;

                hotel.updateBookings(roomType);

                switch (roomType) {
                case 1:
                    totalBedsBooked += 3;

                    break;
                case 2:
                    totalSuitesBooked += 1;

                    break;
                case 3:
                    totalBedsBooked += 1;

                    break;
                case 4:
                    totalBedsBooked += 2;

                    break;
                }
            } else {
                cout << "Incorrect username, password, or email." << endl;
            }
        } else if (option == 2) {
            Reception reception;

            reception.display();

            int choice = reception.getChoice();

            reception.getEmail();

            reception.getPhoneNumber();

            reception.makePayment();

            reception.saveDataToFile();

            reception.readDataFromFile();

            totalBookings++;

            totalRoomsBooked++;

            hotel.updateBookings(choice);

            switch (choice) {
            case 1:
                totalBedsBooked += 3;

                break;
            case 2:
                totalSuitesBooked += 1;

                break;
            case 3:
                totalBedsBooked += 1;

                break;

            case 4:

                totalBedsBooked += 2;

                break;
            }
        } else {
            cout << "Invalid option selected." << endl;
        }

    cout << "Would you like to book any additional services?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int serviceChoice;
    cin >> serviceChoice;

    if (serviceChoice == 1) {
        Service service;
        service.displayServiceOptions();
        service.selectService();
        service.makePayment();
        service.saveDataToFile();
    }
 
	else if(serviceChoice == 2)
	{
		cout<<"THANKYOU SIR , ENJOY YOUR VACATIONS!!!. ";
	}
}
 else {
    cout << "Invalid choice." << endl;
}

    return 0;
}

