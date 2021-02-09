# Philosophers 

<img src="logo.jpeg" alt="logo"/><br/>

------------

❗**The structure of the code may look strange, this is caused by the coding rules of School 21 (no more than 25 lines for a func etc.)**

------------

## Multiple implementation of the dining philosophers problem <br/>


### Introduction

In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

It was originally formulated in *1965 by Edsger Dijkstra* as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation

[More informations](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

------------

Please see <a href="./subject.pdf">subject.pdf</a> for getting the assignments.

------------

### Implementations:

* **philo_one** - Threads and mutexes
* **philo_two** - Threads and semaphores
* **philo_three** - Processes, threads and semaphores

------------

#### Build and Run:
```
# Move to the appropriate directory and:

> make
> ./philo_[number] [p_num] [d_time] [e_time] [s_time] [m_num]

_____________________________________________________________

# Example:

> make
> ./philo_one 4 410 200 200 5
```

#### Options:

Option                 | Description
---------------------- | ----------------------
p_num                  |number of philosophers
d_time                 | time to die for a philosopher
e_time                 | time to eat for a philosopher
s_time                 | time to sleep for a philosopher
m_num                  | number of meals for a philosopher (optional)

-------------

#### Additional Resources:
 
* **[Thread & Mutex](https://www.youtube.com/watch?v=9axu8CUvOKY)** <br/>
* **[Semaphore](https://www.youtube.com/watch?v=ukM_zzrIeXs)**

