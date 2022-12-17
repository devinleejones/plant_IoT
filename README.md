## Introduction   

This project is a self watering system that monitors soil moisture levels and sends data about it through wifi to Arduino IO. When the soil moisture gets too low, IFTTT will notify you through email and allow you to send an email to trigger the water pump to water your plant remotely.

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Soil_Sensor.png)

## Implementation   

Explain your process of prototype development including all applicable aspects such as hardware (electronics), firmware (arduino code), software (p5.js or other code), integrations (Adafruit IO, IFTTT, Arduino IoT cloud, etc.), enclosure and mechanical design.  Use a separate subheader for each part:

### Hardware

This project is powered by the M5 Core-Ink microprocessor which powers and facilitates the entire process.

Capacative Soil Moisture Sensor v1.2 - Track moisture levels

Relay - Toggle the on and off function of the water pump

Water Pump - Water the plant from external water supply

### Schematic   

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.06.16%20PM.png)

### Hardware Wiring   

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/IMG_4305.jpg)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/IMG_4306.jpg)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/IMG_4307.jpg)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/IMG_4310.jpg)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/IMG_4312.jpg)

### Firmware   

<iframe src=https://create.arduino.cc/editor/devinleejones/82c21e42-468c-42c4-834b-65c706918a46/preview?F=ReadMe.adoc?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


In the code, I am using Adafruit IO to subscribe to a feed to listen to a "ON" or "OFF" message to turn the relay on for the water pump. This is also contingent on if the threshold is below the ideal moisture level. There is also a feed subscribed to the data from the M5 processor to notify adafruit and myself through email if the water moisture level goes below the threshold.

### Software   

<iframe src=https://create.arduino.cc/editor/devinleejones/82c21e42-468c-42c4-834b-65c706918a46/preview?F=ReadMe.adoc?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

### Integrations   

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.27.53%20PM.png)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.28.04%20PM.png)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.28.42%20PM.png)

### Enclosure / Mechanical Design   

Explain how you made the enclosure or any other physical or mechanical aspects of your project with photos, screenshots of relevant files such as laser-cut patterns, 3D models, etc. (it’s great if you’re willing to share the editable source files too!)

## Project outcome  

Summarize the results of your final project implementation and include at least 2 photos of the prototype and a video walkthrough of the functioning demo.

## Conclusion  

As you wrap up the project, reflect on your experience of creating it.  Use this as an opportunity to mention any discoveries or challenges you came across along the way.  If there is anything you would have done differently, or have a chance to continue the project development given more time or resources, it’s a good way to conclude this section.

## Project references  

Please include links to any online resources like videos or tutorials that you may have found helpful in your process of implementing the prototype. If you used any substantial code from an online resource, make sure to credit the author(s) or sources.
