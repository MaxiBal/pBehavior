# pBehavior

## Build

Build using Make
```bash

$ make

$ mv ./pBehavior ~/moos-bwsi/behaviors/bin

```

## Add to Project

Add configuration for the setup to the behavior file add the following to the MODE initializations

```
initialize GOTO = false

...

Set MODE=GOING {
    MODE=Active
    Returning=false
    GOTO = true
}
```

Then in behaviors, also add a GOING_TO behavior:
```

Behavior = BHV_Waypoint {

    name      = going_to
    pwt       = 10000
    condition = MODE == GOING

    updates   = GOTO_UPDATES

    point = 0,0

    speed = <VEHICLE_SPEED>
}

```

## Running

To run use:

```bash
pBehavior <MOOS_FILE>.moos
```
You will then be prompted for an X and a Y value.
```bash
Enter X Coordinate: <X_COORD>
Enter Y Coordinate: <Y_COORD>
```
Replace X_COORD and Y_COORD with the desired coordinates and watch the vehicle go.