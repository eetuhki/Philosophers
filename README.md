# 🍝 **Philosophers**

Solving the classic [*Dining Philosophers*](https://en.wikipedia.org/wiki/Dining_philosophers_problem) problem in **C**, using **threads** and **mutex locks**.

Picture this:
Five philosophers sit around a circular table with a bowl of spaghetti.  
There's five forks, but each philosopher needs **two forks** to eat.

Who gets the forks first?  
The hungriest philosopher of course!  

And remember philosophers need to sleep and do some thinking too..!

## Key concepts

**Thread Management**  
  Creating and coordinating multiple threads safely  
  
**Mutex Synchronization**  
  Protecting shared resources (forks) from data race conditions  
  
**Deadlock Prevention**  
  Implementing strategies to avoid circular wait conditions  
  
**Resource Scheduling**  
  Ensuring fair access to limited resources  
  
**Performance Optimization**  
  Balancing efficiency with safety in concurrent systems  

## Installation

Clone the repo and run **make**

## Usage

Please launch `./philo` with the following arguments:
  1. the number of philosophers
  2. the time (in ms) when a philosopher should die
  3. the time (in ms) it takes for a philosopher to eat
  4. the time (in ms) a philosopher will spend sleeping  
  (optional)  
  5. the number of times each philosopher eats

## Examples

`./philo 3 800 200 200`

`./philo 100 600 300 100 5`
