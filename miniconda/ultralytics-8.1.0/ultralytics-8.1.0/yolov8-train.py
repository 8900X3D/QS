from ultralytics import YOLO

          #从哪个模型训练起
model = YOLO('yolov8n.pt')

           #data是数据集的位置              epochs是训练多少轮  batch是根据显卡配置自己调整
model.train(data='yolo-bvn.yaml',workers=1,epochs=10,batch=16)


#命令行里使用yolo copy-cfg可以复制配置文件dafault.yaml
#使用yolo cfg=default_copy.yaml可以使用复制的配置文件  

