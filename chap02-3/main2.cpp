#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    string files[3] = { "video1.mp4", "video2.mp4", "video3.mp4" };
    VideoCapture cap[3];

    for (int i = 0; i < 3; i++) {
        cap[i].open(files[i]);
        if (!cap[i].isOpened()) {
            cout << "영상 열기 실패" << endl;
            return -1;
        }
    }

    Mat frame;
    namedWindow("video", WINDOW_AUTOSIZE);

    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 30; j++)   // 약 1초 재생
            {
                cap[i] >> frame;    //프레임 읽기
                if (frame.empty()) break;   //영상 끝 확인
                imshow("video", frame); //화면 출력
                if (waitKey(33) >= 0) return 0; //1000mx%33=30 프레임 이므로 영상이 자연스럽게 움직임
            }
        }
    }

    return 0;
}