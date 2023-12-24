# SJF algorithm

## SJF Manager
Manager will create an infinite loop until all requested processes aren't completed.
Every time a process is added queue will be sorted.

```mermaid
---
title: Algorithm live
---
flowchart TB
create["`Create new **process**`"]
sort["Sort the queue except first element"]
add["`Add **process** to the end of array`"]
pick["`Pick first **process** in array`"]
process["`Execute **process**`"]
remove["`Remove **process** from array`"]

subgraph creation[Process Creation]
    create --> add --> sort --> create
end
    
subgraph loop[Main Loop]
    pick --> remove --> process -->|When finished| pick
end

creation ..-> loop
```

## Starting manager
On start of simulation user will be asked to choose how many processes are wanted to be simulated.
The user can create more than one simulation.