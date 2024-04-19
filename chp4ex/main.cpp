// chp4ex0.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream> //cin cout을 사용하기 위해
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include <fstream>//파일을 사용하기 위해

using namespace std;





// 중간시험 점수, 기말시험 점수, 과제 점수의 백터로
// 학생의 종합 점수를 가함.
// 이 함수는 인수를 복사하기 않고 median 함수가 해당 작업을 실행.




int main() {


    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    int i = 0;

    //학생 이름과 모든 점수를 읽어 저장하고
    //가장 긴 이름ㅇ르 찾음
    int maxlen;
    Student_info s;
    max(s.name.size(), maxlen);

    //학생 정보를 알파벳순으로 정렬
    sort(students.begin(), students.end(), compare);
    for (vector<Student_info>::size_type i = 0;
        i != students.size(); ++i) {


        //이름과 오른쪽 공백을 포함하여 maxlen + 1
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
    }
    // 종합 점수를 계산해 생성
    try {
        double final_grade = grade(students[i]);
        // 결과를 출력
        streamsize prec = cout.precision(); // 지금 cout precision
        cout << "Final grade: " << setprecision(3)
            << final_grade << setprecision(prec) << endl;
    }
    catch (domain_error e) {
        cout << e.what();

    }

    return 0;
} // main 끝
