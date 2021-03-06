#include <iostream>
#include <typeinfo>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

enum options
{
    sobel,
    prewitt
};

// Computes the x component of the gradient vector
// at a given point in a image.
// returns gradient in the x direction
int xGradient(cv::Mat image, int x, int y, int option)
{
    if (option == prewitt)
    {
        return image.at<uchar>(y - 1, x - 1) +
               image.at<uchar>(y, x - 1) +
               image.at<uchar>(y + 1, x - 1) -
               image.at<uchar>(y - 1, x + 1) -
               image.at<uchar>(y, x + 1) -
               image.at<uchar>(y + 1, x + 1);
    }
    if (option == sobel)
    {
        return image.at<uchar>(y - 1, x - 1) +
               2 * image.at<uchar>(y, x - 1) +
               image.at<uchar>(y + 1, x - 1) -
               image.at<uchar>(y - 1, x + 1) -
               2 * image.at<uchar>(y, x + 1) -
               image.at<uchar>(y + 1, x + 1);
    }
}

// Computes the y component of the gradient vector
// at a given point in a image
// returns gradient in the y direction

int yGradient(cv::Mat image, int x, int y, int option)
{
    if (option == prewitt)
    {
        return image.at<uchar>(y - 1, x - 1) +
               image.at<uchar>(y - 1, x) +
               image.at<uchar>(y - 1, x + 1) -
               image.at<uchar>(y + 1, x - 1) -
               image.at<uchar>(y + 1, x) -
               image.at<uchar>(y + 1, x + 1);
    }
    if (option == sobel)
    {
        return image.at<uchar>(y - 1, x - 1) +
               2 * image.at<uchar>(y - 1, x) +
               image.at<uchar>(y - 1, x + 1) -
               image.at<uchar>(y + 1, x - 1) -
               2 * image.at<uchar>(y + 1, x) -
               image.at<uchar>(y + 1, x + 1);
    }
}

int main(int argc, char *argv[])
{
    std::string name;
    name = "hi";
    int option;
    if (argc > 1)
    {
        if (argv[1] == "prewitt")
        {
            name = "Prewitt";
            option = prewitt;
        }
        else if (argv[1] == "sobel")
        {
            name = "Sobel";
            option = sobel;
        }
        else
        {
            name = "Sobel";
            option = sobel;
        }
    }
    else
    {
        name = "Sobel";
        option = sobel;
    }

    name += " edge detection";

    std::cout << typeid(*argv[0]).name() << " " << name << std::endl;

    cv::Mat frame, dst;

    cv::VideoCapture vid(0);
    vid.set(cv::CAP_PROP_FPS, 30);

    int count = 1;

    while (1)
    {
        //type is CV_8UC3
        vid.read(frame);
        int width = frame.cols;
        int height = frame.rows;

        int gx, gy, sum;

        cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

        dst = frame.clone();
        
        for (int y = 1; y < frame.rows - 1; y++)
        {
            for (int x = 1; x < frame.cols - 1; x++)
            {
                gx = xGradient(frame, x, y, option);
                gy = yGradient(frame, x, y, option);
                sum = abs(gx) + abs(gy);
                sum = sum > 255 ? 255 : sum;
                sum = sum < 0 ? 0 : sum;
                dst.at<uchar>(y, x) = sum;
            }
        }

        cv::imshow(argv[1], dst);
        cv::waitKey(33);
    }

    return 0;
}