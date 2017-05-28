//
//  UtilIO.h
//  HelloCV+GL
//
//  Created by Seung-Chan Kim on 5/26/17.
//  Copyright (c) 2017 Seung-Chan Kim. All rights reserved.
//

#ifndef HelloCV_GL_UtilIO_h
#define HelloCV_GL_UtilIO_h


#include <opencv2/opencv.hpp>

namespace BB
{
    inline static char WaitKey2()
    {
        char ch=0;
        while(!((ch & 0xEFFFFF) != 0))
        {
            ch = cv::waitKey();
        }
        return ch;
    }
    
    inline static void WaitSpecificKey(char key_allow=27) //ESC
    {
        while((cv::waitKey() & 0xEFFFFF) != key_allow);
    }
    
    
}

#endif
