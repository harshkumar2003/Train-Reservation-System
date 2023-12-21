#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Account 
{
    private:
        string type;
        string username;
        string password;
    public:
        Account(const string& type, const string& username, const string& password)
            : type(type), username(username), password(password) {}


        const string& getType() const 
        {
            return type;
        }


        const string& getUsername() const
        {
            return username;
        }


        const string& getPassword() const 
        {
            return password;
        }
};

class Train 
{
    public:
        Train(const string& name, const string& number)
            : name(name), number(number) {}


        const string& getName() const 
        {
            return name;
        }


        const string& getNumber() const
        {
            return number;
        }


    private:
        string name;
        string number;
};
class Ticket 
{
    public:
        Ticket(const string& ClassType, const string& trainNumber, const string& from, const string& to,
            const string& sleeperPrice, const string& threeAPrice, const string& twoAPrice, const string& oneAPrice)
            : tickettype(ClassType), trainNumber(trainNumber), from(from), to(to),
            sleeperPrice(sleeperPrice), threeAPrice(threeAPrice),
            twoAPrice(twoAPrice), oneAPrice(oneAPrice) {}



        const string& getClassType() const
        {
            return tickettype;
        }
        const string& getTrainNumber() const 
        {
            return trainNumber;
        }


        const string& getSleeperPrice() const 
        {
            return sleeperPrice;
        }


        const string& getThreeAPrice() const
        {
            return threeAPrice;
        }


        const string& getTwoAPrice() const 
        {
            return twoAPrice;
        }


        const string& getOneAPrice() const 
        {
            return oneAPrice;
        }
        const string& getFrom() const 
        {
            return from;
        }
        const string& getTo() const 
        {
            return to;
        }


    private:
        string trainNumber;
        string tickettype;
        string sleeperPrice;
        string threeAPrice;
        string twoAPrice;
        string oneAPrice;
        string from;
        string to;
};


class Route 
{
    public:
        Route(const string& trainNumber, const string& from, const string& to)
            : trainNumber(trainNumber), from(from), to(to) {}


        const string& getTrainNumber() const
        {
            return trainNumber;
        }


        const string& getFrom() const 
        {
            return from;
        }


        const string& getTo() const 
        {
            return to;
        }


    private:
        string trainNumber;
        string from;
        string to;
};

// Function to create a new account
void createAccount(const string& userType) 
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;


    Account account(userType, username, password);


    ofstream file("login_details.txt", ios::app);
    if (file.is_open()) 
    {
        file << account.getType() << " " << account.getUsername() << " " << account.getPassword() << endl;
        cout << "Account created successfully." << endl;
    } 
    else 
    {
        cout << "Unable to open file." << endl;
    }
    file.close();
}


// Function to validate login credentials
bool validateLogin(const string& userType) 
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;


    ifstream file("login_details.txt");
    if (file.is_open()) 
    {
        string type, user, pass;
        while (file >> type >> user >> pass) 
        {
            if (type == userType && user == username && pass == password) 
            {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}


// Function to add a train
void addTrain() 
{
    string trainName, trainNumber;
    cout << "Enter train name: ";
    cin >> trainName;
    cout << "Enter train number: ";
    cin >> trainNumber;


    Train train(trainName, trainNumber);


    ofstream file("train_details.txt", ios::app);
    if (file.is_open()) 
    {
        file << train.getName() << " " << train.getNumber() << endl;
        cout << "Train added successfully." << endl;
    } 
    else 
    {
        cout << "Unable to open file." << endl;
    }
    file.close();
}


// Function to delete a train
void deleteTrain()
{
    string trainName, trainNumber;
    cout << "Enter train name: ";
    cin >> trainName;
    cout << "Enter train number: ";
    cin >> trainNumber;

    ifstream inputFile("train_details.txt");
    ofstream tempFile("temp.txt");
    if (inputFile.is_open() && tempFile.is_open())
    {
        string name, number;
        bool trainFound = false;

        while (inputFile >> name >> number)
        {
            if (!(name == trainName && number == trainNumber))
            {
                tempFile << name << " " << number << endl;
            }
            else
            {
                trainFound = true;
                cout << "Train  deleted successfully." << endl;
            }
        }
        inputFile.close();
        tempFile.close();

        remove("train_details.txt");
        rename("temp.txt", "train_details.txt");

        if (!trainFound)
        {
            cout << "Train  not found." << endl;
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
// Function to add ticket prices for a train
void addTicketPrices(const string& classtype)
{
    string trainNumber, from , to;
    string sleeperPrice, threeAPrice, twoAPrice, oneAPrice;
    cout << "Enter the train number: ";
    cin >> trainNumber;
    cout<< "Enter source: ";
    cin>> from;
    cout<< "Enter Destination: ";
    cin>> to;
    cout << "Enter the price for Sleeper class: ";
    cin >> sleeperPrice;
    cout << "Enter the price for 3A class: ";
    cin >> threeAPrice;
    cout << "Enter the price for 2A class: ";
    cin >> twoAPrice;
    cout << "Enter the price for 1A class: ";
    cin >> oneAPrice;
    Ticket ticket(classtype, trainNumber, from , to, sleeperPrice, threeAPrice, twoAPrice, oneAPrice);
    ofstream file("ticket_price.txt", ios::app);
    if (file.is_open()) 
    {
        file << ticket.getTrainNumber() << " " << ticket.getFrom()<<" "<<ticket.getTo()<< " "<< "Sleeper " << ticket.getSleeperPrice() << " " << "3A " <<
            ticket.getThreeAPrice() << " " << "2A " << ticket.getTwoAPrice() << " " << "1A " <<
            ticket.getOneAPrice() << endl;
        cout << "Ticket prices added successfully." << endl;
    } 
    else 
    {
        cout << "Unable to open file." << endl;
    }
    file.close();
}


// Function to delete ticket prices for a train
void deleteTicketPrices()
{
    string trainNumber;
    cout << "Enter the train number: ";
    cin >> trainNumber;

    ifstream inputFile("ticket_price.txt");
    ofstream tempFile("temp.txt");

    if (inputFile.is_open() && tempFile.is_open())
    {
        string line;
        bool trainFound = false;

        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string number;
            ss >> number;

            if (number != trainNumber)
            {
                tempFile << line << endl;
            }
            else
            {
                trainFound = true;
                cout << "Ticket prices deleted successfully." << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        remove("ticket_price.txt");
        rename("temp.txt", "ticket_price.txt");

        if (!trainFound)
        {
            cout << "Ticket not found." << endl;
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
void addTrainRoutes()
{
    string trainNumber, from, to;
    cout << "Enter the train number: ";
    cin >> trainNumber;
    cout << "Enter the source station (from): ";
    cin >> from;
    cout << "Enter the destination station (to): ";
    cin >> to;


    Route route(trainNumber, from, to);


    ofstream file("route_details.txt", ios::app);
    if (file.is_open()) 
    {
        file << route.getTrainNumber()<< " " << route.getFrom() << " " << route.getTo() << endl;
        cout << "Train route added successfully." << endl;
    } 
    else 
    {
        cout << "Unable to open file." << endl;
    }
    file.close();
}
void deleteTrainRoutes()
{
    string trainNumber;
    cout << "Enter the train number: ";
    cin >> trainNumber;

    ifstream inputFile("route_details.txt");
    ofstream tempFile("temp.txt");

    if (inputFile.is_open() && tempFile.is_open())
    {
        string line;
        bool trainFound = false;

        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string number;
            ss >> number;

            if (number != trainNumber)
            {
                tempFile << line << endl;
            }
            else
            {
                trainFound = true;
                cout << "Train routes deleted successfully." << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        remove("route_details.txt");
        rename("temp.txt", "route_details.txt");
        if (!trainFound)
        {
            cout << "Train route Not found." << endl;
        }
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}

// Function to book train tickets
void bookTickets() 
{
    string trainNumber, from, to;
    string ticketType;
    int numberOfPassengers;
    string dateOfTravel;
    int price;

    cout << "Enter the train number: ";
    cin >> trainNumber;
    cout << "Enter the source station (from): ";
    cin >> from;
    cout << "Enter the destination station (to): ";
    cin >> to;

    // Verify if the ticket prices exist for the specified train and route
    ifstream ticketFile("ticket_price.txt");
    if (ticketFile.is_open()) 
    {
        string line;
        while (getline(ticketFile, line)) 
        {
            stringstream ss(line);
            string number, src, dest;
            ss >> number >> src >> dest;

            if (number == trainNumber && src == from && dest == to) 
            {
                // Ticket prices found, display and ask for ticket type
                cout<< endl;
                cout << "Ticket prices for the selected train and route:" << endl;
                cout << line << endl;
                cout<<endl;
                cout << "Enter the class type (Sleeper/3A/2A/1A): ";
                cin >> ticketType;
                break;
            }
        }
        ticketFile.close();

        // Verify if a valid ticket type was entered
        if (ticketType != "Sleeper" && ticketType != "3A" && ticketType != "2A" && ticketType != "1A") 
        {
            cout << "Invalid ticket type. Booking failed." << endl;
            return;
        }
    } 
    else 
    {
        cout << "Unable to open ticket price file. Booking failed." << endl;
        return;
    }

    cout << "Enter the number of passengers: ";
    cin >> numberOfPassengers;

    cout << "Enter the date of travel (DD/MM/YYYY): ";
    cin >> dateOfTravel;

    // Prompt the user for passenger details
    vector<string> passengerNames(numberOfPassengers);
    vector<string> passengerAges(numberOfPassengers);
    vector<string> passengerGenders(numberOfPassengers);

    for (int i = 0; i < numberOfPassengers; i++) 
    {
        cout << "Enter passenger " << (i + 1) << " name: ";
        cin >> passengerNames[i];
        cout << "Enter passenger " << (i + 1) << " age: ";
        cin >> passengerAges[i];
        cout << "Enter passenger " << (i + 1) << " gender: ";
        cin >> passengerGenders[i];
    }

    // Create a string with the passenger details
    stringstream passengerDetails;
    passengerDetails << "Booking Details Below "<<endl;
    passengerDetails << endl;
    passengerDetails << "Train Number: " << trainNumber << endl;
    passengerDetails << "From: " << from << endl;
    passengerDetails << "To: " << to << endl;
    passengerDetails << "Class: " << ticketType << endl;
    passengerDetails << "Date of Travel: " << dateOfTravel << endl;
    passengerDetails << "Number of Passengers: " << numberOfPassengers << endl;

    for (int i = 0; i < numberOfPassengers; i++)
    {
        passengerDetails << "\nPassenger " << (i + 1) << " Details:\n";
        passengerDetails << "Name: " << passengerNames[i] << endl;
        passengerDetails << "Age: " << passengerAges[i] << endl;
        passengerDetails << "Gender: " << passengerGenders[i] << endl;
        passengerDetails << endl;
        passengerDetails << "**********************************************************************************"<<endl;
    }

    // Save the passenger details to the file
    ofstream passengerFile("passenger_details.txt", ios::app);
    if (passengerFile.is_open()) 
    {
        passengerFile << passengerDetails.str() << endl;
        passengerFile.close();
        cout << "\nBooking successful! Passenger details saved." << endl;
        cout<< "\n**********************************************************************************"<<endl;
    }
    else 
    {
        cout << "\nUnable to open passenger details file. Booking failed." << endl;
    }
    

}
void displayPassengerDetails() 
{
    ifstream displayticket("passenger_details.txt");
    if (displayticket.is_open()) 
    {
        string line;
        while (getline(displayticket, line)) {
            cout << line << endl;
        }
        displayticket.close();
    } 
    else 
    {
        cout << "Unable to open passenger file." << endl;
    }
}

// Function to display admin menu
void displayAdminMenu() 
{
    cout << "********** Admin Menu **********" << endl;
    cout << "1. Add Train" << endl;
    cout << "2. Delete Train" << endl;
    cout << "3. Add Ticket Prices" << endl;
    cout << "4. Delete Ticket Prices" << endl;
    cout << "5. Add Train Routes" << endl;
    cout << "6. Delete Train Routes" << endl;
    cout << "7. Logout" << endl;
    cout << "**************************************" << endl;
}


// Function to display user menu
void displayUserMenu() {
    cout << "********** User Menu *********" << endl;
    cout << "1. Book Tickets" << endl;
    cout << "2. Check Ticket Status" << endl;
    cout << "3. Logout" << endl;
    cout << "***************************************" << endl;
}


int main() 
{
    int choice;
    bool loggedIn = false;
    string userType;
    string classtype;

    while (true) 
    {
        cout << "Welcome to Train Booking System!" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. User Login" << endl;
        cout << "3. Create User Account" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
            case 1:
                if (loggedIn) {
                    cout << "You are already logged in." << endl;
                } else {
                    if (validateLogin("admin")) {
                        loggedIn = true;
                        userType = "admin";
                        cout << "Admin login successful." << endl;
                    } else {
                        cout << "Invalid credentials. Please try again." << endl;
                    }
                }
                break;


            case 2:
                if (loggedIn) {
                    cout << "You are already logged in." << endl;
                } else {
                    if (validateLogin("user")) {
                        loggedIn = true;
                        userType = "user";
                        cout << "User login successful." << endl;
                    } else {
                        cout << "Invalid credentials. Please try again." << endl;
                    }
                }
                break;


            case 3:
                if (loggedIn) {
                    cout << "You are already logged in." << endl;
                } else {
                    string newUserType;
                    cout << "Enter user type (admin/user): ";
                    cin >> newUserType;
                    createAccount(newUserType);
                }
                break;


            case 4:
                cout << "Thank you for using the Train Booking System. Goodbye!" << endl;
                return 0;


            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }


        while (loggedIn) {
            if (userType == "admin") {
                displayAdminMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        addTrain();
                        break;


                    case 2:
                        deleteTrain();
                        break;


                    case 3:
                        addTicketPrices(classtype);
                        break;


                    case 4:
                        deleteTicketPrices();
                        break;


                    case 5:
                        addTrainRoutes();
                        break;


                    case 6:
                        deleteTrainRoutes();
                        break;
                    case 7:
                        loggedIn = false;
                        cout << "Logged out successfully." << endl;
                        break;


                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            } 
            else if (userType == "user") 
            {
                displayUserMenu();
                cout << "Enter your choice: ";
                cin >> choice;


                switch (choice) 
                {
                    case 1:
                        bookTickets();
                        break;
                    case 2:
                        displayPassengerDetails();
                        break;
                    case 3:
                        loggedIn = false;
                        cout << "Logged out successfully." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
            }
        }
    }
    return 0;
}