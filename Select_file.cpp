//#include <windows.h>
//#include <string.h>
#include "strategy.h"
#include <string>


		void Select_file::file_scr() 
		{
            //OPENFILENAME ofn;       // common dialog box structure
            //wchar_t szFile[260];       // buffer for file name
            //HWND hwnd{};              // owner window
            //HANDLE hf;              // file handle

            //// Initialize OPENFILENAME
            //ZeroMemory(&ofn, sizeof(ofn));
            //ofn.lStructSize = sizeof(ofn);
            //ofn.hwndOwner = hwnd;
            //ofn.lpstrFile = szFile;
            //// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
            //// use the contents of szFile to initialize itself.
            //ofn.lpstrFile[0] = '\0';
            //ofn.nMaxFile = sizeof(szFile);
            //ofn.lpstrFilter = NULL;
            //ofn.nFilterIndex = 1;
            //ofn.lpstrFileTitle = NULL;
            //ofn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = NULL;
            //ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

            //// Display the Open dialog box. 

            //if (GetOpenFileName(&ofn) == TRUE)
            //    hf = CreateFile(ofn.lpstrFile,
            //        GENERIC_READ,
            //        0,
            //        (LPSECURITY_ATTRIBUTES)NULL,
            //        OPEN_EXISTING,
            //        FILE_ATTRIBUTE_NORMAL,
            //        (HANDLE)NULL);
            //std::wstring ws(szFile);
            //std::string file_destination_Copy(ws.begin(), ws.end());
            //file_destination = file_destination_Copy;
            std::cout << "\n Write File Path \n >> ";
            std::cin >> file_destination;
		};
