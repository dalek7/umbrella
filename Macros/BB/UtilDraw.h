#ifndef UTILDRAW_INCLUDED
#define UTILDRAW_INCLUDED


#include <opencv2/opencv.hpp>

using namespace cv;
namespace BB {

    // void circle(Mat& img, Point center, int radius, const Scalar& color, int thickness=1, int lineType=8, int shift=0)

	#ifndef draw_cross
	#define draw_cross( img, center, d, color, t )                                 \
						line( img,	Point( center.x - d, center.y - d ),                \
									Point( center.x + d, center.y + d ), color, t, 0 ); \
						line( img,	Point( center.x + d, center.y - d ),                \
									Point( center.x - d, center.y + d ), color, t, 0 )
	#endif


    #ifndef draw_plus
	#define draw_plus( img, center, d, color, t )                                 \
						line( img,	Point( center.x - d, center.y ),                \
									Point( center.x + d, center.y ), color, t, 0 ); \
						line( img,	Point( center.x , center.y - d ),                \
									Point( center.x , center.y + d ), color, t, 0 )
	#endif




}

#endif // UTILDRAW_INCLUDED
