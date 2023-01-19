///Hough Circle Transform

//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include <iostream>
//using namespace cv;
//using namespace std;
//int main(int argc, char** argv)
//{
//    const char* filename = argc >= 2 ? argv[1] : "1_test.png";
//    // Loads an image
//    Mat src = imread(samples::findFile(filename), IMREAD_COLOR);
//    // Check if image is loaded fine
//    if (src.empty()) {
//        printf(" Error opening image\n");
//        printf(" Program Arguments: [image_name -- default %s] \n", filename);
//        return EXIT_FAILURE;
//    }
//    Mat gray;
//    cvtColor(src, gray, COLOR_BGR2GRAY);
//    medianBlur(gray, gray, 5);
//    vector<Vec3f> circles;
//    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
//        gray.rows / 3,  // change this value to detect circles with different distances to each other
//        100, 30, 0.1, 500 // change the last two parameters
//   // (min_radius & max_radius) to detect larger circles
//    );
//    for (size_t i = 0; i < circles.size(); i++)
//    {
//        Vec3i c = circles[i];
//        Point center = Point(c[0], c[1]);
//        // circle center
//        circle(src, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
//        // circle outline
//        int radius = c[2];
//        circle(src, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
//        cout << "center" << center.x << ", " << center.y << endl;
//    }
//    imshow("detected circles", src);
//    waitKey();
//    return EXIT_SUCCESS;
//}

///Circle Detection

//#include<opencv2/opencv.hpp>//OpenCV header to use VideoCapture class//
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgproc.hpp"
//#include<iostream>
//using namespace std;
//using namespace cv;
//int main(int argc, char** argv)
//	{
//	VideoCapture cap(0);
//
//	while (true)
//	{
//		Mat frame;
//		cap >> frame;
//		Mat gray;
//		cvtColor(frame, gray, COLOR_BGR2GRAY);
//		medianBlur(gray, gray, 5);
//
//		vector<Vec3f> circles;
//		HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 16, 100,
//			30, 1, 30);
//
//		for (size_t i = 0; i < circles.size(); i++)
//		{
//			Vec3i c = circles[i];
//			Point center = Point(c[0], c[1]);
//			// circle center
//			circle(frame, center, 1, Scalar(0, 100, 100), 3, cv::LINE_AA);
//			//circle outline
//			int radius = c[2];
//			circle(frame, center, radius, Scalar(255, 0, 255), 3, cv::LINE_AA);
//		}
//	imshow("Detection on circle", frame);
//    waitKey(5);
//	}
//
//    return EXIT_SUCCESS;
//}







#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
//int main(int argc, char** argv)
//{
//    Mat dst, cdst, cdstP;
//    const char* default_file = "1_test.png";
//    const char* filename = argc >= 2 ? argv[1] : default_file;
//   
//    Mat src = imread(samples::findFile(filename), IMREAD_GRAYSCALE);
//
//    if (src.empty()) {
//        printf(" Error opening image\n");
//        printf(" Program Arguments: [image_name -- default %s] \n", default_file);
//        return -1;
//    }
//     
//    Canny(src, dst, 50, 160, 3);
//    cvtColor(dst, cdst, COLOR_GRAY2BGR);
//    cdstP = cdst.clone();
//    vector<Vec2f> lines; // will hold the results of the detection
//    HoughLines(dst, lines, 1, CV_PI / 180, 100, 0, 0); // runs the actual detection
//    for (size_t i = 0; i < lines.size(); i++)
//    {
//        float rho = lines[i][0], theta = lines[i][1];
//        Point pt1, pt2;
//        double a = cos(theta), b = sin(theta);
//        double x0 = a * rho, y0 = b * rho;
//        pt1.x = cvRound(x0 + 1000 * (-b));
//        pt1.y = cvRound(y0 + 1000 * (a));
//        pt2.x = cvRound(x0 - 1000 * (-b));
//        pt2.y = cvRound(y0 - 1000 * (a));
//        line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
//    }
//
//    vector<Vec4i> linesP; // will hold the results of the detection
//    HoughLinesP(dst, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection
//    for (size_t i = 0; i < linesP.size(); i++)
//    {
//        Vec4i l = linesP[i];
//        line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
//    }
//    imshow("Source", src);
//    imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
//
//       imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
//       waitKey();
//    const char* filename2 = argc >= 2 ? argv[1] : "1_test.png";
//    
//    Mat src2 = imread(samples::findFile(filename2), IMREAD_COLOR);
//
//    if (src2.empty()) {
//        printf(" Error opening image\n");
//        printf(" Program Arguments: [image_name -- default %s] \n", filename2);
//        return EXIT_FAILURE;
//    }
//    Mat gray;
//    cvtColor(src2, gray, COLOR_BGR2GRAY);
//    medianBlur(gray, gray, 5);
//    vector<Vec3f> circles;
//    HoughCircles(gray, circles, HOUGH_GRADIENT, 1,
//        gray.rows / 3,  // change this value to detect circles with different distances to each other
//        100, 30, 0.1, 500 // change the last two parameters
// 
//    );
//    for (size_t i = 0; i < circles.size(); i++)
//    {
//        Vec3i c = circles[i];
//        Point center = Point(c[0], c[1]);
//    
//        circle(src2, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
//   
//        int radius = c[2];
//        circle(src2, center, radius, Scalar(255, 0, 255), 3, LINE_AA);
//        cout << "center" << center.x << ", " << center.y << endl;
//    }
//    imshow("detected circles", src2);
//    waitKey();
//    return 0;
//}



#include "strategy.h"
#include <string>
using namespace std;



int main(int argc, char** argv)
{
	//Select_file new_file;
	//new_file.file_scr();
	bool stop = 1;
	while(stop)
	{ 
	Strategy_Selector ver;
	ver.select_strategy();
	Line new_line(ver.strategy, ver.Image_path);
	Circle new_circle(ver.strategy, ver.Image_path, new_line.lines_);
	Winner winner;
	winner.print_winner( new_circle.source, new_circle.caps_position, new_circle.strategy_circle);
	std::cout << "Next pictures \n PRESS ANY KEY \n QUIT PRESS 0 >>" << endl;
	std::cin >> stop;
	}
	return 0;
}