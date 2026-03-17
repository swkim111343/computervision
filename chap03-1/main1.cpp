// **********************************************
// 제 목 : 과제1
// 날 짜 : 2026년 3월17일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
#include <cmath>
using namespace cv;
using namespace std;

int main()
{
    Point pt1, pt2; //point 클래스 변수선언
    double dist;

    //입력받기
    cout << "첫번째 점의 x,y 좌표를 입력: ";
    cin >> pt1.x >> pt1.y;
    cout << "두번째 점의 x,y 좌표를 입력: ";
    cin >> pt2.x >> pt2.y;

    //두 점의 좌표 출력
    cout << "pt1:[" << pt1.x << ", " << pt1.y << "]" << endl;
    cout << "pt2:[" << pt2.x << ", " << pt2.y << "]" << endl;

    dist = norm(pt1 - pt2); //opencv의 norm함수 사용해서 거리 구하기
    cout << "두 점 사이의 거리: " << dist << endl;

    return 0;
}