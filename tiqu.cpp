#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int nump = 364;
int numn = 872;
Mat org,dst,img,tmp;
string filename="lena.jpg";
/*

int pic_size = 40;//截取图片宽高度

void on_mouse(int event,int x,int y,int flags,void *ustc)//event鼠标事件代号，x,y鼠标坐标，flags拖拽和键盘操作的代号
{
    static Point pre_pt(-1,-1);//初始坐标
    static Point cur_pt(-1,-1);//实时坐标
    char temp[16];
    if (event == CV_EVENT_LBUTTONDOWN)//左键按下，读取初始坐标，并在图像上该点处划圆
    {
        org.copyTo(img);//将原始图片复制到img中
        sprintf(temp,"(%d,%d)",x,y);
        pre_pt = Point(x,y);
        putText(img,temp,pre_pt,FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,0,255),1,8);//在窗口上显示坐标
        circle(img,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);//划圆
        imshow("img",img);
    }
    else if (event == CV_EVENT_MOUSEMOVE && !(flags & CV_EVENT_FLAG_LBUTTON))//左键没有按下的情况下鼠标移动的处理函数
    {
        img.copyTo(tmp);//将img复制到临时图像tmp上，用于显示实时坐标
        sprintf(temp,"(%d,%d)",x,y);
        cur_pt = Point(x,y);
        putText(tmp,temp,cur_pt,FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,0,255));//只是实时显示鼠标移动的坐标
        imshow("img",tmp);
    }
    else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON))//左键按下时，鼠标移动，则在图像上划矩形
    {
        img.copyTo(tmp);
        sprintf(temp,"(%d,%d)",x,y);
        cur_pt = Point(x,y);
        putText(tmp,temp,cur_pt,FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,0,255));
        rectangle(tmp,pre_pt,cur_pt,Scalar(0,255,0,0),1,8,0);//在临时图像上实时显示鼠标拖动时形成的矩形
        imshow("img",tmp);
    }
    else if (event == CV_EVENT_LBUTTONUP)//左键松开，将在图像上划矩形
    {
        org.copyTo(img);
        sprintf(temp,"(%d,%d)",x,y);

       // cur_pt.x = pre_pt.x + pic_size;
        //cur_pt.y = pre_pt.y + pic_size;
        cur_pt = Point(x,y);  //如果要自定义绘制截图大小，这句话就可以,因为截取样本需要固定大小，所以这里不用

        putText(img,temp,cur_pt,FONT_HERSHEY_SIMPLEX,0.5,Scalar(0,0,0,255));
        circle(img,pre_pt,2,Scalar(255,0,0,0),CV_FILLED,CV_AA,0);
        rectangle(img,pre_pt,cur_pt,Scalar(0,0,255,0),1,8,0);//根据初始点和结束点，将矩形画到img上
        //imshow("lena.jpg",img);
        img.copyTo(tmp);
        //截取矩形包围的图像，并保存到dst中
        int width = abs(pre_pt.x - cur_pt.x);
        int height = abs(pre_pt.y - cur_pt.y);
        if (width == 0 || height == 0)
        {
            printf("width == 0 || height == 0");
            return;
        }
        dst = org(Rect(min(cur_pt.x,pre_pt.x),min(cur_pt.y,pre_pt.y),width,height));
        namedWindow("dst");

       cvtColor(dst,dst,CV_BGR2GRAY);

       imshow("dst",dst);

        if (waitKey(0) == 's')
        {
            stringstream ss;
            string str;
            if(waitKey(0)=='p'){
                ss << "samples/pos/"<<nump << ".png";
                ss >> str;
                resize(dst,dst,Size(20,20),0,0,INTER_LINEAR);
                cout<<dst.size<<endl;
                imwrite(str, dst);
                nump++;
                 cout << "保存图片" << str << endl;
            }

           else if(waitKey(0)=='n'){
                ss << "samples/neg/"<<numn << ".png";
                ss >> str;
               // resize(dst,dst,Size(20,20),0,0,INTER_LINEAR);
               // cout<<dst.size<<endl;
                imwrite(str, dst);
                numn++;
                 cout << "保存图片" << str << endl;
            }



        }
        else
        {
            cout << "不保存" << endl;
        }

    }
}

int main()
{
    org = imread(filename);
    org.copyTo(img);
    org.copyTo(tmp);
    namedWindow("img");//定义一个img窗口
    setMouseCallback("img",on_mouse,0);//调用回调函数
    imshow("img",img);

    while(waitKey(0)!='q'){}
   cout<<"nump="<<nump<<"  numn="<<numn<<endl;
    return 0;
}

/*int main(){
int j=895;
        for(int i=25;i<=48;i++)
        {
            string filename="";

         stringstream ssfile;
        stringstream ss;
                string str;
            Mat src;
            ssfile<<"fup3/"<<i<<".jpg";
            ssfile>>filename;
           src=imread(filename);

           ss << "samples/neg/"<<(j) << ".png";
                ss >> str;
                Mat dst;
            cvtColor(src,dst,CV_BGR2GRAY);
         cout<<filename<<"  "<<str<<endl;
                imwrite(str, dst);
                j++;
        }
        waitKey(0);
        return 0;
}

*/
