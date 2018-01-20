#ifndef RECORD_MODULE_H_
#define RECORD_MODULE_H_
#include "common.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

enum InputMode {
    IM_IMAGE,
    IM_VIDEO,
};

class CRecordModule {
public: 
	CRecordModule(); 
	CRecordModule(string _videoFile); 
	~CRecordModule();
	bool IsOpened(); 
	Mat GetFrame(); 
	Size GetFrameSize(); 

private: 
	void Clear(); 
private: 
	VideoCapture m_cap; 
	Size m_size; 
	Mat m_lastFrame;
}; 

#endif //RECORD_MODULE_H_
