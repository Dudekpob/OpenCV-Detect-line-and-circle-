#include "strategy.h"
typedef std::pair<int, int> pair;

		void Winner::print_winner(cv::Mat source, std::vector<std::pair<int,int>> c_position, int strategy) 
		{
		
			if (strategy == 1)
			{
					std::sort(c_position.begin(), c_position.end(),
						[](const pair& x, const pair& y) {
							if (x.second != y.second) {
								return x.second < y.second;
							}
							return x.first < y.first;
						});
				for (size_t i = 0; i < c_position.size(); i++)
				{
					cv::Point text_position(c_position[i].first, c_position[i].second);
					int font_size = 1;//Declaring the font size//
					cv::Scalar font_Color(0, 0, 0);//Declaring the color of the font//
					int font_weight = 5;//Declaring the font weight//
					cv::putText(source, //target image
						std::to_string(i+1), //text
						cv::Point(c_position[i].first, c_position[i].second), //top-left position
						cv::FONT_HERSHEY_DUPLEX,
						1.0,
						CV_RGB(118, 185, 0), //font color
						4);
				}
			}
			else if (strategy == 2)
			{
				std::sort(c_position.begin(), c_position.end());
				for (size_t i = 0; i < c_position.size(); i++)
				{
					cv::Point text_position(c_position[i].first, c_position[i].second);
					int font_size = 1;//Declaring the font size//
					cv::Scalar font_Color(0, 0, 0);//Declaring the color of the font//
					int font_weight = 5;//Declaring the font weight//
					cv::putText(source, //target image
						std::to_string(i + 1), //text
						cv::Point(c_position[i].first, c_position[i].second), //top-left position
						cv::FONT_HERSHEY_DUPLEX,
						1.0,
						CV_RGB(118, 185, 0), //font color
						4);
				}
			}
			else
			{
				std::cout << "Error"<<std::endl;
			}
	
			cv::imshow("Winner", source);//Showing the image//
			cv::waitKey(0);//Wait for Keystroke//
		};

	

