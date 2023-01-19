#include "strategy.h"


	Line::Line()
	{

	};

	Line::Line(int strategy, std::string image_path) : strategy_line(strategy) 
	{
		cv::Mat destination, cdst, cdstP;
		std::string image_p;
		for (size_t i = image_path.size()-1; i > 0; i--)
		{
			if (image_path[i] != '\\' || image_path[i] != 92)
				image_p += image_path[i];
			else
				break;
		}		
		reverse(image_p.begin(), image_p.end());
		image_path.erase(image_path.end() - image_p.size()-1, image_path.end());
		std::string final_path = image_path;
		cv::samples::addSamplesDataSearchPath(final_path);
		cv::samples::addSamplesDataSearchSubDirectory(final_path);
		const char* filename = image_p.c_str();
		cv::Mat test = cv::imread(filename, 1);
		if (test.empty()) {
			printf(" Error opening image\n");
		}
		
		cv::Mat source = cv::imread(cv::samples::findFile(filename), cv::IMREAD_GRAYSCALE);
		if (source.empty()) {
			printf(" Error opening image\n");
		}
		cv::resize(test, source, cv::Size(512, 512), cv::INTER_LINEAR);
		cv::Canny(source, destination, 50, 160, 3);
		cvtColor(destination, cdst, cv::COLOR_GRAY2BGR);
		cdstP = cdst.clone();
		std::vector<cv::Vec2f> lines; // will hold the results of the detection
		cv::HoughLines(destination, lines, 1, CV_PI / 180, 100, 0, 0); // runs the actual detection
			for (size_t i = 0; i < lines.size(); i++)
			{
				float rho = lines[i][0], theta = lines[i][1];
				cv::Point pt1, pt2;
				double a = cos(theta), b = sin(theta);
				double x0 = a * rho, y0 = b * rho;
				pt1.x = cvRound(x0 + 1000 * (-b));
				pt1.y = cvRound(y0 + 1000 * (a));
				pt2.x = cvRound(x0 - 1000 * (-b));
				pt2.y = cvRound(y0 - 1000 * (a));
				line(cdst, pt1, pt2, cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
			}
		std::vector<cv::Vec4i> linesP; // will hold the results of the detection
		HoughLinesP(destination, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection
			for (size_t i = 0; i < linesP.size(); i++)
			{
				cv::Vec4i l = linesP[i];
				line(cdstP, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 3, cv::LINE_AA);
			}
	
		cv::imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
		cv::waitKey();
		lines_ = lines;
	};

