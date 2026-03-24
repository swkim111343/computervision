// **********************************************
// 제 목 : 과제4
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
    //3채널 컬러 이미지
    Mat img(300, 400, CV_8UC3);

    int i = 0, key;

    while (true) //while 문을 사용하여
    {
        //Blue → Green → Red 반복
        if (i % 3 == 0) //i의 초기 값인 0대입하면 나머지가 0이므로 blue부터출력
            img = Scalar(255, 0, 0);   // Blue
        else if (i % 3 == 1)
            img = Scalar(0, 255, 0);   // Green
        else
            img = Scalar(0, 0, 255);   // Red

        imshow("img", img);

        key = waitKey(1000); // 1초마다반복
        if (key == 'q') break;  //q키를 누르면 break,(while문 종료)

        i++;    //색상 반복을 위해 1씩 증가하면서 while문 순환
    }

    return 0;
}