#include <iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include <cctype>
#include <map>
using namespace std;


string encode(string &);
string  input,input_2;
string encode_(string &);
string  input_,input_2_;
char m;
string text;
string morseCode;
const int rows= 5;
const int columns = 5;
char polybiusSquare[rows][columns];




// Convert characters to Morse code by switch case
std::string morse(char m) {
    switch (toupper(m)) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case ' ':
            return " "; // Spaces
        default:
            return ""; // If user types special characters not in Morse
    }
}




// Function to decipher Morse code
std::string decipher_Morse(const std::string& morseCode) {
    std::unordered_map<std::string, char> morseToChar = {
            {".-", 'A'},
            {"-...", 'B'},
            {"-.-.", 'C'},
            {"-..", 'D'},
            {".", 'E'},
            {"..-.", 'F'},
            {"--.", 'G'},
            {"....", 'H'},
            {"..", 'I'},
            {".---", 'J'},
            {"-.-", 'K'},
            {".-..", 'L'},
            {"--", 'M'},
            {"-.", 'N'},
            {"---", 'O'},
            {".--.", 'P'},
            {"--.-", 'Q'},
            {".-.", 'R'},
            {"...", 'S'},
            {"-", 'T'},
            {"..-", 'U'},
            {"...-", 'V'},
            {".--", 'W'},
            {"-..-", 'X'},
            {"-.--", 'Y'},
            {"--..", 'Z'},
            {" ", ' '}, // Space
    };

    std::istringstream iss(morseCode);
    std::string word;
    std::string result;

    while (iss >> word) {
        auto it = morseToChar.find(word);
        if (it != morseToChar.end()) {
            result += it->second;
        } else {
            result += ' ';
        }
    }
    return result;
}




//function for Polybius Square cipher
void Polybius_Square(const int key[]) {
    int cell = 0;
    for (int i = 0; i < rows; ++i) {       // These loops iterate through each cell of the Polybius Square.
        for (int j = 0; j < columns; ++j) {
            polybiusSquare[i][j] = 'A' + cell;   // This line assigns a character to the current cell based on the value of
            if (polybiusSquare[i][j] == 'J') {
                polybiusSquare[i][j] = 'K';
                cell +=1;
            }
            ++cell;   // This increments the cell for the next iteration.
        }
    }
}




string Encryption (const string& text, const int key[]) {
    string encrypt_message = "";
    for (char ch : text) {
        ch = toupper(ch);
        if (ch == 'J') {        // If the character is 'J', replace it with 'I'
            ch = 'I';
        }
        if (isalpha(ch)) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    if (polybiusSquare[i][j] == ch) {  // If the current cell in the Polybius Square is equal to the character that the user input
                        string NumOfRow = to_string(key[i]);  // This will convert the values of key[i] into a string, key[i] represents the row index in the Polybius Square.
                        string NumOfColumn = to_string(key[j]);  // This will convert the values of key[j] into a string, key[j] represents the column index in the Polybius Square.
                        encrypt_message += NumOfRow + NumOfColumn ;  // Add the relevant key values to the message that is encrypted.
                    }
                }
            }
        } else {
            encrypt_message += " ";
        }
    }
    return encrypt_message;
}




string Decryption(const string& text, const int key[]) {
    string decrypt_message = "";

    for (size_t i = 0; i < text.length(); ++i) {
        if (isdigit(text[i])) {
            int row = static_cast<int>(text[i]) - static_cast<int>('0');
            int column = static_cast<int>(text[i + 1]) - static_cast<int>('0');

            for (int i = 0; i < rows; ++i) {
                if (key[i] == row) {
                    for (int j = 0; j < columns; ++j) {
                        if (key[j] == column) {
                            char decrypted_char = polybiusSquare[i][j];
                            decrypt_message += decrypted_char;
                            break;
                        }
                    }
                    break;
                }
            }
            ++i; // Increment i by 1 to move to the next pair of digits
        } else {
            decrypt_message += ' ';
        }
    }


    return decrypt_message;
}




int main(){
while (true){
    string menu,message;
    string menu_2,menu_3;
    cout<<"ahlan ya user ya habiby ;)"<<endl;
    cout<<"what do you like to do:"<<endl;
    cout<<"1-cipher a message:"<<"\n"<<"2-dicipher a message:"<<"\n"<<"3-end"<<"\n";
    cin>>menu;
    if (menu=="1"){
        cout<<"which cipher do you like to choose:"<<endl;
        cout<<"1-atbash cipher v1"<<"\n"<<"2-atbash cipher v2"<<"\n"<<"3-morse cipher"<<"\n"<<"4-Polybius Square Cipher"<<endl;
        cin>>menu_2;
        while (true){
            if (menu_2=="1"){
                //display atbash cipher v1
                        input_=message;
                        string menu_;
                          {cout<<"please enter a massege you want to encode: "<<endl;
                            cout<<encode_(input_)<<endl;
                            cout<<"*************************************************"<<endl;
                            input_2_.clear();
                            break;
                            }


            }
            else if (menu_2=="2"){
                //display atbash cipher v2
                    input=message;
                    string menu__;
                    {cout<<"please enter a massege you want to encode: "<<endl;
                        cout<<encode(input)<<endl;
                         cout<<"*************************************************"<<endl;
                        input_2.clear();
                        break;

                        }




            }
            else if (menu_2=="3"){
                //display morse cipher
                cin.ignore();
                cout << "Enter text you want to cipher: "<<endl;
            getline(cin, text);
            for (char m : text) {
                if (isalpha(m) || (isdigit(m))) {
                    cout << morse(m);
                }
                if (m == ' ') {
                    cout << ' ';
                } else {
                    continue;
                }
            }cout << endl;
            break;
            }
            else if(menu_2=="4"){
                //diplay Polybius Square Cipher
                int key[5];
                cout << "Enter five numbers for the key from 1 to 5:" << '\n';
                for (int i = 0; i < 5; ++i) {
                    cin >> key[i];
                }

                Polybius_Square(key);
                cin.ignore(); // To read all matrix
                string text;
                cout << "Enter the message to be encrypted: "<<endl;
                getline(cin, text);

                    string encrypt_message = Encryption (text, key);
                    cout << "Encrypted Message is: " << encrypt_message<<endl;
                    break;
            }
            else
                break;
            }
    }
    else if (menu=="2"){

        cout<<"which cipher do you like to choose: "<<endl;
        cout<<"1-atbash cipher v1"<<"\n"<<"2-atbash cipher v2"<<"\n"<<"3-morse cipher"<<"\n"<<"4-Polybius Square Cipher"<<endl;
        cin>>menu_3;
        while (true){
            if (menu_3=="1"){
                //display atbash cipher v1
                        input_=message;
                        string menu_;
                          {cout<<"please enter a massege you want to decode: "<<endl;
                            cout<<encode_(input_)<<endl;
                             cout<<"*************************************************"<<endl;
                            input_2_.clear();
                            break;
                            }



            }
            else if (menu_3=="2"){
                //display atbash cipher v2
                    input=message;
                    string menu__;
                    {cout<<"please enter a massege you want to decode: "<<endl;
                        cout<<encode(input)<<endl;
                         cout<<"*************************************************"<<endl;
                        input_2.clear();
                        break;
                        }




            }
            else if (menu_3=="3"){
                 //display morse cipher
             cin.ignore();
                cout << "Enter the Morse code you want to decipher:\n type any special char to make space:\n ";
            getline(cin, morseCode);
            string decodedText = decipher_Morse(morseCode);

            cout << "Deciphered text: " << decodedText;
            cout << endl;
            break;
            }
            else if(menu_3=="4"){
                //diplay Polybius Square Cipher
                int key[5];
                cout << "Enter five numbers for the key from 1 to 5:" << '\n';
                for (int i = 0; i < 5; ++i) {
                    cin >> key[i];
                }

                Polybius_Square(key);
                cin.ignore(); // To read all matrix
                string text;
                cout << "Enter the message to be decrypted: "<<endl;
                getline(cin, text);

                    string decrypt_message = Decryption(text, key);
                    cout << "Decrypted Message is: " << decrypt_message<<endl;
                    break;
            }
            else
                break;
            }
    }
    }





}



// atbash cipher v2
// function for incryption and decryption
string encode(string &input){
    getline(cin>>ws,input);
    // length of the input that the user will enter
    int x=input.length();
    // convert input to upper case string
    for(int z=0;z<=x;z++)
        {input[z]=toupper(input[z]);}
    // map for replacing each char with its corresponding char
    map<char,char> cipher={
        {'A','M'},{'B','L'},{'C','K'},{'D','J'},{'E','I'},{'F','H'},{'G','G'},{'H','F'},
        {'I','E'},{'J','D'},{'K','C'},{'L','B'},{'M','A'},{'N','Z'},{'O','Y'},{'P','X'},{'Q','W'},{'R','V'},{'S','U'},{'T','T'},
        {'U','S'},{'V','R'},{'W','Q'},{'X','P'},{'Y','O'},{'Z','N'}
        };
     // loop to iterate at each char in the string and apply the cipher
    for (int i=0;i<x;i++){
            // the condition for checking if the char in the string within the map or not
            if (cipher.find(input[i]) != cipher.end()) {
                // Check if the character is alphabetic
                input_2 += cipher[input[i]];
            }else {
                 // Keep non-alphabetic characters unchanged
                input_2 += input[i];
                }
    }
    // return the new string
    return input_2;
    }



//atbash cipher v1
// function for incryption and decryption
string encode_(string &input_){
    getline(cin>>ws,input_);
    // length of the input that the user will enter
    int x=input_.length();
    // convert input to upper case string
    for(int z=0;z<=x;z++)
        {input_[z]=toupper(input_[z]);}
    // map for replacing each char with its corresponding char
    map<char,char> cipher={
        {'A','Z'},{'B','Y'},{'C','X'},{'D','W'},{'E','V'},{'F','U'},{'G','T'},{'H','S'},
        {'I','R'},{'J','Q'},{'K','P'},{'L','O'},{'M','N'},{'N','M'},{'O','L'},{'P','K'},{'Q','J'},{'R','I'},{'S','H'},{'T','G'},
        {'U','F'},{'V','E'},{'W','D'},{'X','C'},{'Y','B'},{'Z','A'}
        };
    // loop to iterate at each char in the string and apply the cipher
    for (int i=0;i<x;i++){
           // Check if the character is alphabetic
            if (cipher.find(input_[i]) != cipher.end()) {
                // the variable in which we but the corresponding char to form a new string
                input_2_ += cipher[input_[i]];
            }else {
                // Keep non-alphabetic characters unchanged
                input_2_ += input_[i];
                }
    }
    // return the new string
    return input_2_;

}
