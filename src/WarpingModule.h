#ifndef WARPING_MODULE_H_
#define WARPING_MODULE_H_
#include "common.h"


class CWarpingModule {
public: 
	CWarpingModule(); 
	~CWarpingModule();
	void WarpToFrontalFace3D(const Mat& _img, const PointSetd& _pnts, bool _isWarp = true);
	Mat FrontalFace(); 
	PointSetd WarpedLandmark(); 
	Mat WarpFace(Mat _img);
	void Transform(Mat& _ar, Mat& _H, Point2d& _t) { _ar = m_ar.clone(); _H = m_H.clone();_t = m_t;}
	Mat Z()  { return m_Z; }
	Mat Warp2d() { return m_warp2d; }
	
private: 
	void Clear();

private: 
	Mat m_frontalFace;  // warped face
	Mat m_pnts3d;  // labeled 3d points
	Mat m_Z;      // 3d depth
	Size m_size; // 3d image size

	Mat m_ar;   // 3d warping
	Mat m_H;   // 2d warping
	Point2d m_t;  // translation
	Mat m_warp2d; 
};
#endif
