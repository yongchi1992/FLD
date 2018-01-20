#include <cv.h>  
#include <cxcore.h>  
#include <highgui.h>  
#include <opencv2/opencv.hpp>

int main( int argc, char** argv )  
{  
        
    IplImage* pFrame = NULL;  
    IplImage* img;  
    
        
    CvCapture* pCapture = cvCreateCameraCapture(-1);  
    
        
    cvNamedWindow("video", 1);  
    CvVideoWriter *writer = NULL;  
    int isColor = 1;  
    int fps = 25;
    int frameW = 640; 
    int frameH = 480;  
        
    writer=cvCreateVideoWriter("out.avi",CV_FOURCC('X','V','I','D'),fps,cvSize(frameW,frameH),isColor);  
    
        
    while(1)  
    {  
        pFrame=cvQueryFrame( pCapture );  
        if(!pFrame)break;  
        cvShowImage("video",pFrame);  
        cvGrabFrame(pCapture); 
        img = cvRetrieveFrame(pCapture);
        cvWriteFrame(writer,img); 
        char c=cvWaitKey(33);  
        if(c==27)break;  
    }  
    cvReleaseImage(&pFrame);  
    cvReleaseImage(&img);  
    cvReleaseVideoWriter(&writer);  
    cvReleaseCapture(&pCapture);  
    cvDestroyWindow("video");  
}  
