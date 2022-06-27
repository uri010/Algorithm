//
// Created by 김유리 on 2022/06/27.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string s, char Delimiter){
    istringstream iss(s);
    string buffer;
    vector<string>input;
    while(getline(iss,buffer,Delimiter)) {
        input.push_back(buffer);
    }
    return input;
}

int main (){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<pair<string, double> >grades;
    grades.push_back({"A+", 4.5});
    grades.push_back({"A0", 4.0});
    grades.push_back({"B+", 3.5});
    grades.push_back({"B0", 3.0});
    grades.push_back({"C+", 2.5});
    grades.push_back({"C0", 2.0});
    grades.push_back({"D+", 1.5});
    grades.push_back({"D0", 1.0});
    grades.push_back({"F", 0.0});
    string s;
    double total_num =0;
    double total_grade = 0;
    double grade =0;
    for(int i=0; i < 20; i ++){
        getline(cin,s);
        vector<string> input = split(s, ' ');
        if( input[2] == "P") continue;
        total_num += stod(input[1]);
        for(int j=0;j < 9; j++){
            if( input[2]== grades[j].first){
                grade = grades[j].second;
                break;
            }
        }
        total_grade += grade * stod(input[1]);
    }
    cout << total_grade/total_num;
}