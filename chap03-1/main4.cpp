// **********************************************
// 제 목 : 과제4
// 날 짜 : 2026년 3월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    Rect r;
    Point p;

    // 입력
    cout << "사각형의 좌측상단의 좌표를 입력하시오(x,y): ";
    cin >> r.x >> r.y;

    cout << "사각형의 폭,높이를 입력하시오(width, height): ";
    cin >> r.width >> r.height;

    cout << "점 P의 좌표를 입력하시오: ";
    cin >> p.x >> p.y;

    // inside 함수 사용
    if (p.inside(r)) {
        cout << "점 P는 사각형 안에 있다." << endl;
    }
    else {
        cout << "점 P는 사각형 밖에 있다." << endl;
    }

    return 0;
}