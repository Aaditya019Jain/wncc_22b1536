#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool f(unordered_map<string, vector<int>>& students, const string& project, const string& rollNumber) {
    vector<int>& skills = students[rollNumber];
    for (auto& student : students) {
        if (student.first != rollNumber && student.second == skills) {
            if (student.first == rollNumber)
                return true;
        }
    }
    return false;
}

int main() {
    unordered_map<string, vector<int>> students;
    unordered_set<string> jp; 
    int n, m;
    cout << "Number of students: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string rn;
        vector<int> sl(5);
        cout << "Enter student's roll number followed by skill levels (HTML, Python, DSA, Java, SQL): ";
        cin >> rn;
        for (int j = 0; j < 5; j++) {
            cin >> sl[j];
        }
        students[rn] = sl;
    }
    
    int cp = 0;
    cout << "number of projects: ";
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        string projectName;
        vector<int> a(5);
   
        cout << "project name: ";
        cin >> projectName;
        cout << "required skill levels (HTML, Python, DSA, Java, SQL): ";
        for (int j = 0; j < 5; j++) {
            cin >> a[j];
        }
        bool projectCompleted = true;
        
        for (int j = 0; j < 5; j++) {
            int skillRequired = a[j];
            if (skillRequired == 0) {
                continue;
            }
            bool sk = false;
            
            for (auto& student : students) {
                string rollNumber = student.first;

                if (jp.count(rollNumber) > 0)
                    continue;
                
                if (student.second[j] >= skillRequired) {
                    sk = true;
                    jp.insert(rollNumber); 
                    break;
                } else if (student.second[j] == skillRequired - 1) {
                    if (f(students, projectName, rollNumber)) {
                        sk = true;
                        jp.insert(rollNumber); 
                        break;
                    }
                }
            }
            
            if (!sk) {
                projectCompleted = false;
                break;
            }
        }
        
        if (projectCompleted) {
            cp++;
        }
    }
    
    cout << "Total completed projects: " << cp << endl;
    
    return 0;
}
