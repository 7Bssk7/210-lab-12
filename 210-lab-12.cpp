#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <fstream>
using namespace std;

const int SIZE = 40, MISSED_EXAM = 0;

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
    array<int, SIZE>::iterator found = find(list.begin(), list.end(), MISSED_EXAM); 

    cout << "CLASS 1241A" << "\n" << endl;
    cout << "Number of student: " << list.size()<< endl;
    cout << "List of all grades for the exam 1: " << endl;
    for(int gr : list ) cout << gr << " "; cout << endl;
    cout << "Grade of the very first student in the list" << list.front() << endl;
    cout << "Grade of the very last student in the list" << list.back() << endl;
    cout << "Did the entire class miss the exam?" << endl;
    cout << (list.empty() == 0? "No" : "Yes" ) << endl;
    cout << "Did any of the student miss the exam?(some one got a grade of 0)" << endl;
    cout << (found != list.end()? "Yes, unfortunately at least one student missed the exam." : "No, none of the students missed the exam.") << endl;
    cout << "Sorted list of the grades from lowest to highest: " << endl;
    sort(list.begin(), list.end());
    for(int gr : list) cout << gr << " "; cout << endl; 
    cout << "And here is the list of grades from highest to lowest: " <<endl;
    sort(list.rbegin(), list.rend());
    for(int gr : list) cout << gr << " "; cout << endl;
    cout << "Highest grade recieved on the exam: " << *max_element(list.begin(), list.end()) << endl;
    cout << "Lowest grade recieved on the exam: " << *min_element(list.begin(), list.end()) << endl;
    cout << "Class average on the exam(the nearest whole number): " << ((accumulate(list.begin(), list.end(), 0)) / SIZE) << endl;

}