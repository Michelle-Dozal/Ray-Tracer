# Ray-Tracer
>This project was completed while taking CS130 (Computer Graphics) at University of California, Riverside in Winter 2021 with Dr.Tamar Shinar. The main purpose of the course was to become familiar and comfortable using physics and vector knowledge to implement a ray tracer.

## General
The main purpose of this project was to use generate 2D/3D objects using pixels by their light movement. Also known as "ray-tracing" and was implemented using shading/rays/physics concepts to bring it to life. 

Implemented Things like
* Flat Shading
* Sphere Intersections
* Casting Rays
* Coordinate System
* Plane Intersections
* Phong Shading (ambient,diffuse, & specular)
* Shadows
* Reflective Shading

## Some Tests 

<img width="450" src="https://user-images.githubusercontent.com/62925991/106525874-817a9380-6499-11eb-83ee-a0365f9fd6f2.png"> <img width="450" src="https://user-images.githubusercontent.com/62925991/106693346-1c9f6600-658b-11eb-8126-5ecb0c736783.png">
<img width="450" src="https://user-images.githubusercontent.com/62925991/106693351-2032ed00-658b-11eb-8bf7-e325f5f6f19d.png">


## Usage
Once the files are downloaded and all the code is in place you can run the tests or the grading script. To run the tests, run ``` ./ray_tracer -i <test-file>``` and once it runs the output of that test file will be routed to the output.png where you can see it. To get more detailed info on the pixels you can use the -x & -y flags to print out information about a pixel using the "debug_pixel" function. To do so run ```./ray_tracer -i <test-file> -x 123 -y 234 ``` with the desired pixels. You can always go and add to the debug_pixel in the certain functions to see specific data. I was able to get it to test 25. :) 

This project comes with a grading script, which you can run like this: ```./grading-script.py .``` and you will see all the tests that are passed.

### Technologies
* C++
* Python (for grading script) 
