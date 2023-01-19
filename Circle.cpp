#include "strategy.h"



Circle::Circle()
{
}





Circle::Circle(int strategy_line, std::string image_path, std::vector<cv::Vec2f> lines) : strategy_circle(strategy_line)
	{
		cv::Mat source2 = cv::imread(cv::samples::findFile(image_path), cv::IMREAD_COLOR);
		    if (source2.empty()) {
		        printf(" Error opening image\n");
		    }
		    cv::Mat gray;
		    cvtColor(source2, gray, cv::COLOR_BGR2GRAY);
		    medianBlur(gray, gray, 5);
		    std::vector<cv::Vec3f> circles;
		    HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
		        gray.rows / 3,  // change this value to detect circles with different distances to each other
		        100, 30, 0.1, 500 // change the last two parameters
		    );
			int max_y = 0;
			int max_x = 0;
			int temp = 0;
			int border_x = 0;
			int border_y = 0;
			bool first = 1;
			std::vector<std::pair<int, int>> caps_position_;
		    for (size_t i = 0; i < circles.size(); i++)
		    {
		        cv::Vec3i c = circles[i];
		        cv::Point center = cv::Point(c[0], c[1]);
		        circle(source2, center, 1, cv::Scalar(0, 100, 100), 3, cv::LINE_AA);
		        int radius = c[2];
		        circle(source2, center, radius, cv::Scalar(255, 0, 255), 3, cv::LINE_AA);
		        std::cout << "center" << center.x << ", " << center.y << std::endl;
				caps_position_.push_back(std::make_pair(center.x, center.y));
				if (strategy_line == 1)
				{
					
					for (size_t i = 0; i < lines.size(); i++)
					{
					  if(lines[i][0] < center.x)
					  { 
						  if (first)
						  {
							  max_y = center.y;
							  max_x = center.x;
							  
							  first = false;
						  }
						if (center.y < max_y )
						{
							max_y = center.y;
							max_x = center.x;
						}
					  }
					}
				}
				else if (strategy_line == 2)
				{
					
					for (size_t i = 0; i < lines.size(); i++)
					{
						if (lines[i][1] < center.y)
						{
							if (first)
							{
								max_y = center.y;
								max_x = center.x;
								first = false;
							}
							if (center.x > max_x)
							{
								max_y = center.y;
								max_x = center.x;
							}
						}
					}
				}
			
		    }
		
	

		    cv::imshow("detected circles", source2);
			source = source2;
			winner_x = max_x;
			winner_y = max_y;
			caps_position = caps_position_;
		    cv::waitKey();
		   	 
	};



