# -*- coding: utf-8 -*-

import cv2 
from PIL import Image
import time  


videoCapture = cv2.VideoCapture()
videoCapture.open('./test1.mp4')

fps = videoCapture.get(cv2.CAP_PROP_FPS)
frames = videoCapture.get(cv2.CAP_PROP_FRAME_COUNT)


for i in range(int(frames - 1)):
    ret,frame = videoCapture.read()
    height,width=frame.shape[:2]
    degree=90
    heightNew=int(width*fabs(sin(radians(degree)))+height*fabs(cos(radians(degree))))
    widthNew=int(height*fabs(sin(radians(degree)))+width*fabs(cos(radians(degree))))
    matRotation=cv2.getRotationMatrix2D((width/2,height/2),degree,1)
    matRotation[0,2] +=(widthNew-width)/2  
    matRotation[1,2] +=(heightNew-height)/2  
    imgRotation=cv2.warpAffine(frame,matRotation,(widthNew,heightNew),borderValue=(255,255,255))
    cv2.imwrite("./video_test/%d.jpg"%i,imgRotation)
    
    
    
