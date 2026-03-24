// **********************************************
// 제 목 : 과제5
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
    //400x400 흑백 이미지생성(그레이스케일 c1사용)
    Mat img(400, 400, CV_8UC1, Scalar(0));

    int gray = 0;   //현재 밝기값 검저으로 초기화
    int dir = 1;    // 방향(1: 증가, -1: 감소)

    while (true)
    {
        img = Scalar(gray); //이미지 전체를 gray값으로 채움
        imshow("img", img); 

        char key = waitKey(5); // 5msec마다
        if (key == 'q') break;  //q누르면종료

        //그레이 레벨 밝기 값을 1은 증가 -1 은감소
        gray += dir;

        //255에 도달하면 감소로 전환, 0에 도달하면 증가로 전환
        if (gray == 255 || gray == 0)
            dir *= -1;  //방향바꾸기
    }

    return 0;
}