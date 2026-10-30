# Pacman Decentralized

**EECS 149/249A Final Project — Fall 2026**  
**Team:** Yacqub Mohamed, Sareena Robinson, Sophie Ling, Jing Xu

> Project proposal / work in progress. The implementation details and hardware choices are subject to testing.

## Overview

We propose **Pacman Decentralized**, a physical rendition of Pacman without a central controller providing location information to the ghosts. Pacman is a robot controlled by a human, and the ghosts are robots that move based on a predefined protocol. The ghosts never truly know where they are in the maze, or where the other entities are, and must plan their path to find Pacman using local information combined with information shared by other entities. The goal is for Pacman to last as long as possible without bumping into a ghost.

## Approach

We will use a wireless communication medium such as BLE or WiFi for a human to control the Pacman robot, and for the ghosts to communicate with one another. We will use a variety of sensors, such as infrared sensors and proximity sensors, for the ghosts to navigate through the maze and avoid colliding into other ghosts.

We will use state machines to model the protocol the ghosts will follow. The state machine will use the sensor values, along with other accumulated data, to determine where to move next and what information to send to the other ghosts. We also plan to build a computer simulation of our project to evaluate the quality of our protocol under various maze structures, starting positions, and Pacman movements. Our goals are for the ghosts to cleanly navigate through a maze, avoid other ghosts, efficiently find Pacman, and attempt to crash into Pacman.

To determine when a ghost has found Pacman, we will test the feasibility of the camera-based visual-marker approach alongside the proposed acoustic-foam setup. While acoustic foam may prevent Pacman from being treated as an obstacle, it cannot identify the target on its own, so an additional target-confirmation method would be needed. We aim to register a capture when a ghost confirms Pacman within a calibrated proximity threshold, rather than requiring a physical collision. The detection method and capture threshold will be finalized after initial hardware tests.

## Resources

Current planned resources and their roles:

- **3–4 Pololu robots** for Pacman and the ghosts.
- **4 × 8 ft (or larger) cardboard sheet and black tape** for the maze platform and boundaries. The robots will use downward-facing infrared sensors to detect and avoid crossing the tape.
- **BLE/WiFi module** (XIAO ESP32C6 or MOD-WIFI-ESP8266) for wireless communication. Phones are planned as controllers for Pacman.
- **Ultrasonic distance sensors** (HC-SR04) to help ghosts avoid other robots. We plan to experiment with open-cell acoustic foam on Pacman to reduce ultrasonic reflections; the effectiveness of this approach remains to be tested.

Additional hardware and setup details: **TBD**.

## Communication Strategies

We will investigate how different inter-robot communication strategies affect decentralized multi-robot pursuit. We plan to compare three strategies:

1. **No Communication:** Each ghost searches for and pursues Pacman using only its own sensor observations, without exchanging information with other ghosts. This serves as our baseline.
2. **Periodic Broadcasting:** Ghosts broadcast their status and local observations at fixed intervals, allowing others to adjust their search behavior based on shared information.
3. **Event-Triggered Communication:** Ghosts send messages only when key events occur, such as detecting or losing Pacman or observing a significant change in their surroundings, to reduce unnecessary transmissions.

All three strategies will use the same sensing configuration and underlying navigation algorithm; the primary difference will be how information is shared. Each ghost will make its own decisions through a finite state machine using local observations and any received messages, without a central controller.

Messages may contain a sender ID, event type, target observation, and timestamp.

## Evaluation Plan

We will first implement all three communication strategies in simulation and compare them under matched maze layouts, initial positions, and Pacman trajectories. This will allow us to evaluate the effect of communication on cooperative pursuit.

We will measure:

- **Capture success rate:** The proportion of trials in which Pacman is captured within a fixed time.
- **Average capture time.**
- **Collision frequency:** With obstacles or other ghosts.
- **Communication overhead:** Message count, data volume, and transmission frequency.

After the simulation experiments, we plan to implement at least two modes on physical robots: independent pursuit without ghost-to-ghost communication, and one cooperative mode with information sharing. If time permits, we will implement the third communication strategy and compare the physical results with simulation.

Our goal is to quantify under which conditions communication improves pursuit efficiency and to examine trade-offs involving communication overhead and sensing limitations.

## Implementation Scope and Fallback Plan

To reduce the risks of hardware integration and multi-robot communication, we will develop the system incrementally.

We will first implement a remotely controlled Pacman and a single ghost capable of independent exploration, obstacle avoidance, and target detection. We will then extend the system to multiple ghosts to establish a baseline that does not rely on inter-robot communication, before adding information sharing and coordinated behavior.

If reliable wireless communication or multi-robot coordination cannot be completed in time, the system will still support an independent-pursuit mode for a basic physical Pac-Man demonstration, while simulation will be used to compare the communication strategies.

For the physical system, we will prioritize reliable navigation, target detection, and at least one cooperative communication mode. More complex communication strategies and directional target estimation will be considered as time permits.

## Schedule

**TBD** — to be agreed upon by the team.

## Risks

- The BLE/WiFi module may not work well for group communication among multiple ghosts. We may need to experiment with different communication structures, such as only allowing Pacman to broadcast data to the ghosts.
- Detecting and avoiding walls depends on careful calibration of each robot's infrared sensors, potentially before each run.
- Ghosts must distinguish staying on a path from turning into an alley; T-intersections and other junctions present navigation challenges.
- Acoustic foam might not work as intended, so ghosts may still avoid Pacman. A possible alternative is a low-resolution camera and a recognizable visual marker on Pacman.
- Additional risks and mitigations: **TBD**.

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
