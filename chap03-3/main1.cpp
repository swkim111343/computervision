// **********************************************
// 제 목 : 과제1
// 날 짜 : 2026년 3월24일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    //(2x2 행렬)이므로 2, 2이고 원소가 소수점이므로 자료형이 float이고 그 때문에 32비트F사용, 일반 숫자 행렬이므로 1채녈
    float data1[] = { 3.5, 2.1, -1.5, -6.5 };
    Mat mat1(2, 2, CV_32FC1, data1);

    //(3x3 행렬)이므로 3, 3이고 원소가 음수 포함 정수이므로 자료형이 int 이고 그 때문에 32비트S사용, 일반 숫자 행렬이므로 1채녈
    int data2[] = { 0, 2, -1, 5, 10, 8, 6, -7, 9 };
    Mat mat2(3, 3, CV_32SC1, data2);

    //(1x4 행렬)이므로 1, 4이고 원소가 정수이므로 자료형이 int 이고 그 때문에 32비트S사용, 일반 숫자 행렬이므로 1채녈
    int data3[] = { 1, 2, 3, 4 };
    Mat mat3(1, 4, CV_32SC1, data3);

    //(4x1 행렬)이므로 3, 3이고 원소가 정수이므로 자료형이 int 이고 그 때문에 32비트S사용, 일반 숫자 행렬이므로 1채녈
    int data4[] = { 5, 6, 7, 8 };
    Mat mat4(4, 1, CV_32SC1, data4);

    cout << "mat1 = " << endl << mat1 << endl << endl;
    cout << "mat2 = " << endl << mat2 << endl << endl;
    cout << "mat3 = " << endl << mat3 << endl << endl;
    cout << "mat4 = " << endl << mat4 << endl << endl;

    return 0;
}