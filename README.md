# robot-picking-cigarette-butt-with-image-processing
In this project, object detection is done via Raspberry Pi by providing serial comminication Raspberry Pi and UNO. CPU is needed for image processing. Thus, Raspberry Pi 4B was choosen and camera is needed for taking real time video. Hereby, the camera module was choosen. In addition, there are some library handling image processing, object detection by training datas. In this project, tensorflow lite was used for training cigarette butt datas in Google Colab Platform. Because when compared between tensorflow, tensorflow lite, YOLO library with benchmark value. Tensorflow Lite gives high performance with high FPS and low temperature. The cigarette butt data which is image which have to be jpg to train. 1000 cigarette butts data are used to train model in this project. To sum up, serial commnication which is baud rate 115200 between Raspberry Pi and UNO is started. At that moment, the bounding box focus the object. If the object is cigarette butt, the data is sent from Raspberry Pi to UNO as shown below. When UNO takes the data, the conditions process. According to condition, robot is picked  cigarette butt.

![gif_için](https://user-images.githubusercontent.com/109728194/232320761-05414af1-77d6-410b-a31b-7ab0665aa322.gif)

# Training Model
The datas are labeled before training process. In this project 1000 cigarette butt image are labeled by labelIMG program as shown in image. The frame covering the cigarette butt is drawed then, it is labeled as cigarette_butt. After label process, each labeled image has XML document which consists of information of frame covering the image. For example, these are x and y coordinate, label name etc. The images are ready for training by using CNN

![label](https://github.com/yasinsulhan/robot-picking-cigarette-butt-with-image-processing/assets/109728194/1e7c5b2b-a07f-4818-971d-f594387df9ee)

In this project, deep learning has proved to be a very powerful tool because of its ability to handle large amounts of data. The interest to use hidden layers has surpassed traditional techniques, especially in pattern recognition. One of the most popular deep neural networks is Convolutional Neural Networks (also known as CNN or ConvNet) in deep learning, especially when it comes to computer vision applications. The application can be thought as in image . The pixel of image goes as input and this can be predicted into labeled form.

![cnn_tanıtım](https://github.com/yasinsulhan/robot-picking-cigarette-butt-with-image-processing/assets/109728194/8124060a-c7e2-42ad-9072-05493dfbc3be)

The labeled datas are trained over 40000 steps and 16 batch sizes. To be understood such words. Iteration, batch size epoch and number of steps must be evaluated togetger. The training set is splited into many batches. When run the the algorithm, it requires one epoch to analyze the full training set. An epoch is composed of many iterations (or batches). Iteration is the number of batches needed to complete one Epoch. Batch size is the number of training samples used in one iteration. Epoch is one full cycle through the training dataset. A cycle is composed of many iterations. Number of Steps per epoch is equal Total number of training samples are divided by batch size. The detailed information can be accessed from here [2].

After training, the result is evaluated by using graph and mAP (mean Average Precision) score. The loss of system decreases after steps. It shows that the system gets accuracy than first case. The graphs on the figure explains how the loss of the system decreases for trained model.

![1](https://github.com/yasinsulhan/robot-picking-cigarette-butt-with-image-processing/assets/109728194/56d55734-79be-4f66-bb01-f9130e394c19)

To be avoided for memorizing the average score must be between % 70 and % 75. Otherwise, the system goes memorizing. Thus, every object can be predicted as cigarette butt. As shown in image average mAP score shows 73.29 %. It proved that how the training system success over the datas.

![5](https://github.com/yasinsulhan/robot-picking-cigarette-butt-with-image-processing/assets/109728194/94a8e7c2-2341-422f-b3d5-3fb30e0f9cde)

# Last Version of the Robot
Here is the last version of the robot as hown the image. The red led lights up if the object is cigarette_butt. There is a camera module in the middle of the robot and two arms folding up each other. Also robot has a cigarette butt bin to store them. This will be published soon.





