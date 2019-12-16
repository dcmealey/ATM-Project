/*
    This program is a program coded by Caleb Mealey, which is a fully functional ATM (automated teller machine) interface that will keep track of bank account balances (checking & savings) and allow a user to make money deposits, withdrawals, and transfers, and check on the balances.
*/

//  import header, include iostream, cstdlib, and filestream (fstream) & string
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

// Establish 'yes', using namespace std
using namespace std;

// Incorrect Input Display - outputs a standard generic "Incorrect Input! Try Again!" output to user
void incorrectInputDisplay() {
     // display error message to user
    cout <<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|            Incorrect Input!               | \n"
         <<"|                                           | \n"
         <<"|               Try Again!                  | \n"
         <<"|___________________________________________| \n";          
}

// Main Menu - outputs the main menu with the basic 5 ATM transactions to perform
void displayMainMenu() {
    // display menu
     cout<<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|                MAIN MENU                  | \n"
         <<"|                                           | \n"
         <<"|             1) Deposit                    | \n"
         <<"|                                           | \n"
         <<"|             2) Withdrawal                 | \n"
         <<"|                                           | \n"
         <<"|             3) Transfer                   | \n"
         <<"|                                           | \n"
         <<"|             4) Balance Inquiry            | \n"
         <<"|                                           | \n"
         <<"|             5) Reset Pin                  | \n"
         <<"|                                           | \n"
         <<"|             6) Exit (Ctrl-C)              | \n"
         <<"|                                           | \n"
         <<"|___________________________________________| \n"
         <<"                                              \n"
         <<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|           Enter Choice:                   | \n"
         <<"|___________________________________________| \n";
}

// Deposit Menu - to select which account to deposit into
void depositMenu() {
    // display deposit sub-menu    
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|      Deposit to Which Account?            | \n"
             <<"|                                           | \n"
             <<"|         1) Checking                       | \n"
             <<"|                                           | \n"
             <<"|         2) Savings                        | \n"
             <<"|                                           | \n"
             <<"|          Enter Choice:                    | \n"
             <<"|___________________________________________| \n";
}

// Deposit Function - contains all of the logic for the deposit transaction - queries which account to use, performs the math, and then updates the pointer variables values.
void depositFunc(int inputacct, double deposit, double &checking, double &savings) {
    
    // launch pointer variables for checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    
    // call the deposit menu to be outputted
    depositMenu();
    // Assign user input for the deposit menu options
    cin >> inputacct;
    
    // initialize a switch statement
    switch(inputacct) {
        
        // case 1 - deposit into checking account
        case 1:
        
        // display current balance, request amount to be deposited
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|      Current Checking Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerChecking <<"                     \n"
             <<"|                                           | \n"
             <<"|          Deposit Amount:$                 | \n"
             <<"|___________________________________________| \n";
            
            // Assign user input for the amount to be depositted
            cin >> deposit;
            
            // perform math
            *pointerChecking = *pointerChecking + deposit;
       
        // display the amount depositted, and updated balance
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"    You deposited in :$" << deposit <<"           \n"
             <<"|                                           | \n"
             <<"|      Current Checking Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerChecking <<"               \n"
             <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
        
        // case 2 - deposit into savings account
        case 2:
        
        // display current balance, request amount to be deposited
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|       Current Savings Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerSavings <<"                     \n"
             <<"|                                           | \n"
             <<"|          Deposit Amount:$                 | \n"
             <<"|___________________________________________| \n";
            
            // Assign user input for the amount to be depositted
            cin >> deposit;
            
            // perform math
            *pointerSavings = *pointerSavings + deposit;
        
        // display the amount depositted, and updated balance
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"    You deposited in :$" << deposit <<"            \n"
             <<"|                                           | \n"
             <<"|      Current Savings Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerSavings <<"                     \n"
             <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
        
        // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
        default:    
            // clear user input
            cin.clear();
            cin.ignore(10000,'\n');
            
            // display error message to user
            incorrectInputDisplay();
            
            // break out of the current case loop
            break;
        }
}

// Withdrawal Menu - to select which account to withdraw from
void withdrawalMenu() {
        // Display withdrawal sub-menu
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|        Withdraw from:                     | \n"
             <<"|                                           | \n"
             <<"|         1) Checking                       | \n"
             <<"|                                           | \n"
             <<"|         2) Savings                        | \n"
             <<"|                                           | \n"
             <<"|          Enter Choice:                    | \n"
             <<"|___________________________________________| \n";
}

// Withdraw Function - contains all of the logic for the withdrawal transaction - queries which account to use, performs the math, and then updates the pointer variables values.
void withdrawFunc(int inputacct, double withdraw, double &checking, double &savings) {
    
    // launch pointer variables for checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    
    // call the withdrawal menu to be outputted
    withdrawalMenu();
    // Assign user input for the withdrawal menu options
    cin >> inputacct;
    
    // initialize a switch statement
    switch(inputacct) {
        
        // case 1 - withdraw from checking account
        case 1:
        
        // Request amount to withdrawn
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|      Current Checking Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerChecking <<"                     \n"
             <<"|                                           | \n"
             <<"|         Withdrawal Amount: $              | \n"
             <<"|___________________________________________| \n";
            
            // Assign that amount to the withdraw variable
            cin >> withdraw;
            
            // Check to make sure enough funds are in checkings account to perform withdraw
            if (*pointerChecking >= withdraw) {  
            
            // perform the math
            *pointerChecking = *pointerChecking - withdraw;
        
        // display the amount withdrawn, and updated balance
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"            You withdrew: $" << withdraw <<"      \n"
             <<"|                                           | \n"
             <<"|        Current Checking Balance:          | \n"
             <<"|                                           | \n"
             <<"             $"<< *pointerChecking <<"               \n"
             <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
            }
            
            // If not enough funds are avaible to perform withdraw, display this result and error to user
            if (*pointerChecking < withdraw) {
                
                // display 'Insufficient Funds' warning
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|          Unsuccessful Withdrawal          | \n"
                     <<"|                                           | \n"
                     <<"|   You do not have enough funds in your    | \n"
                     <<"| checking account to withdraw this amount: | \n"
                     <<"             $"<< withdraw << "                    \n"
                     <<"|___________________________________________| \n";              }
            
            // break out of the current case loop
            break;
        
        // case 2 - withdraw from savings account
        case 2:
        
        // Request amount to withdrawn
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|       Current Savings Balance:            | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerSavings <<"                     \n"
             <<"|                                           | \n"
             <<"|         Withdrawal Amount: $              | \n"
             <<"|___________________________________________| \n";
            
            // Assign that amount to the withdraw variable
            cin >> withdraw;
            
            // Check to make sure enough funds are in checkings account to perform withdraw
            if (*pointerSavings >= withdraw) {
            
            // perform the math
            *pointerSavings = *pointerSavings - withdraw;
        
        // display the amount withdrawn, and updated balance
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"           You withdrew: $" << withdraw <<"        \n"
             <<"|                                           | \n"
             <<"|        Current Savings Balance:           | \n"
             <<"|                                           | \n"
             <<"          $"<< *pointerSavings <<"                     \n"
             <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
            }
            
            // If not enough funds are avaible to perform withdraw, display this result and error to user
            if (*pointerSavings < withdraw) {
                
                // display 'Insufficient Funds' warning
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|          Unsuccessful Withdrawal          | \n"
                     <<"|                                           | \n"
                     <<"|   You do not have enough funds in your    | \n"
                     <<"|  savings account to withdraw this amount: | \n"
                     <<"             $"<< withdraw << "                    \n"
                     <<"|___________________________________________| \n";        
            }
            
            // break out of the current case loop
            break;
        
        // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
        default:    
            // clear user input
            cin.clear();
            cin.ignore(10000,'\n');
            
            // display error message to user
            incorrectInputDisplay();              
            
            // break out of the current case loop
            break;
        }
}

// Transfer Menu - to select which account to transfer from
void transferMenu() {
        // display transfer sub-menu
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|             Transfer:                     | \n"
             <<"|                                           | \n"
             <<"|         1) Checking to Savings            | \n"
             <<"|                                           | \n"
             <<"|         2) Savings to Checking            | \n"
             <<"|                                           | \n"
             <<"|          Enter Choice:                    | \n"
             <<"|___________________________________________| \n";
}

// Transfer Function - contains all of the logic for the transfer transaction - queries which account to use, performs the math, and then updates the pointer variables values.
void transferFunc(int inputacct, double transfer, double &checking, double &savings) {
    
    // launch pointer variables for checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    
    // call the transfer menu to be displayed
    transferMenu();
    
    // Assign user input for the transfer menu options
    cin >> inputacct;
    
    // initialize a switch statement
    switch(inputacct) {
       
        // case 1 - transfer from checking to savings
        case 1:
            
            // Display current balance, Request amount to be transferred
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|    Transfer from Checking to Savings      | \n"
                 <<"|                                           | \n"
                 <<"  Current Balance in Checking: $ "<< *pointerChecking <<  "    \n"
                 <<"|                                           | \n"
                 <<"|           Transfer Amount: $              | \n"
                 <<"|___________________________________________| \n";
            
            // Assign that amount to the transfer variable
            cin >> transfer;
            
            // Check if checkings account has enough funds to perform transfer, if there are sufficient funds ->
            if (*pointerChecking >= transfer) {
                
                // perform math
                *pointerChecking = *pointerChecking - transfer;
                *pointerSavings = *pointerSavings + transfer;
                
                // display successful tranfer output, showing amount transferred
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|           Successful Transfer             | \n"
                     <<"|                                           | \n"
                     <<"   Current Balance in Checking: $"<< *pointerChecking <<  "       \n"
                     <<"   Current Balance in Savings: $"<< *pointerSavings <<  "       \n"
                     <<"|___________________________________________| \n";   
                
                // break out of the current case loop
                break;
            }
            
            // Check if checkings account has enough funds to perform transfer, if there are insufficient funds ->
            if (*pointerChecking < transfer) {
                
                // display unsuccessful tranfer output, showing amount that wasn't able to be transferred
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|          Unsuccessful Transfer            | \n"
                     <<"|                                           | \n"
                     <<"|   You do not have enough funds in your    | \n"
                     <<"| checking account to transfer this amount: | \n"
                     <<"              $"<< transfer << "                    \n"
                     <<"|___________________________________________| \n";       
            }
            
            // break out of the current case loop
            break;
        
        // case 2 - transfer from savings to checking
        case 2:
            
            // Display current balance, Request amount to be transferred
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|    Transfer from Savings to Checking      | \n"
                 <<"|                                           | \n"
                 <<"  Current Balance in Savings: $ "<< *pointerSavings <<  "    \n"
                 <<"|                                           | \n"
                 <<"|           Transfer Amount: $              | \n"
                 <<"|___________________________________________| \n";
            
            // Assign that amount to the transfer variable
            cin >> transfer;
            
            // Check if savings account has enough funds to perform transfer, if there are insufficient funds ->
            if (*pointerSavings >= transfer) {
                
                // perform math
                *pointerSavings = *pointerSavings - transfer;
                *pointerChecking = *pointerChecking + transfer;
                
                // display successful tranfer output, showing amount transferred
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|           Successful Transfer             | \n"
                     <<"|                                           | \n"
                     <<"   Current Balance in Checking: $"<< *pointerChecking <<  "       \n"
                     <<"   Current Balance in Savings: $"<< *pointerSavings <<  "       \n"
                     <<"|___________________________________________| \n";   
                
                // break out of the current case loop
                break;
            }
            
            // Check if savings account has enough funds to perform transfer, if there are insufficient funds ->
            if (*pointerSavings < transfer) {
                
                // display unsuccessful tranfer output, showing amount that wasn't able to be transferred
                cout <<" ___________________________________________  \n"
                     <<"|                                           | \n"
                     <<"|          Unsuccessful Transfer            | \n"
                     <<"|                                           | \n"
                     <<"|   You do not have enough funds in your    | \n"
                     <<"|  savings account to transfer this amount: | \n"
                     <<"             $"<< transfer << "                    \n"
                     <<"|___________________________________________| \n";       
            }
            
            // break out of the current case loop
            break;
        
            // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
        default:    
            // clear user input
            cin.clear();
            cin.ignore(10000,'\n');
            
            // display error message to user
            incorrectInputDisplay();
            
            // break out of the current case loop
            break;
       }
}

// Balance Inquiry Menu - to select which account to query
void balanceInquiryMenu() {
        // display balance inquiry sub-menu
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|            Balance of:                    | \n"
             <<"|                                           | \n"
             <<"|         1) Checking                       | \n"
             <<"|                                           | \n"
             <<"|         2) Savings                        | \n"
             <<"|                                           | \n"
             <<"|          Enter Choice:                    | \n"
             <<"|___________________________________________| \n";
}

// Balance Inquiry Function - contains all of the logic for the balance inquiry function
void balanceInquiryFunc(int inputacct, double &checking, double &savings) {
    
    // launch pointer variables for checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    
    // call the balance inquiry menu to be displayed
    balanceInquiryMenu();
    
    // Assign user input for the balance inquiry menu options
    cin >> inputacct;
    
    // initialize a switch statement
    switch(inputacct) {
        
        // case 1 - Checking account balance inquiry
        case 1:
            
            // display current balance in checking account
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"  Current Balance in Checking: $ "<< *pointerChecking << "         \n"
                 <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
        
        // case 2 - Savings account balance inquiry
        case 2:
            
            // display current balance in savings account
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"  Current Balance in Savings:$ "<< *pointerSavings <<  "           \n"
                 <<"|___________________________________________| \n";
            
            // break out of the current case loop
            break;
        
        // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
        default:
            // clear user input
            cin.clear();
            cin.ignore(10000,'\n');
            
            // display error message to user
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|            Incorrect Input!               | \n"
                 <<"|                                           | \n"
                 <<"|               Try Again!                  | \n"
                 <<"|___________________________________________| \n";            
            
            // break out of the current case loop
            break;
    }
}                        

// Reset Pin Function - Reset Pin Logic & Function
int resetPinFunc(int pin) {
    
    // Initialize pincode_test, pincode_test2, pincode* (pointer) variables
    int pincode_test, pincode_test2;
    int * pincode = &pin;
    
    // Initialize while loop, setting the value to loop until *pincode != 0000 or the pin you were changing from
    while(*pincode == 0000 || *pincode == pin) {
        
        // Display Pin Reset Menu
        cout <<" ___________________________________________  \n"
             <<"|                                           | \n"
             <<"|              Reset Your Pin:              | \n"
             <<"|                                           | \n"
             <<"|  Current pincode: "<< *pincode << "           | \n"
             <<"|                                           | \n"
             <<"|        New pin must be 4 integers:        | \n"
             <<"|             and cannot be: 0000           | \n"
             <<"|___________________________________________| \n";
        
        // Assign user input to the pincode_test variable
        cin >> pincode_test;
        
        // test if the user inputted pincode_test variable is a legal four digit integer
        if (999<pincode_test && pincode_test<10000) {
            
            // requeest user to input the pin again, to confirm that its what they want
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|            Type it again:                 | \n"
                 <<"|___________________________________________| \n";
            
            // assign user input to the pincode_test2 variable
            cin >> pincode_test2;
            
            // test if the two user inputted pincodes are the same
            if (pincode_test == pincode_test2) {
                
                // assign *pincode to the user inputted new pin
                *pincode = pincode_test;
                pin = pincode_test;
            
            // display pin change success message
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|   You have successfully reset your pin!   | \n"
                 <<"|___________________________________________| \n";
                
                return pincode_test;
                
                // break out of the current case loop
                break;
                }
            
            // clear user input & display user input error message
            else {
                // clear user input
                cin.clear();
                cin.ignore(10000,'\n');
                
                // display user input error message output
                incorrectInputDisplay();
            }
        }
        
        // clear user input & display user input error message
        else {
            // clear user input
            cin.clear();
            cin.ignore(10000,'\n');
                
            // display user input error message output
            incorrectInputDisplay();
        }
    }
}

// Outgoing File Stream Save Function - Contains all the logic to save out the outgoing file stream path to the file "Bank_Accts.txt"
void outgoingFileStreamSaveFunc(int pin, double checking, double savings) {
    
    ofstream out_stream;
    
    // launch pointer variables for, pincode, checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    int * pincode = &pin;
    
    // Open the outgoing file stream to save within file, "Bank_Accts.txt"
    out_stream.open("Bank_Accts.txt");
    
    // save the checking, savings, and pincode values
    out_stream << 1 << " " << *pointerChecking << endl;
    out_stream << 2 << " " << *pointerSavings << endl;
    out_stream << 3 << " " << *pincode << endl;
    
    // close the outgoing file stream
    out_stream.close();
}
   

int main() {

    // initialize variables for savings, checking, and transfer variables
    double savings, checking, deposit, withdraw, transfer;
    // initialize pointer variables for checking & savings variables
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    
    // launch incoming and outgoing file streams as in_stream and out_stream respectively
    ifstream in_stream;
    ofstream out_stream;
    
    // initialize acct_id, pin, *pincode, and balance variables
    int acct_id, pin;
    int * pincode = &pin;
    double balance;
    
    // set incoming stream file stream to open "Bank_Accts.txt"
    in_stream.open("Bank_Accts.txt");
    
    // if it fails to open the file, intialize the welcome new user menu, initialize pincode to 0000
    if (in_stream.fail()) {
           // Display new user menu
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|                 Welcome!                  | \n"
                 <<"|                                           | \n"
                 <<"|  It appears this is your first time using | \n"
                 <<"|  our ATM program on this machine or from  | \n"
                 <<"|             this directory.               | \n"
                 <<"|                                           | \n"
                 <<"|    We recommend you deposit funds, and    | \n"
                 <<"|    reset the pincode for your account.    | \n"
                 <<"|                                           | \n"
                 <<"|      Your default pincode is: 0000        | \n"
                 <<"|                                           | \n"
                 <<"|                Thank You!                 | \n"
                 <<"|___________________________________________| \n";
        
        // initialize the pointer variables to 0
        *pointerChecking = 0.00;
        *pointerSavings = 0.00;
        *pincode = 0000;
    }
    
    // if the file is able to open, perform some logic to unpack the existing account balances and pincode
    if (in_stream.is_open()) {
            
            // display "Welcome Back!"
            cout <<" ___________________________________________  \n"
                 <<"|                                           | \n"
                 <<"|              Welcome Back!                | \n"
                 <<"|___________________________________________| \n";
        
        // unpack the existing file, and set the first number of each line to the "acct_id" variable, and the second number to that accout_id's "balance" variable
        while (in_stream >> acct_id >> balance) {
            
            // assign the checking balance to the first acct_id's balance value
            if(acct_id == 1) {
                *pointerChecking = balance;
            }
            
            // assign the savings balance to the second acct_id's balance value
            if(acct_id == 2) {
                *pointerSavings = balance;
            }
            
            // assign the pincode to the third acct_id's balance value
            if(acct_id == 3) {
                *pincode = balance;
            }
        }
        
        // close the incoming stream file stream
        in_stream.close();
    }
    

    
    // launch variable input, for user's input to the menu options
    int input, inputacct;
    
    // display "Enter your pin:" message
    cout <<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|            Enter your pin:                | \n"
         <<"|___________________________________________| \n";
    // Retrieve user's input and assign it to the variable input
    cin >> input;
    
    // start a while loop, which initiates the ATM program logic if the user inputted value for their pin matches the one on record, or if the *pincode variable value is 0000
    while (input == *pincode || *pincode == 0000) {          
        // display menu
        displayMainMenu();

        // Retrieve user's input and assign it to the variable input
        cin >> input;

        // Start a while loop, with the loop active as long as the user's input is not equal to 5 (input option to exit the program)
         while(input!=6) {

             // initialize a switch loop
            switch(input) {

                // case 1 - Deposit
                case 1:
                    depositFunc(inputacct, deposit, *pointerChecking, *pointerSavings);

                    // save pincode value, and checking & savings balances to outgoing file stream
                    outgoingFileStreamSaveFunc(*pincode, *pointerChecking, *pointerSavings);

                    // break out of the current case loop
                    break;

                // case 2 - Withdrawal
                case 2:
                    withdrawFunc(inputacct, deposit, *pointerChecking, *pointerSavings);

                    // save pincode value, and checking & savings balances to outgoing file stream
                    outgoingFileStreamSaveFunc(*pincode, *pointerChecking, *pointerSavings);

                    // break out of the current case loop
                    break;               

                // case 3 - Transfer
                case 3:
                    transferFunc(inputacct, transfer, *pointerChecking, *pointerSavings);

                    // save pincode value, and checking & savings balances to outgoing file stream
                    outgoingFileStreamSaveFunc(*pincode, *pointerChecking, *pointerSavings);

                    // break out of the current case loop
                    break;                
                // case 4 - Account Balance Inquiry
                case 4:
                    balanceInquiryFunc(inputacct, *pointerChecking, *pointerSavings);
                    // break out of the current case loop
                    break;

                // case 5 - Reset Pin
                case 5:
                    *pincode = resetPinFunc(*pincode);

                    // save pincode value, and checking & savings balances to outgoing file stream
                    outgoingFileStreamSaveFunc(*pincode, *pointerChecking, *pointerSavings);

                    // break out of the current case loop
                    break;

                // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
                default:
                    // clear user input
                    cin.clear();
                    cin.ignore(10000,'\n');

                    // display error message to user
                    incorrectInputDisplay();

                    // break out of the current case loop
                    break;
            }

        // display main menu
        displayMainMenu();

        // Retrieve user's input and assing it to the variable input
        cin >> input;
        }
    }
    
    // save pincode value, and checking & savings balances to outgoing file stream
    outgoingFileStreamSaveFunc(*pincode, *pointerChecking, *pointerSavings);    
    
    // display exit message, and exit program gracefully
    cout <<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|              Thank you!                   | \n"
         <<"|                                           | \n"
         <<"|    We hope to to see you using our        | \n"
         <<"|       C++ ATM Services again soon!        | \n"
         <<"|___________________________________________| \n";
    
    return 0;
}




 


 