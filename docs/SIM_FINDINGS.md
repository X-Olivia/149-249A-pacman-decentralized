## Initial Findings (11/7)

1. If the ghosts do a naive algorithm where they repeatedly query the UWB sensor
and rotate randomly if the distance increases, then the ghosts will rotate
rapidly when pacman is moving away (even if the ghosts are moving in the 
right direction).

2. UWB usually has noise in its measurements, so our code should simulate that.

3. UWB may also provide angle measurements, so our code could simulate that.
