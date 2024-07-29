// g++ -std=c++11 vectors.cpp
#include<iostream>
#include<vector>
#include<algorithm> // for replace()
using namespace std;

void disp(vector<int> v){
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void disp2(vector<int> v){
    for (int val : v) {
        cout << val << " ";
    }
}

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    cout<<"v1 values : ";
    disp(v1);

    v1.pop_back(); // removes last element of the vector
    // use v1.back() to get last value of vector (like .top() in stack)

    vector<int> v2(9);
    for(int i=0;i<10;i++){
        v2.push_back(i*10);
    }
    cout<<"v2 values : ";
    disp(v2);

    cout<<"v2.size() : "<<v2.size()<<endl;
    cout<<"v2[3] : "<<v2[3]<<endl;
    cout<<"v2.at(3) : "<<v2.at(3)<<endl;
    cout<<"v2.front() : "<<v2.front()<<endl;
    cout<<"v2.back() : "<<v2.back()<<endl;
    cout<<"Last element : "<<v2[v2.size()-1]<<endl;
    cout<<endl;

    v2.assign(5,100); //freq,value
    cout<<"v2 values after using assign(5,10) : ";
    disp(v2);
    cout<<"v2.size() after .assign() : "<<v2.size()<<endl;    

    v2.insert(v2.begin()+4,50); //iterator,value
    cout<<endl<<"v2[4] after .insert() : "<<v2[4]<<endl;
    cout<<"v2.size() after linserting 4th value : "<<v2.size()<<endl;
    v2.erase(v2.begin()+4); // can give 2nd parameter too -> vec.erase(from_addr,to_addr)
    cout<<endl<<"v2[4] after .erase() : "<<v2[4]<<endl;    
    cout<<"v2.size() after erasing 4th value : "<<v2.size()<<endl;
    cout<<endl;

    cout<<"Before .swap() : "<<endl;
    cout<<"v1 values : ";
    disp(v1);
    cout<<"v2 values : ";
    disp(v2);

    v1.swap(v2);

    cout<<"After .swap() : "<<endl;
    cout<<"v1 values : ";
    disp(v1);
    cout<<"v2 values : ";
    disp(v2);

    v2.clear();
    cout<<"v2 values after .clear() : ";
    disp(v2);
    cout<<endl;

    vector<int> vec = {1, 2, 3, 4, 5, 3, 6, 3, 7};
    int valueToRemove = 3;

    cout << "before .remove() : ";
    disp2(vec);
    cout <<" vec.size()= "<<vec.size()<<endl;

    // remove(vec.begin(), vec.end(), valueToRemove);
    // cout << "after .remove() : ";
    // for (int val : vec) {
    //     cout << val << " ";
    // }
    // cout <<" vec.size()= "<<vec.size()<<endl;

    vec.erase(remove(vec.begin(),vec.end(),valueToRemove),vec.end());
    cout << "after .erase() : ";
    disp2(vec);
    cout <<" vec.size()= "<<vec.size()<<endl<<endl;

    // Deleting the second row (index 1)
    //vec.erase(vec.begin() + 1);

    // Deleting the second element (index 1) from the second row (index 1)
    //vec[1].erase(vec[1].begin() + 1);

    vector<int> v3={1,2,1,3};
    cout<<"v3 vector : ";
    disp(v3);

    replace(v3.begin(),v3.end(),1,5); // begin it, end it, old_value, new_value
    cout<<"v3 after replace() : ";
    disp(v3);

    sort(v3.begin(),v3.end()); // begin it, end it
    cout<<"v3 after sort() : ";
    disp(v3);

    cout<<endl;

    vector<int> v4={1,2,5,4,3,2};
    cout<<"v4 : ";
    auto it=find(v4.begin(),v4.end(),5);
    if(it==v4.end()){
        cout<<"Value not found"<<endl;
    }
    else{
        cout<<"Value found"<<endl;
    }
}