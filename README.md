# Pacman Decentralized

**EECS 149/249A Final Project — Fall 2026**  
**Team:** Yacqub Mohamed, Sareena Robinson, Sophie Ling, Jing Xu

> Project proposal / work in progress. The implementation details and hardware choices are subject to testing.

## Overview

We propose **Pacman Decentralized**, a physical rendition of Pacman without a central controller providing location information to the ghosts. Pacman is a robot controlled by a human, and the ghosts are robots that move based on a predefined protocol. The ghosts never truly know where they are in the maze, and must plan their path to find Pacman using local information combined with information shared by other entities. The goal is for Pacman to last as long as possible without being captured by a ghost.

## Approach

We will use a wireless communication medium such as BLE or WiFi for a human to control the Pacman robot, and for the ghosts to communicate with each other. We will test the effectiveness of a variety of sensors, such as infrared sensors and candidate camera or UWB modules, for the ghosts to navigate through the maze, avoid colliding into other ghosts, efficiently find Pacman, and attempt to “capture” Pacman. We define “captured” as a ghost coming within a proximity threshold of Pacman. The detection method and capture threshold will be finalized after hardware tests.

We will use state machines to model the protocol the ghosts will follow. The state machine will use the sensor values, along with other accumulated data, to determine where to move next and what information to send to the other ghosts. We also plan to simulate different maze layouts and starting conditions, comparing how no communication, periodic broadcasting, and event-triggered communication under limited sensing range influences Pacman survival time, capture success rate, and communication overhead.

## Resources

Here are the current resources we plan to use, along with how we will use them:

1. **3-4 Pololu robots** for Pacman and the ghosts.
2. **4x8ft (or larger) cardboard sheet** for the maze platform, along with black tape for the path of the maze. The robots will use their downward-facing IR sensors to stay on the path.
3. **3-4 BLE/WiFi module** (DSD TECH HM-10 BLE or MOD-WIFI-ESP8266) for wireless communications. We plan to use our phones, a laptop, or a physical joystick, as the controller for the Pacman robot. (Enough of these modules are in-stock).
4. **3-4 UWB transmitters** ([DWM3000EVB](https://www.digikey.com/en/products/detail/qorvo/DWM3000EVB/24367408), $29.5) for determining distance to the other robots, and for distinguishing between Pacman and the other robots
   1. If UWB does not work well, then we will try in-stock cameras for identifying Pacman and other ghosts using distinct color markers, and ultrasonic sensors (HC-SR04) for proximity detection.

## Schedule

- **November 4:** Proposal (due noon)
- **November 9/16:** Presentation
  - Present our project details and what we plan on doing over the next few weeks.
- **November 12:** Milestone 1
  - Basic Pacman remote control in open space, along with initial ghost navigation to find Pacman. Get basic computer simulation with maze and Pacman working.
- **November 23:** First Mini Project Update (Maze Development)
  - Develop a physical maze, get ghosts to navigate the maze to find and capture Pacman. Also flesh out simulation with multiple ghosts and sensing.
- **December 3:** Milestone 2
  - Specify state machine protocol for the robots, fully implement it, and analyze its effectiveness in simulation and real-world testing.
- **December 7:** Third Mini Project Update (Communication)
  - Implement group communication between the ghosts using BLE or WiFi, and experiment with data sharing strategies and how it improves capture efficiency.
- **December 14:** Fourth Mini Project Update (Final Deliverables)
  - Finish most of the project report. Have a demonstration mostly ready at this point.
- **December 17:** Project Poster/Demo Expo
- **December 18:** Project Report Turned In

## Risks

1. The BLE/WiFi module we plan to use may not work well for group communication among multiple ghosts. We may have to experiment with different communication structures (such as only allowing Pacman to broadcast data to the ghosts).
2. There may not be enough available pins to hook up all the sensors. We will do initial hardware testing to make sure this is possible.
3. Staying on path requires the robots to accurately identify intersections and viable paths fast enough to respond (which depends on the quality of the maze + the underlying sensor being used to track the path). The IR sensors can work for this, but that means for each test run, every robot must correctly calibrate their IR sensors.
4. The entire game could be derailed if the ghosts ever collide into each other. The ghost protocols must prevent them from colliding.

## Project Structure

```text
.
├── README.md                # Project proposal and overview
├── firmware/                # Robot control, sensing, communication (planned)
├── simulation/              # Maze and multi-ghost simulation (planned)
├── experiments/             # Evaluation configurations and results (planned)
└── docs/                    # Hardware notes and design documentation (planned)
```

The directories are placeholders. No implementation has been committed yet.

## Proposal

[Shared Google Docs project proposal](https://docs.google.com/document/d/1uMTvYJauuFdY2iByDO_VxIN7RbM9pTxfK5Ku_NUzh88/edit?tab=t.o0gbc5lnk3e1)
