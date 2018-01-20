#ifndef FACE_DEMO_H_
#define  FACE_DEMO_H_
#include "common.h"
#include "RecordModule.h"
#include "CLMTrackingModule.h"
#include "WarpingModule.h"

class CFaceDemo {
public: 
	CFaceDemo();
    CFaceDemo(InputMode _mode, string _fileName);
	~CFaceDemo();
	Mat Texture();
	Mat Depth() { return m_warpModule->Z(); }
	void Transform(Mat& _ar, Mat& _H, Point2d& _t) { m_warpModule->Transform(_ar, _H, _t); }
	Size ImageSize();

private: 
	void Clear();
	void ReadConfig(string _fName);
	void Init();

private:
	InputMode m_inputMode;
	string m_fileName; 
	Mat m_inputImg; 
	Mat m_imgTexture; 
	CRecordModule* m_recorder;
	CWarpingModule* m_warpModule;
	CCLMTrackingModule* m_tracker; 
	vector<PointSetd> m_recentPnts; 
};


#endif
