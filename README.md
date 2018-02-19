Name: DoubleProject
Description: Semantic tagging of locations with the robot Double and the Vision Cloud Service Clarifai.
Author: Alexandre SARAZIN, 2018

The aim of the project is to allow the robot Double and the user to know in which room of a building the robot is situated through a semantic tagging of locations and using a Vision Cloud Services.
The first step is to acquire a data set of pictures for each room/concept and send them to the Cloud Service. Then create and train the model with the defined concepts. Finally test the model.
The robot can be control directly via the iPad or via the Python script 'double_remote_control.py'.

Requirements: XCODE, COCOA, CLARIFAI Profile, Basic-Control-SDK-iOS for Double, PYTHON

It is strongly recommended to create a new Xcode project. The Basic-Control-SDK-iOS can create problem if you try to run the code as it is. You can copy paste the 'Podfile' in your new workspace and update it.

Then:
1. Do a 'pod install' in the file repository
2. Update your computer IP address and Clarifai API key in the 'ViewController.m'
3. Update your computer IP address in the 'double_remote_control.py' python script
4. Connect the iPad to Double
5. Launch the python script 'double_remote_control.py' on your computer
6. Launch the app on the iPad
7. Connect the app to the computer with the 'connect' button