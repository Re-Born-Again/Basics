
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream f1("sample.txt");
    f1<<"line 1"<<endl;
    f1<<"line 2"<<endl;             // to write into file
    f1<<"line 3"<<endl;
    f1.close();
    cout<<endl;

    string text;
    ifstream f2("sample.txt");
    f2>>text;                       // to read only 1st word
    cout<<text<<endl;
    f2.close();
    cout<<endl;

    ifstream f3("sample.txt");
    getline(f3,text);               // to read 1st line
    cout<<text<<endl;    
    f3.close();
    cout<<endl;

    ifstream f4("sample.txt");
    while(getline(f4,text))         // to read whole file
        cout<<text<<endl;
    f4.close();
    cout<<endl<<endl;

    // if everything(above code) given using same file obj then according to the cursor movement result changes
    ifstream f5("sample.txt");
    f5>>text;                       
    cout<<text<<endl;               // reads 1st word
    cout<<endl;

    getline(f5,text);               
    cout<<text<<endl;               // reads 1st line except 1st word as cursor moved
    cout<<endl;

    while(getline(f5,text))         
        cout<<text<<endl;           // reads whole file except 1st line as cursor moved
    cout<<endl;

    f5.close();

    ofstream f6("sample.txt");
    f6<<"File erased"<<endl;
    f6.close();
    ifstream f7("sample.txt");
    while(getline(f7,text))         // reading the whole file agagin but everythin will be erased when opened again
        cout<<text<<endl;
    cout<<endl;
    f7.close();

    ofstream f8("sample.txt",ios::app);             // to append data to existing file
    f8<<"File appended without erasing"<<endl;
    f8.close();
    ifstream f9("sample.txt");
    while(getline(f9,text))         
        cout<<text<<endl;
    cout<<endl;
    f9.close();
    
    ofstream f10("sample.txt");
    f10<<"New data overwritten"<<endl;
    f10.close();
    ifstream f11("sample.txt");
     while(getline(f11,text))         
        cout<<text<<endl;
    cout<<endl;

    remove("sample.txt");               // to delete file

    if(getline(f11,text)==0)
        cout<<"File deleted successfully"<<endl;
    f11.close();

}