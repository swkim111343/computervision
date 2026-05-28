// **********************************************
// 제 목 : 실습과제4
// 날 짜 : 2026년 5월 28일
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

    int mode = 0;
    // 0 : 원본
    // 1 : 2배 확대
    // 2 : 1/2 축소

    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        // 원본 영상의 3개 점
        Point2f srcPts[3], dstPts[3];

        srcPts[0] = Point2f(0, 0);
        srcPts[1] = Point2f(frame.cols - 1, 0);
        srcPts[2] = Point2f(frame.cols - 1, frame.rows - 1);

        // 확대
        if (mode == 1)
        {
            dstPts[0] = Point2f(0, 0);

            dstPts[1] =
                Point2f((frame.cols - 1) * 2, 0);

            dstPts[2] =
                Point2f((frame.cols - 1) * 2, (frame.rows - 1) * 2);

            Mat M = getAffineTransform(srcPts, dstPts);

            warpAffine(frame, dst, M,
                Size(frame.cols * 2, frame.rows * 2));
        }

        // 축소
        else if (mode == 2)
        {
            dstPts[0] = Point2f(0, 0);

            dstPts[1] =
                Point2f((frame.cols - 1) / 2, 0);

            dstPts[2] =
                Point2f((frame.cols - 1) / 2, (frame.rows - 1) / 2);

            Mat M = getAffineTransform(srcPts, dstPts);

            warpAffine(frame, dst, M,
                Size(frame.cols / 2, frame.rows / 2));
        }

        // 원본 크기
        else
        {
            dst = frame.clone();
        }

        imshow("video", dst);

        char key = (char)waitKey(1);

        if (key == 'a')
            mode = 1;

        else if (key == 'b')
            mode = 2;

        else if (key == 'c')
            mode = 0;

        else if (key == 'q')
            break;
    }

    cap.release();
    destroyAllWindows();

    return 0;
}