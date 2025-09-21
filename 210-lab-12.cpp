// COMSC 210 | Lab 12 | Arkhip Finski
// IDE used: Visual Studio

#include <iostream>
#include <algorithm> // for sort(), find, max_element(), min_element
#include <numeric> // for accumulate()
#include <array> // for std::array
#include <fstream> // for file input
using namespace std;

const int SIZE = 40, MISSED_EXAM = 0;

//Function prototype
void outputArray(array<int, SIZE>);

int main(){
    ifstream inputFile("grades.txt");
    array<int, SIZE> grades;
    int temp, i = 0;

    //Check if file is open and read grades into the array
    if(inputFile.is_open()){
        while(inputFile >> temp){
            grades[i] = temp; //store grade in array
            ++i;
        }
        inputFile.close(); // Closes file after reading all of the data
    }
    else{
        cout << "Error, file is not opening "<< endl;

        return 1;
    }
    //Calls function to output all array information
    outputArray(grades);

    return 0;
}

//This function outputs all information from the array(grades in the class)
//Argument: array of grades of data type int and size "SIZE"
//This is a void function(no return)
void outputArray(array<int, SIZE> list){
    //Iterator to check if any students missed the exam and received grade of 0
    array<int, SIZE>::iterator found = find(list.begin(), list.end(), MISSED_EXAM); 
 
    cout << "CLASS 1241A" << "\n" << endl;
    //Output the number of students in the class
    cout << "Number of students: " << list.size()<< endl;
    //Output all grades stored in the array   
    cout << "List of all grades for the exam 1: " << endl;
    for(int gr : list ) cout << gr << " "; cout << endl;
    //Output grades of the first and last student's grade  
    cout << "Grade of the very first student in the list: " << list.front() << endl;
    cout << "Grade of the very last student in the list: " << list.back() << endl;
    //Check if array is empty(if all students missed the exam)
    cout << "Did the entire class miss the exam?" << endl;
    cout << (list.empty() == 0? "No" : "Yes" ) << endl;
    //Check if at least one student missed the exam and received grade of 0
    cout << "Did any of the student miss the exam?(someone got a grade of 0)" << endl;
    cout << (found != list.end()? "Yes, unfortunately at least one student missed the exam." : "No, none of the students missed the exam.") << endl;
    //Sort array of grades from lowest to highest
    cout << "Sorted list of the grades from lowest to highest: " << endl;
    sort(list.begin(), list.end());
    for(int gr : list) cout << gr << " "; cout << endl; 
    //Sort array of grades from highest to lowest
    cout << "And here is the list of grades from highest to lowest: " <<endl;
    sort(list.rbegin(), list.rend());
    for(int gr : list) cout << gr << " "; cout << endl;
    //Output highest and lowest grade received on the exam
    cout << "Highest grade received on the exam: " << *max_element(list.begin(), list.end()) << endl;
    cout << "Lowest grade received on the exam: " << *min_element(list.begin(), list.end()) << endl;
    //Compute and output class average(nearest whole number)
    cout << "Class average on the exam(nearest whole number): " << ((accumulate(list.begin(), list.end(), 0)) / SIZE) << endl;

}