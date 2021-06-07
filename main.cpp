#include <iostream>
#include <opencv4/opencv2/opencv.hpp>         

std::vector asciiChars = {'@', '#', '8', 'S', '%', '?', '*', '+', ';', ',', '.'};

const double asciiConst = 260/asciiChars.size();

int main(int argc, char** argv){

    cv::Mat frame;

    cv::VideoCapture vid(0);
    vid.set(cv::CAP_PROP_FPS, 30);

    if(!vid.isOpened()){
        return -1;
    }
    while(vid.read(frame)){
        // type is CV_8UC3
        int width = frame.cols;
        int height = frame.rows;

        // for( int j = 20 ; j < height ; j+=2){
        //     std::string ascii = "";
        //     for( int i = 0 ; i < width ; i+=2){
        //         auto pixel1 = (frame.at<cv::Vec3b>(j,i)[0]*(0.114))
        //             + (frame.at<cv::Vec3b>(j,i)[1]*(0.587))
        //             + (frame.at<cv::Vec3b>(j,i)[2]*(0.299));
        //         auto pixel2 = (frame.at<cv::Vec3b>(j+1,i)[0]*(0.114))
        //             + (frame.at<cv::Vec3b>(j+1,i)[1]*(0.587))
        //             + (frame.at<cv::Vec3b>(j+1,i)[2]*(0.299));
        //         auto pixel3 = (frame.at<cv::Vec3b>(j,i+1)[0]*(0.114))
        //             + (frame.at<cv::Vec3b>(j,i+1)[1]*(0.587))
        //             + (frame.at<cv::Vec3b>(j,i+1)[2]*(0.299));
        //         auto pixel4 = (frame.at<cv::Vec3b>(j+1,i+1)[0]*(0.114))
        //             + (frame.at<cv::Vec3b>(j+1,i+1)[1]*(0.587))
        //             + (frame.at<cv::Vec3b>(j+1,i+1)[2]*(0.299));
        //         ascii += asciiChars[asciiChars.size() - 1 - floor(((pixel1+pixel2+pixel3+pixel4)/4)/asciiConst)];
        //     }
        //     std::cout << ascii << std::endl;
        // }
        // width = 640
        // height = 480
        cv::cvtColor(frame, frame, 0);
        

        


        


       cv::imshow("Webcam", frame);
       cv::waitKey(33);
    }

    return 0;
}