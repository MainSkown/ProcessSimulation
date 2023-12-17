# FCFS algorithm

## FCFS Manager
Manager will create an infinite loop until all requested processes aren't completed.

```mermaid
---
title: Algorithm live
---
flowchart TB
create["`Create new **process**`"]
add["`Add **process** to the end of array`"]
pick["`Pick first **process** in array`"]
process["`Execute **process**`"]
remove["`Remove **process** from array`"]

subgraph creation[Process Creation]
    create --> add --> create
end
    
subgraph loop[Main Loop]
    pick --> remove --> process -->|When finished| pick
end

creation ..-> loop
```

## Starting manager
On start of simulation user will be asked to choose how many processes are wanted to be simulated.
The user can create more than one simulation.