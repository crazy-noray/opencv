#include"people.h"

void colorSpaceTrans(Mat frame,Mat &gray)
{
    cvtColor(frame,gray,COLOR_BGR2HLS);
    cvtColor(gray,gray,CV_BGR2GRAY);
}

Mat dealFrameDiff(Mat gray,Mat backFrame)
{
    Mat foreFrame,foreFrame_TH;
    Canny(gray,gray,180,255,3);
    absdiff(gray,backFrame,foreFrame);
    threshold(gray,foreFrame_TH,220,255,THRESH_BINARY);
    normalize(foreFrame_TH,foreFrame_TH,0,255,NORM_MINMAX,CV_8UC1);
    return foreFrame_TH;
}

void before(Mat &back)
{
    int erosion_size = 4;
    int dilation_size = 8;
    
    Mat ErodeElement =
            getStructuringElement( MORPH_RECT,
                                  Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                                  Point( erosion_size, erosion_size ) );
    Mat DilateElement =
            getStructuringElement( MORPH_RECT,
                                   Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                   Point( dilation_size, dilation_size ) );
    int erosion_size1 = 6;
    Mat ErodeElement1 =
            getStructuringElement( MORPH_RECT,
                                  Size( 2*erosion_size1 + 1, 2*erosion_size1 + 1 ),
                                  Point( erosion_size1, erosion_size1 ) );
    erode(back,back,ErodeElement1);
    for(int i = 0;i<=5;i++)
    {
        medianBlur(back,back,3);

        dilate(back,back,DilateElement);
        erode(back,back,ErodeElement);
    }

}
