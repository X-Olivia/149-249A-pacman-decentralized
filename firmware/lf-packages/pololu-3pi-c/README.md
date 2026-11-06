# Package Library for Interaction with the Pololu 3pi Robot Components
This reactor package library provides base reactors for interfacing with components of the [Pololu 3pi+ 2040 robot](https://www.pololu.com/docs/0J86), along with the C headers and utility routines used by the base reactors. This library is written in the C target of Lingua Franca.

## Prerequisites
This library requires installing the Raspberry Pi Pico SDK and `picotool`.
### Install with `nix`
Please follow the steps in https://www.lf-lang.org/embedded-lab/Prerequisites.html.

### Non-`nix` setup
Please follow the steps in https://www.lf-lang.org/embedded-lab/Non-Nix.html.

## Library Reactors
* [Bump](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Bump.lf): Periodically reads the bump sensors and outputs their states.
* [Display](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Display.lf): Receives strings and displays them on the LCD display.
* [Encoder](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Encoder.lf): Reads the wheel encoders when triggered and outputs the measured angle in degrees.
* [Accelerometer, Gyro, and GyroAngle](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/IMU.lf): Read the IMU values when triggered and output the acceleration, angular velocity, and the robot's angle relative to its initial orientation, respectively.
* [Line](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Line.lf): Reads the line sensors when triggered and outputs their values. By default, calibration is performed upon receiving the first trigger. **NOTE**: The line sensors cannot be used together with the bump sensors.
* [Motors](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Motors.lf): Drives the left and right motors according to the power levels provided as inputs.
* [MotorsWithFeedback](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/MotorsWithFeedback.lf): Wraps [Motors](https://github.com/lf-lang/pololu-3pi-c/blob/main/src/lib/Motors.lf) with a proportional-integral (PI) feedback controller. It uses encoder measurements to adjust motor power so that the measured wheel speeds track the desired speeds.

## To Use This Library
Clone the repo into your `lf-packages` directory in the root of your project or into the directory pointed to by your `LF_PACKAGES` environment variable:

```bash
git clone https://github.com/lf-lang/pololu-3pi-c.git
```
Alternatively, if you are in a git repo, create a submodule:

```bash
git submodule add https://github.com/lf-lang/pololu-3pi-c.git
```
Then import the library reactors. For example:

```
import Display from <pololu-3pi-c>
```

## Usage Examples
This package library is currently used by the [lf-3pi-template](https://github.com/lf-lang/lf-3pi-template) repository as the main template library for the [Embedded Systemd Labs](https://www.lf-lang.org/embedded-lab/index.html).
