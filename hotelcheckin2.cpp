#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

// The main code is found here.

int main()
{

// Introducing variables

    int night1 = 80, night2 = 100;      // Price of single and double room
    int total1, total2;                 // Total price with a discount
    char again;                         // again = Y or y, input from user if the program will be run again
    int choice;                         // Input 1, 2 or 3 in the main menu
                   // Random number created for the reservation number
    double reservation_check;           // Input this for checking the reservation in case3.
    int count;                           // For the for-loop
    int val;

// Introducing a struct where all the data from the guest will be stored

     struct Guest
    {
        string name;          // Name
        double number;     // Reservation number
        double nights;        // Amount of nights staying
    };


// Introducing prototypes for subroutines

    void randomNumGenerator1();              // This subroutine generates a random number between 10,000 and 99,999
    void randomNumGenerator2();              // This subroutine generates a random number between 20,000 and 99,999
    void checkRes1(const Guest &guest1);                  
    void checkRes2(const Guest &guest2);
                                         

// Using a do-while loop so the program can be run as many times based on user choice

    do
    {

        cout << "- - - - - - - - - - - - - - - - -" << endl;
        cout << "Welcome to Jasu's Hotel, thank you for choosing us!" << endl;
        cout << "Please choose a action you would like to proceed to by entering a number 1, 2 or 3 !:" << endl;
        cout << "1. Single room booking -> " << endl;
        cout << "2. Double room booking -> " << endl;
        cout << "3. Checking your reservation -> " << endl;
        cin >> choice;

        Guest guest1;
        Guest guest2;

    // Menu created by using if-else if-else loop.


    // Input 1: Single room booking option, first it will generate a random number for a reservation and
    // ask the user to input different inputs and lastly it will showcase a invoice of the reservation.
                        
                if (choice == 1)
                {
                    cout << "You chose 1. Single room booking!" << endl;
                                
                    randomNumGenerator1();

                    cout << "Fill out your information." << endl;

                    struct Guest guest1;

                    cout << "Please enter your full name: " << endl;
                    cin.ignore();
                    getline (cin, guest1.name);
                    cout << "Please enter you reservation number you got assigned:" << endl;
                    cin >> guest1.number;
                    cout << "Please enter the amount of nights you would like to stay:" << endl;
                    cin >> guest1.nights;
                    cout << "Price for a single room is 80 euros/night. " << endl;
                    cout << "Price for your stay is " << guest1.nights * night1 << " euros, before discounts." << endl;
                    cout << endl;
                    cout << endl;
                    cout << "- - - - - - - - - - - - - - " << endl;
                    cout << "Here is your final invoice:" << endl;
                                
                    int total1 =  night1 - (rand()%25)+1; // This will randomize a discount for the final invoice (min. 1€/night max. 25€/night)

                    cout << "Type of room: Single room " << endl;
                    cout << "Name of guest: " << guest1.name << endl;
                    cout << "Amount of nights: " << guest1.nights << endl;
                    cout << "Price per night: " << night1 << " euros. " << endl;
                    cout << "Total price for the stay: " << total1 * guest1.nights << " euros. Congratulations, you got a surprise discount!" << endl;
                                
                }
                            
                            
    // Input 2: Double room booking option, basically the same structure as the single room, just sligthly different variables.

                else if (choice == 2)
                {

                    cout << "You chose 2. Double room booking!" << endl;
                                
                    randomNumGenerator2();

                    cout << "Fill out your information." << endl;

                    struct Guest guest2;

                    cout << "Please enter your full name: " << endl;
                    cin.ignore();
                    getline (cin, guest2.name);
                    cout << "Please enter you reservation number you got assigned:" << endl;
                    cin >> guest2.number;
                    cout << "Please enter the amount of nights you would like to stay:" << endl;
                    cin >> guest2.nights;
                    cout << "Price for a double room is 100 euros/night. " << endl;
                    cout << "Price for your stay is " << guest2.nights * night2 << " euros, before discounts." << endl;
                    cout << endl;
                    cout << endl;
                    cout << "- - - - - - - - - - - - - - " << endl;
                    cout << "Here is your final invoice:" << endl;

                    int total2 =  night2 - (rand()%30)+1; // This will randomize a discount for the final invoice min. 1€/night max. 30€/night

                    cout << "Type of room: Single room " << endl;
                    cout << "Name of the guest: " << guest2.name << endl;
                    cout << "Amount of nights: " << guest2.nights << endl;
                    cout << "Price per night: " << night2 << " euros. " << endl;
                    cout << "Total price of the stay: " << total2 * guest2.nights << " euros. Congratulations, you got a surprise discount!" << endl;
                    
                } 
                            

    // Case 3: reservation checking option

                else if (choice == 3)
                {
                
                    cout << "You chose reservation checking!" << endl;
                    cout << "Did you book a Single or a Double room? (1/2)" << endl;
                    cin >> val;

                        if (val == 1)
                        {
                            cout << "Please enter your reservation number: " << endl;
                            cin >> guest1.number;
                            checkRes1(guest1);
                        }
                        
                        else if (val ==2)
                        {
                            cout << "Please enter your reservation number: " << endl;
                            cin >> guest2.number;
                            checkRes2(guest2);
                        }
                        
                        else 
                        {
                            cout << "Please enter 1 or 2!." << endl;
                        }
                            
                
                     
                }
                           
                else
                {
                    cout << "You didn't enter 1, 2 or 3! Try again!" << endl;
                }
                
        cout << endl;
        cout << endl;
        cout << "Would you like to go back to Main Menu? (Y/N)";
        cin >> again;

    } while (again == 'Y' || again == 'y');


return 0;
}

// All the prototypes and their code will be found here.

    void randomNumGenerator1() // This will generate the random number for the initial reservation number
    {
            static double random_number1;

            random_number1 = rand()%99999+100000;
            cout << "Your reservation number is " << random_number1 << ". " << "Please save this so you can enter it later for your reservation." << endl;
    }

void randomNumGenerator2() // This will generate the random number for the initial reservation number
    {
            static double random_number2;

            random_number2 = rand()%99999+200000;
            cout << "Your reservation number is " << random_number2 << ". " << "Please save this so you can enter it later for your reservation." << endl;
    }

    void checkRes1 (Guest guest1)
    {

        double random_number1;
        random_number1 = rand()%99999+100000;

        if (guest1.number == random_number1)
        {
            cout << "yes";
        }

        else 
        {
            cout << "shit";
        }    
    }

    void checkRes2 (Guest guest2)
    {
        double random_number2;
        random_number2 = rand()%99999+100000;

        if (guest2.number == random_number2)
        {
            cout << "yes";
        }

        else 
        {
            cout << "shit";
        }    
    }

  
    
    