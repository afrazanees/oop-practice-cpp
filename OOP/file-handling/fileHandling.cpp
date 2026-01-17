#include <iostream>
#include <fstream>
using namespace std;

//--------Write data to a file
/*int main (){
    ofstream outFile;
    outFile.open("text.txt"); //Create an output file

    // Check if the file was opened successfully
    if (outFile.is_open()){
        outFile << "Welcome To File Handling!"; // Write to the file
        cout << "Hello World!";
    }else {
        cout << "Error while creating or opening a fiel!"; // Always close the file after use for resources realese
    }
    outFile.close();
}*/


//---------Read Data from File
/*int main (){
    ifstream inFile;
    inFile.open("text.txt");

    if(inFile.is_open()){
        cout << "File is opened!" << endl;
    }else{
        cout << "Error while opening file!" <<endl;
    }
    
    //Chracter-by-chracter
    while(!inFile.eof()){ //eof() is a function, means "End of File"
        // char ch;
        // cout << ch;
        // inFile>>ch;

        // //To solve "Not getting space issue"
        // char ch;
        // ch = inFile.get();
        // cout << ch;

        //Line-by-line
        while(!inFile.eof()){
            string line;
            getline(inFile, line);
            cout << line << endl;
        }
    }

    inFile.close();
}*/


//--------Append(Add new content to an existing file without overwriting it) data to a file
/*int main (){
    ofstream outFile;
    outFile.open("text.txt", ios::app); //Open file in append mode

    // Check if the file was opened successfully
    if (outFile.is_open()){
        cout << "File is Open!";
        outFile << "\nThis is an appended line!"; // Write to the file
    }else {
        cout << "Error: Could not open the file for appending!"; // Always close the file after use for resources realese
    }
    outFile.close();
}*/


//--------Clearing a File
/*int main (){
    ofstream outFile;
    outFile.open("text.txt", ios::trunc); //Open file in truncate mode

    // Check if the file was opened successfully
    if (outFile.is_open()){
        cout << "File contents cleared successfully!";
    }else {
        cout << "Error while creating or opening a fiel!"; // Always close the file after use for resources realese
    }
    outFile.close();
}*/

//----------All operations
int main (){

    //Write to a file
    ofstream outFile;
    outFile.open("text.txt");
    if(outFile.is_open()){
        cout << "File opened successfully to write data!"<<endl;
        outFile<<"This is the first line.\n";
        outFile<<"This is the second line.\n";
    }else{
        cout << "Error: Cannot write successfully";
    }
    outFile.close();

    //Read from a file
    ifstream inFile;
    inFile.open("text.txt");
    if(inFile.is_open()){
        cout << "File opened successfully to read data!" << endl;
        int choice;
        cout << "Read Data: \n1. Character by chracter \n2. Line by line";
        cout << "\nChoice: ";
        cin >> choice ;
        if(choice == 1){
            char c;
            while (!inFile.eof()){
                c = inFile.get();
                cout << c ;
            }
        } else if (choice == 2){
            string line;
            while(!inFile.eof()){
                getline(inFile, line);
                cout << line << endl;;
            }
        }else{
            cout << "Invalid Choice!";
            return 1;
        }
    }else{
        cout << "Error: Cannot read successfully"<<endl;
    }
    inFile.close();

    //Append a line
    ofstream outFileAppened("text.txt", ios::app);
    if(outFileAppened.is_open()){
        cout << "File opened successfully for data appened!" <<endl;
        outFileAppened << "Appended Line here!";
    }else{
        cout << "Error: Cannot Appened successfully";
    }
    outFileAppened.close();

    //Read again to check the appended content
    ifstream inFileAppended("text.txt");
    if(inFileAppended.is_open()){
        cout << "File opened successfully for data reading again!";
        while (!inFileAppended.eof()){
            string line;
            getline(inFileAppended, line);
            cout << line << endl;
        }
    }else{
        cout << "Error: Cannot Read Appened line successfully";
    }
    inFileAppended.close();
}