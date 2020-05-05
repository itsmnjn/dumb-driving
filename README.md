# Dumb Driving - A dead simple autonomous driving algorithm for my MSP432 Launchpad robot kit

During my spring of 2020 semester, I took an embedded development and robotics class where we were taught to assemble and program a simple line-following robot, built from a kit provided by Texas Instruments. Due to the COVID-19 crisis, as classes moved online, the line-following aspect of the project had to be taken out, and we simply stopped at timer-controlled PWM motors.

I wanted to at least get Felix (what I named my robot) to drive himself in some sort of fashion, and so I decided to extend our final lab code with a simple algorithm:

1. Go forward
2. If bumpers hit, stop
3. Go backward
4. If first stop, turn right 90 degrees
5. If second stop, turn left 90 degrees
6. Go to step 1

Here's a video of Felix in action!

\[insert video here\]

I also have plans on making Felix a lot smarter with computer vision, though that may take some time as I have yet to learn much about that field.
