// **********************************************
// 제 목 : 과제2 
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
    Rect s1, s2; //사각형 클래스 객체선언
    int area1, area2;

    //입력
    cout << "첫번째 사각형의 폭, 높이 입력: ";
    cin >> s1.width >> s1.height;
    cout << "두번째 사각형의 폭, 높이 입력: ";
    cin >> s2.width >> s2.height;

    // 면적 계산
    area1 = s1.width * s1.height;
    area2 = s2.width * s2.height;
    //출력
    cout << "s1:[" << s1.width << "X " << s1.height << "]" << endl;
    cout << "s2:[" << s2.width << "X " << s2.height << "]" << endl;

    //출력
    cout << "s1의 면적 " << area1 << endl;
    cout << "s2의 면적 " << area2 << endl;

    return 0;
}