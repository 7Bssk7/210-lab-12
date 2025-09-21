#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

const int SIZE = 40;

void outputArray(array<int, SIZE>);

int main(){
    ifstream inputFile("grades.txt");
    array<int, SIZE> grades;
    int temp, i = 0;

    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades[i] = temp;
            ++i;
        }
        inputFile.close();
    }
    else{
        cout << "Error, file is not opening "<< endl;
    }
    outputArray(grades);

    return 0;
}

void outputArray(array<int, SIZE> list){

    cout << "CLASS 1241A" << "\n" << endl;
    cout << "Number of student: " << list.size()<< endl;
    cout << "List of all grades for the exam 1: " << endl;
    for(int gr : list ) cout << gr << " "; cout << endl;


}