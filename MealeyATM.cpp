//  import header, include iostream & string
#include <iostream>
#include <string>

/*
    This program is a program coded by Caleb Mealey, which is a fully functional ATM (automated teller machine) interface that will keep track of bank account balances (checking & savings) and allow a user to make money deposits, withdrawals, and transfers, and check on the balances.
*/
// Establish 'yes', using namespace std
using namespace std;

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
         <<"|             5) Exit (Ctrl-C)              | \n"
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
            cout << "You have entered in a wrong input" << endl;
            // break out of the current case loop
            break;
        }
}

// Withdrawal Menu - to select which account to withdraw from
void withdrawalMenu() {
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
             <<"          $"<< *pointerChecking <<"               \n"
             <<"|___________________________________________| \n";
            // break out of the current case loop
            break;
            }
            // If not enough funds are avaible to perform withdraw, display this result and error to user
            if (*pointerChecking < withdraw) {
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
            cout << "You have entered in a wrong input" << endl;
            // break out of the current case loop
            break;
        }
}

// Transfer Menu - to select which account to transfer from
void transferMenu() {
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
            cout << "You have entered in a wrong input" << endl;
            // break out of the current case loop
            break;
       }
}

// Balance Inquiry Menu - to select which account to query
void balanceInquiryMenu() {
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
            cout << "You have entered in a wrong input" << endl;
            // break out of the current case loop
            break;
    }
}                        

int main() {
    // launch variables for savings, checking, and transfer
    double savings, checking, deposit, withdraw, transfer;
    // launch pointer variables for checking & savings
    double* pointerChecking = &checking;
    double* pointerSavings = &savings;
    // initialize the pointer variables to 0
    *pointerChecking = 0.00;
    *pointerSavings = 0.00;
    // launch variable input, for user's input to the menu options
    int input, inputacct;
    // display menu
    displayMainMenu();
    // Retrieve user's input and assing it to the variable input
    cin >> input;
        
    // Start a while loop, with the loop active as long as the user's input is not equal to 5 (input option to exit the program)
     while(input!=5) {
        // initialize a switch loop
        switch(input) {
            // case 1 - Deposit
            case 1:
                depositFunc(inputacct, deposit, *pointerChecking, *pointerSavings);
                break;
            // case 2 - Withdrawal
            case 2:
                withdrawFunc(inputacct, deposit, *pointerChecking, *pointerSavings);
                break;                
            // case 3 - Transfer
            case 3:
                transferFunc(inputacct, transfer, *pointerChecking, *pointerSavings);
                break;                
            // case 4 - Account Balance Inquiry
            case 4:
                balanceInquiryFunc(inputacct, *pointerChecking, *pointerSavings);
                break;
            // default case - catches any incorrect input, clears the user inputted value, and displays error message to user
            default:
                // clear user input
                cin.clear();
                cin.ignore(10000,'\n');
                // display error message to user
                cout << "You have entered in a wrong input" << endl;
                // break out of the current case loop
                break;
        }
    // display main menu
    displayMainMenu();
    // Retrieve user's input and assing it to the variable input
    cin >> input;
    }
    // display exit message, and exit program gracefully
    cout <<" ___________________________________________  \n"
         <<"|                                           | \n"
         <<"|              Thank you!                   | \n"
         <<"|    Come Use our C++ ATM Services Soon!    | \n"
         <<"|___________________________________________| \n";
}




 


 