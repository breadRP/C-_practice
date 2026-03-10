#include <iostream>
#include <string>
using namespace std;

int main() {
    int studentCount = 0;
    cin >> studentCount;

    // TODO: read each student's name and score, then print the average and top student.
    int totalScore = 0;
    string topStudent;
    int topScore = -1;

    for (int i = 0; i < studentCount; ++i) {
        string name;
        int score;
        cin >> name >> score;
        totalScore += score;
        if (score > topScore) {
            topScore = score;
            topStudent = name;
        }
    }

    int averageScore = static_cast<double>(totalScore) / studentCount;
    cout << "Average: " << averageScore << endl;
    cout << "Highest: " << topStudent << " " << topScore << endl;

    return 0;
}