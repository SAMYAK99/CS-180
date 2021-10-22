import cv2

# first import the image to check the image whether its checking or not

#img = cv2.imread('Lenna_(test_image).PNG')
# instead of doing the image we can do the code through the webacam
thres = 0.45

nms_threshold = 0.2
cam = cv2.VideoCapture(0)
cam.set(3,640)  # 3 is with
cam.set(4,480)  # 4 is for height
cam.set(10,70)  # this one is for brightness
 



classNames = []
classFile = 'coco.names'
with open(classFile, 'rt') as f:
    classNames = f.read().rstrip('\n').split('\n')
#print(classNames)

configPath = 'ssd_mobilenet_v3_large_coco_2020_01_14.pbtxt'
weightsPath = 'frozen_inference_graph.pb'

net = cv2.dnn_DetectionModel(weightsPath,configPath)
net.setInputSize(320 , 320)
net.setInputScale(1.0/127.5)
net.setInputMean((127.5 , 127.5 , 127.5))
net.setInputSwapRB(True)

# ot snd the image for predictions
a = 1
while True:
    a = a+1
    success , img = cam.read()
    classIds , confs , bbox = net.detect(img , confThreshold = thres)
    print(classIds , bbox)
    
    indices = cv2.dnn.NMSBoxes(bbox , confs ,thres , nms_threshold)
    print(classIds, bbox)
    
    

    if len(classIds)!=0:
        
        for classId , confidence , box in zip(classIds.flatten() , confs.flatten() , bbox):
            cv2.rectangle(img , box , color=(0 , 255 ,0),thickness = 2)
            cv2.putText(img , classNames[classId - 1].upper(),(box[0] + 10, box[1]+30),
                        cv2.FONT_HERSHEY_COMPLEX ,1,(255,255,255) , 2)
            cv2.putText(img , str(round(confidence * 100,2)),(box[0] + 200, box[1]+30),
                        cv2.FONT_HERSHEY_COMPLEX ,1,(255,255,255) , 2)
        
        
        cv2.imshow("Output",img)
        key = cv2.waitKey(1)
        if key == ord('q'):
            break
cv2.destroyAllWindows()
cam.release()