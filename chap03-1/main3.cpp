// **********************************************
// 제 목 : 과제3
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
    Rect r1(10, 10, 20, 20);
    Point p1(15, 15);

    // contains 함수 사용
    if (r1.contains(p1)) {  //-> 점 p1이 사각형 r1 내부에 있으면 true 반환
        cout << "점 p1은 사각형 r1 내부에 존재한다." << endl;
    }
    else {
        cout << "점 p1은 사각형 r1 외부에 존재한다." << endl;
    }

    return 0;
}