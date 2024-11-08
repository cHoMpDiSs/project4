//
//  main.cpp
//  week4
//
//  Created by Jordon Marchesano on 11/7/24.
//

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

int readDials(string num);
int toDigit(char ch);

int toDigit(char ch) {
    char c = toupper(ch);
    if (!isalnum(static_cast<unsigned char>(c))) {
        return -1;
    }
    switch (c) {
        case 'A': case 'B': case 'C':
            return 2;
        case 'D': case 'E': case 'F':
            return 3;
        case 'G': case 'H': case 'I':
            return 4;
        case 'J': case 'K': case 'L':
            return 5;
        case 'M': case 'N': case 'O':
            return 6;
        case 'P': case 'Q': case 'R': case 'S':
            return 7;
        case 'T': case 'U': case 'V':
            return 8;
        case 'W': case 'X': case 'Y': case 'Z':
            return 9;
        default:
            return c - '0';

    }
}

int readDials(string num){
    long int numLength = num.length();
    vector<int> convertedNum;
     if(numLength < 8){
         return 0;
     }
     else if (num[0] == '0'){
         return -2;
     }
  
     else if (num[3] != '-'){
         return -4;
     }
     else{
         for (int i = 0; i <= 3; i++){
             cout << num[i] << " Num I" << endl;
             if (num[i] == '5'){
                 continue;
             }
             else if(i > 3 && num[i] != '5'){
                 break;
             }
             return -3;
         }
     }
    for (int i = 0; i < numLength; i++){
        if (i == 3){
            continue;
        }
        else{
            convertedNum.push_back(toDigit(num[i]));
        }
    }
    string dialedNumber;
    for (int i = 0; i < convertedNum.size(); ++i) {
        if (i == 3) {
                dialedNumber += '-';
            }
        dialedNumber += to_string(convertedNum[i]);
        }
        cout << "Dialed number: " << dialedNumber << endl;
    return 0;
}

string phoneNumber;

int main(int argc, const char * argv[]) {
    int studentId1, studentId2;
    studentId1 = 900536880;
    studentId2 = 900914917;
    string nameStudent1, nameStudent2;
    nameStudent1 = "Jordon Marchesano";
    nameStudent2 = "Glen Dsouza";
    cout  << left << setw(18) << "Student Name: " << nameStudent1 << endl;
    cout  << left << setw(18) << "Student ID: " << studentId1 << endl;
    cout  << left << setw(18) << "Student Name: " << nameStudent2 << endl;
    cout  << left << setw(18) << "Student ID: " << studentId2 << "\n" << endl;
   
 
    while (true){
        cout << "Enter a phone number (Q to quit): ";
        cin >> phoneNumber;
        if (phoneNumber == "q" || phoneNumber == "Q"){
            cout << "Press any key to continue..." << endl;
            break;
            
        }
        int result = readDials(phoneNumber);
        switch (result){
            case 0:
                break;
            case -1:
                cout << "ERROR - An invalid character was entered" << endl;
                break;
            case -2:
                cout << "ERROR - Phone number cannot begin with 0" << endl;
                break;
            case -3:
                cout << "ERROR - Phone number cannot begin with 555" << endl;
                break;
            case -4:
                cout << "ERROR - Hyphen is not in the correct position" << endl;
                break;
        }
        
    }
    
    cin.ignore();
    cin.get();
    return 0;
    
    
}
