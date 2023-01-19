#include "strategy.h"


	void Strategy_Selector::select_strategy()
	{
		std::cout << "Image is Vertical or Horizontal?? \n";
		std::cout << "1. Image is Vertical \n";
		std::cout << "2. Image is Horizontal \n";
		std::cout << "Write ->>";
		std::cin >> strategy;
		// 1 - Vertical
		// 2 - Horizontal
		Select_file new_file;
		new_file.file_scr();
		Image_path = new_file.file_destination.c_str();
	
	};
