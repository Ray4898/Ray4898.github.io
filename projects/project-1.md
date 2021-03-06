---
layout: project
type: project
image: images/proj1.PNG
title: Vertical Landing Rocket (Thrust Readings of a Rocket)

permalink: projects/Rocket
# All dates must be YYYY-MM-DD format!
date: 2018-07-01
labels:
  - Propeller
  - Arduino
summary: We made an RPM sensor by using a Hall effect sensor and a magnet for the Vericle Landing Rocket.
---

<div class="ui small rounded images">
  <img class="ui small floated image" src="../images/proj1.PNG">
  
  
</div>

In order to ensure a descending rocket will land softly, a sensor system must be integrated to detect changes in height, velocity, rotations-per-minute (RPM) and thrust. The respective data is essential for proper communication between the microcontroller and the servo motor. The intended goal is to have our sensors output a single height value and to adjust the throttle of the propeller with respect to the velocity as the rocket descends.


For this project, I designed and made an RPM sensor by using a Hall effect sensor and a magnet with the other team members. The Hall effect sensor uses the Hall effect theory and acts like a switch. We 3D printed a mold, which could hold a magnet against the shaft and also 3D printed a base, which would hold the Hall effect sensor in a permanent position near the shaft. When the motor spins, the magnet passes in front of the Hall effect sensor, changes the magnetic field for that duration that the magnet is in front of the sensor, and sends a signal to the Arduino, thus detecting the rotation. 

<div class="ui large rounded images">
  
 <img class="ui large center image" src="../images/proj1-2.PNG">
 
</div>

We used the RPM sensor we made and a scale to measue the RPM and the thrust. I also made a graph for RPM VS Thrust with the data, and the Graph above shows the relation between the RPM and the thrust (measured in Weight).  We also used the data to make an equation.  With the relation between the RPM and the thrust, we could now know how to control the rocket when it is landing.

By doing this project, I know how to design an embed system with Arduino and how to write code with Arduino.



Source: <a href="https://github.com/Ray4898/Ray4898.github.io/blob/master/RPM.ino"><i class="large github icon "></i>source code for the RPM sensor</a>







