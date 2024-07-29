#include<iostream>
#include<bitset>
using namespace std;

int main(){
    int dec = 5;
    int dec2 = 10;
    bitset<10> bin(dec); // <10> for length of binary number
    cout<<bin<<endl;
    string a = bin.to_string(); // converting to string
    cout<<a<<endl;
    cout<<bin.count()<<endl; // to count no of 1's
    string b = bitset<10>(dec2).to_string(); // another way to declare
    cout<<b<<endl;
}