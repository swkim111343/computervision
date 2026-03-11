#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv; 
using namespace std; 

int main()
{
    string files[10] = { "0.png","1.png","2.png","3.png","4.png",
                        "5.png","6.png","7.png","8.png","9.png" };   //숫자 이미지 파일 이름을 저장한 배열 (0~9)
    Mat img[10];

    for (int i = 0; i < 10; i++)
    {
        img[i] = imread(files[i]); 
        if (img[i].empty())
        {
            cout << "이미지 로드 실패" << endl;
            return -1;
        }
    }
    namedWindow("timer", WINDOW_AUTOSIZE);      //timer 생성

    while (true)    //초시계 반복문
    {
        for (int i = 0; i < 10; i++)
        {
            imshow("timer", img[i]); //이미지 출력
            waitKey(1000); // 1000ms = 1초 대기 (숫자가 1초마다 변경)
        }
    }
    return 0;
}