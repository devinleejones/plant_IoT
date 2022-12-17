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

In the code, I am using Adafruit IO to subscribe to a feed to listen to a "ON" or "OFF" message to turn the relay on for the water pump. This is also contingent on if the threshold is below the ideal moisture level. There is also a feed subscribed to the data from the M5 processor to notify adafruit and myself through email if the water moisture level goes below the threshold.

<iframe src=https://create.arduino.cc/editor/devinleejones/82c21e42-468c-42c4-834b-65c706918a46/preview?F=ReadMe.adoc?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

### Software   

<iframe src=https://create.arduino.cc/editor/devinleejones/82c21e42-468c-42c4-834b-65c706918a46/preview?F=ReadMe.adoc?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

### Integrations   

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.27.53%20PM.png)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.28.04%20PM.png)

![example of an image](https://github.com/devinleejones/plant_IoT/blob/main/Photos/Screen%20Shot%202022-12-16%20at%205.28.42%20PM.png)


## Project outcome  

[Final video walkthrough of prototype](https://youtube.com/shorts/DgtvGtQOz5Q?feature=share)

## Conclusion  

I had a lot of fun working on this project and using the built in wifi cababilities of the M5 Board to connect to Adafruit IO. Utilizing the feeds and the applets through IFTTT was a really cool experience that felt pretty seamless. Some of the biggest difficulties for me was figuring out the logic for the relay in conjuction with the water pump to water the plant when necessary based on readings of the thresholds built in. In the future I would like to develop the applets further to have more versatility for hte user when watering their plants remotelty. 

## Project references  

Adafruit -

https://www.adafruit.com/product/4547?gclid=Cj0KCQiAm5ycBhCXARIsAPldzoUbuDUomzTId5K_s44k9dhl1d6b_HoViTWjhyyQ2sczhtfTbzvqmXIaAvQcEALw_wcB
https://www.adafruit.com/product/4026

Youtube -

Caroline Dunn
https://www.youtube.com/watch?v=0tlo2dZ8J1s
