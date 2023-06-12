# robot-picking-cigarette-butt-with-image-processing
In this project, object detection is done via Raspberry Pi by providing serial comminication Raspberry Pi and UNO. CPU is needed for image processing. Thus, Raspberry Pi 4B was choosen and camera is needed for taking real time video. Hereby, the camera module was choosen. In addition, there are some library handling image processing, object detection by training datas. In this project, tensorflow lite was used for training cigarette butt datas in Google Colab Platform. Because when compared between tensorflow, tensorflow lite, YOLO library with benchmark value. Tensorflow Lite gives high performance with high FPS and low temperature. The cigarette butt data which is image which have to be jpg to train. To sum up, serial commnication which is baud rate 115200 between Raspberry Pi and UNO is started. At that moment, the bounding box focus the object. If the object is cigarette butt, the data is sent from Raspberry Pi to UNO. When UNO takes the data, the conditions process. According to condition, robot is picked  cigarette butt.

![gif_için](https://user-images.githubusercontent.com/109728194/232320761-05414af1-77d6-410b-a31b-7ab0665aa322.gif)


The full version of the project will be pulished about one month. For now, object detection and serial comminication were published.




