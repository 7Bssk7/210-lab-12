#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

const int SIZE = 40;

int main(){
    ifstream inputFile("grades.txt");
    array<int, SIZE> grades;
    int temp, i = 0;

    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades[i] = temp;
            ++i;
        }
    }
    else{
        cout << "Error, file is not opening "<< endl;
    }



    return 0;
}