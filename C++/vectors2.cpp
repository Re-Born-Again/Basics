#include<iostream>
#include<vector>
using namespace std;

void disp_vec(vector<vector<int>> vect){
    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> vect={{1,2},
                              {3,4,5},
                              {6,7,8,9}}; // no need to initialise also as vectors are vectors!
    disp_vec(vect);
    
    vect.push_back({10,11,12,13,14});
    disp_vec(vect);
   
    vect[3].pop_back();
    disp_vec(vect);

    vect[4].push_back(1); // doesnt work as expected as there is not even a single element in vect[4]
    disp_vec(vect);

    vect.push_back({2,2,2});
    disp_vec(vect);

    vect[4].push_back(1); // now we can push as there are elements present in vect[4]
    disp_vec(vect);

    vect.erase(vect.begin()+2);
    disp_vec(vect);

}