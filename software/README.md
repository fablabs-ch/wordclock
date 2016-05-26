#Arduino code for the wordclock

#Requirement

The arduino programme require two libraries
 * [TimerOne](https://github.com/PaulStoffregen/TimerOne.git)
 * [DS3231.h](https://github.com/jarzebski/Arduino-DS3231.git)


Clone these librairie in the folder arduino/libraries, restart your arduino IDE and you're good to go. The arduino folder is usually located in _My Documents_ (example : `C:\Users\Gaetan\Documents\Arduino\libraries`)

```sh
cd C:\Users\Gaetan\Documents\Arduino\libraries
git clone https://github.com/PaulStoffregen/TimerOne.git
git clone https://github.com/jarzebski/Arduino-DS3231.git
```

##State diagram
![class diagram](https://github.com/fablabs-ch/wordclock/blob/master/software/images/state_diagram.png "State diagram")

##Class diagram
![class diagram](https://github.com/fablabs-ch/wordclock/blob/master/software/images/class_diagram.png "Class diagram")
