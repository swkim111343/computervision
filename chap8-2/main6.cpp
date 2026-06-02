// **********************************************
// 제 목 : 실습과제6
// 날 짜 : 2026년 6월 2일
// 작성자 : 2001485 김선우
// **********************************************
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture cap(1);

    if (!cap.isOpened()) {
        cerr << "Camera open failed!" << endl;
        return -1;
    }

    Mat frame, dst;
    char mode = 'a';

    while (true)
    {
        cap >> frame;

        if (frame.empty())
            break;

        if (mode == 'a')
        {
            dst = frame.clone();
        }
        else if (mode == 'b')
        {
            double sx = 0.5;
            double sy = 0.5;

            double tx = frame.cols / 4.0;
            double ty = frame.rows / 4.0;

            Mat M = (Mat_<double>(2, 3) <<
                sx, 0, tx,
                0, sy, ty);

            warpAffine(
                frame,
                dst,
                M,
                frame.size(),
                INTER_LINEAR,
                BORDER_CONSTANT
            );
        }

        imshow("Video", dst);

        // 반복문 안에서 waitKey는 1번만 호출
        int key = waitKey(30);

        if (key == 'a')
            mode = 'a';
        else if (key == 'b')
            mode = 'b';
        else if (key == 'q')
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}