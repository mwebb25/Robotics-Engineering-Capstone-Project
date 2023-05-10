# Robotics-Engineering-Capstone-Project

Overview

Radio-Controlled cars or RC cars are miniature models of cars or trucks(figure 4). They can be controlled from distances using transmitters or remotes. Many kids have them as toys. They come in all shapes and sizes. There are also people who race RC cars. They have modified these cars to have an actual engine in them. They have designed these cars to be fast and aerodynamic. They can do fast wheel changes on these cars during the races.
In our project we will design a RC car to be very fast and aerodynamic. We will have a controller for a human to drive it around. It will have two arduinos connected to each other. One will be connected to the controller, the other will be in the car controlling it. We will have two motors controlling the back wheels to move forward. Servos in the front of the car will steer it.
We will design our car to be fast and lightweight. We will power it with a 5 volt battery pack and only use necessary components to make it as light as possible. Our arduinos will connect using radio waves. We can test this around the school on different surfaces.


2023 Robotics Engineering Capstone Project



Grady Thorne and Michael Webb
05/10/2023

![IMG_1059](https://github.com/mwebb25/Robotics-Engineering-Capstone-Project/assets/90726375/2a939505-40dd-4ecc-9f6e-d8c3bd338a80)

Design Summary:

For our project we built a Remote Controlled Car. An ESP8266 controls four Arduino motors that move the car around. A distance sensor mounted on the front of the car senses distance and stops the car from colliding with any obstacles in front of it. When the car gets too close to an object it automatically stops the car. 

System Design:

For our driving system four motors that move four wheels. We have a phone with Blynk downloaded on it. Blynk is hooked up to an ESP8266. The ESP is wired to a Motor Controller. We control the car with 4 wheel tank drive. Our distance sensor is connected to the ESP and sends the distance to an LCD on the phone. When the distance to an object is too close to the car the distance sensor stops the motors from moving forward.

Design Evaluation:

For the output display we have a LCD and display screen on the phone we use to display the distance the car is away from an object. For the manual user input we have a touch screen with four buttons that controls the car. For our automatic sensor we use a distance sensor to tell us how far away an object is and will give us a warning message if the car gets too close and will stop the car. We have four on-off DC motors to drive the car that meet the Actuators, Mechanisms and Hardware requirements. We have a bluetooth module that connects Blynk to our ESP to control the entire car. 



Parts:

ESP8266 #WRL-17146 Sparkfun Electronics $8
L298n Motor Controller #L298n Qunqi $5
4 Arduino Motors and Wheels #ROA_408 DiGiYes $15
Distance Sensor #EP-HC-SR04 EPLZON $3
2 Battery Packs $8
9 Batteries #HR-3UTG-AMZN Amazon $9
Mini BreadBoard #3-01-0633 HiLetgo $7
Switch $2
Wire Nuts #30-072 Ideal $2
Magnets $2
PVC #42639 Ace $3

3D Prints:
Walls 73.1g
Motor Mounts 20g
Sensor Mounts 10g

Lessons Learned:

One of the biggest problems we had encountered was coding the distance sensor to work. It did not want to stop the car from hitting objects and then when it did stop the car the code made the drive controls start to lurch in all directions. We had to try many different codes before we finally found one that worked. Another big problem we had was two days before the project was due our car stopped working completely. The motors would not run and the distance sensor was also not sensing distance. We had to take apart the entire car and rewire it and recode it. One of the biggest lessons we learned was that you have to keep trying and can’t give up on your project.

Building Instructions:

The first step is to measure out your PVC pipe. You want PVC pipe that is 2 inches in diameter.  The next step is to cut the PVC to be around 15 inches in length. This will be around the length that your car will be. However, you want to cut your 15 inches of PVC horizontally. You then have a PVC pipe that can now be made of a length of 6.28 inches wide. You then heat the PVC pipe to then flatten it to a plate. If needed you may want to use a large piece of wood and press down on the PVC after you heated it. The next step is to put the templates provided on and use a jigsaw to cut out the shape of the body. Repeat everything above one more time to get to pvc body plates. You then need to print 4 motor mounts. You will also want to print two side walls, a front, and a back wall. All of these walls will be hot glued on top of one of your PVC pipe plates. That will then make your car around a height of an inch and a half. After adding your walls you want to attach your motors. You need to take your four motors and their mounts and drill a hole in your pvc base plate and attach one bolt and a lock nut. This will be repeated for all the motor mounts. Now you will need to drill 3 more holes. The first is near the center of the robot. You need to drill a quarter-inch hole for the switch. You will now need to mount your distance sensor. You need to mount this with the same bolt and nut as you mounted the motor mounts. Once you do that you are getting close. All you need to do is drill a quarter-inch hole close to your distance sensor mount. Wire everything up to the ESP8266 and connect it to Blynk. The final step is to add magnets with corresponding metal bars to the middle of the middle wall. After all of these steps, you are done and you can drive. 
