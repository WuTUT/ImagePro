#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
using namespace cv;
using namespace std;

string Cascade_mode ="/home/wu/MLData/harrdata/cascade.xml";


CascadeClassifier Mycascade;
string window_name = "test";
Mat detectAndDisplay( Mat frame);
String videofilename="/home/wu/fujian3.avi";
int main()
{
    VideoCapture capture(videofilename);
    if(!capture.isOpened())
        cout<<"error"<<endl;
    double rate = capture.get(CV_CAP_PROP_FPS);
    cout<<"帧率为:"<<rate<<endl;
    while(1){
        Mat image,ROI;

        if(!Mycascade.load( Cascade_mode ))  { printf("[error] 无法加载级联分类器文件！\n");   return -1;    }

        capture>>image;


        if(!image.data)  {   printf("[error] 没有图片\n");   return -5;  }
        ROI= detectAndDisplay(image);
       waitKey(30);
    }

    waitKey(0);
    return 0;
}

Mat detectAndDisplay( Mat frame)
{
    std::vector<Rect> pedestrain;
    Mat frame_gray(frame.size(),CV_8U);
    cvtColor( frame, frame_gray, CV_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

   // Mycascade.detectMultiScale( frame_gray, pedestrain, 1.1, 5, 0, Size(40,40),Size(70,70) );//test small samples high
  //Mycascade.detectMultiScale( frame_gray, pedestrain, 1.1, 5, 0, Size(40,40),Size(120,120) );//test big samples low
   Mycascade.detectMultiScale( frame_gray, pedestrain, 1.1, 3, 0, Size(40,40),Size(120,120) );
    for( int i = 0; i < pedestrain.size(); i++ )  {
        rectangle(frame,
                  pedestrain[i],
                  Scalar(0, 255, 0),
                  1);

       cout <<((pedestrain[i]).x)<<endl;
    }
  imshow( window_name, frame );
  return frame;
}





