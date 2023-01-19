#pragma once
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class Select_file
{
	public:
		std::string file_destination;
	    void file_scr();
};

class Strategy_Selector :Select_file
{
	public:
		int strategy;
		std::string Image_path;
		void select_strategy();
};

class Line:Strategy_Selector
{
	public:
		cv::Mat destination, cdst, cdstP, source;
		Line();
		int strategy_line;
		std::string image_path;
		std::vector<cv::Vec2f> lines_;
		Line(int strategy, std::string image_path);
};

class Circle:Line
{
	public:
		cv::Mat destination, cdst, cdstP, source;
		Circle();
		int strategy_circle;
		int winner_x,winner_y;
		std::vector<std::pair<int, int>> caps_position;
		Circle(int strategy_line, std::string image_path, std::vector<cv::Vec2f> lines);
};

class Winner :Circle
{
	public:

		void print_winner( cv::Mat source, std::vector<std::pair<int,int>> caps_position, int strategy);
};
