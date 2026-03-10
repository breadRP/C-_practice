#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int studentCount = 0;
    cin >> studentCount;

    // TODO: read each student's name and score, then print the average and top student.
    vector<string> student;
    vector<int> student_score;
    
    for (int i=0; i<studentCount; i++)
    {
        string name;
        int score;
        
        cin >> name;
        cin >> score;
        
        student.push_back(name);
        student_score.push_back(score);
    }
    
    auto max_score = max_element(student_score.begin(), student_score.end());
    int index = max_score - student_score.begin();
    int sum = accumulate(student_score.begin(), student_score.end(), 0);
    int mean = static_cast<double>(sum) / studentCount;
    
    cout << "Average: " << mean << endl;
    cout << "Highest: " << student[index] << " " << *max_score;
    
    return 0;
}