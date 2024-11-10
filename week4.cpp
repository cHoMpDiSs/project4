#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;

char dig1, dig2, dig3, hyph, dig4, dig5, dig6, dig7;
void AcknowledgeCall();

void AckowledgeCall(){
    cout << "Phone Number Dialed: " << dig1 << dig2 << dig3 << hyph << dig4 << dig5 << dig6 << dig7 << endl;    
}

int toDigit(char &ch) {
    char c = toupper(ch);
    if (!isalnum(static_cast<unsigned char>(c))) {
        return -1;
    }
    switch (c) {
        case 'A': case 'B': case 'C':
           ch = '2';
            break;
        case 'D': case 'E': case 'F':
            ch = '3';
            break;
        case 'G': case 'H': case 'I':
            ch = '4';
            break;
        case 'J': case 'K': case 'L':
            ch = '5';
            break;
        case 'M': case 'N': case 'O':
            ch = '6';
            break;
        case 'P': case 'Q': case 'R': case 'S':
            ch = '7';
            break;
        case 'T': case 'U': case 'V':
            ch = '8';
            break;
        case 'W': case 'X': case 'Y': case 'Z':
            ch = '9';
            break;
        default:
            return c - '0';

    }
    return 0;
}
int readDials(){
//    char thing;
    //Initialize variables and get user input for phone #
    int verif1, verif2, verif3, verif4, verif5, verif6, verif7;
    verif1 = toDigit(dig1);
    verif2 = toDigit(dig2);
    verif3 = toDigit(dig3);
    verif4 = toDigit(dig4);
    verif5 = toDigit(dig5);
    verif6 = toDigit(dig6);
    verif7 = toDigit(dig7);
    if (verif1 == -1 || verif2 == -1 || verif3 == -1 || verif4 == -1|| verif5 ==-1 || verif6 == -1 || verif7 == -1){
        return -1;
    }
    if (dig1 == '0'){
        return -2;
    }
    if (dig1 == '5' && dig2 == '5' && dig3 == '5'){
        return -3;
    }
    if (hyph != '-'){
        return -4;
    }
    return 0;
}


int main(){
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
    int verify;
    while (true){
        cout << "Enter a phone number: (Q to quit) ";
        cin >> dig1;
        if (dig1 == 'Q'){
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            return 0;
        }
        cin >> dig2 >> dig3 >> hyph >> dig4 >> dig5 >> dig6 >> dig7;
        verify = readDials();
        switch (verify){
            case -1:
                cout << "ERROR - An invalid character was entered" << endl << endl;
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
            case 0:
                AckowledgeCall();
                break;
        }
        cout << endl;
        
    }

   
}
