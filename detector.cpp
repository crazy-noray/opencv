
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int dete(Mat &dst){
    int people = 0;
    HOGDescriptor hog;

    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    //Hog处理人体检测
    vector<Rect> found, found_filtered;

    hog.detectMultiScale(dst, found, 0, Size(8,8), Size(32,32), 1.05, 2 );


    size_t i, j;
    for( i = 0; i < found.size(); i++ )
    {
        Rect r = found[i];
        for( j = 0; j < found.size(); j++ )
            if( j != i && (r & found[j]) == r)
                break;
        if( j == found.size() )
            found_filtered.push_back(r);
    }
    for( i = 0; i < found_filtered.size(); i++ )
    {
        Rect r = found_filtered[i];

        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);

       rectangle(dst, r.tl(), r.br(), cv::Scalar(0,255,0), 3);

       putText(dst,"1",Point(r.x+20,r.y+20),
           CV_FONT_HERSHEY_COMPLEX,1,Scalar(0,0,122));
      people++;
    }

   return people;
}

