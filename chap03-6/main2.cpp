// **********************************************
// 제 목 : 과제2
// 날 짜 : 2026년 4월1일
// 작성자 : 2001485 김선우
// **********************************************
// 소스코드 작성
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    // 행렬 정의 (2x2, float)
    Mat A = (Mat_<float>(2, 2) << 1, 3, -4, 2);
    Mat B = (Mat_<float>(2, 2) << 2, 3, 0, 5);
    Mat C = (Mat_<float>(2, 2) << -2, -2, -2, -3);

    // B의 역행렬
    Mat B_inv = B.inv();

    // X 계산
    Mat X = 3 * A + B_inv + 10 * C - 5;

    // 결과 출력
    cout << "행렬 X:\n" << X << endl;

    return 0;
}