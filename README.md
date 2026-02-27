<!-- *********************************************************************** -->
<!--                                                                         -->
<!--                                                      :::      ::::::::  -->
<!-- README.md                                          :+:      :+:    :+:  -->
<!--                                                  +:+ +:+         +:+    -->
<!-- By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+       -->
<!--                                              +#+#+#+#+#+   +#+          -->
<!-- Created: 2026/02/02 14:46:52 by alago-ga          #+#    #+#            -->
<!-- Updated: 2026/02/27 15:32:56 by alago-ga         ###   ########.fr      -->
<!--                                                                         -->
<!-- *********************************************************************** -->

*This project has been created as part of the 42 curriculum by Ariel Lago.*

# PHILOSOPHERS

## Description
This project is written in C, it works with threads and mutexes to generate a simulation:
A certain number of philosophers sit around a table with the goal of eating spaghetti. 
There's one fork per philosopher but they need two forks to eat, so they have to go into a routine where they sleep and think while they wait for two forks to be free for eating. 
After eating they put the two forks on the table and go to sleep, so other philosophers can eat.
In certain occasions a philosopher will be unable to find two free forks on time and will starve.
In this cases the simulation will end.

### Implementation
- Each philosopher runs in its own thread.
- Each fork is protected by a mutex.
- There's a thread that perpetually checks whether any philosopher has starved or eaten enough meals.
- There's a mutex that ensures that the philosopher thread messages are printed one by one.
- Even numbered philosophers start with a small delay in order to avoid deadlocks.
- ft_usleep uses a loop that makes it more precise than usleep.

## Instructions
After cloning the repository, open it on your terminal and type *make* to compile.
Now you can run the program by writing *./philo* followed by four or five arguments:
### (1) Number of philosophers
How many philosophers and forks will be at the table.
### (2) Time to die
How many milliseconds a philosopher can go without starving.
### (3) Time to eat
How many milliseconds they take to eat.
### (4) Time to sleep
How many milliseconds they sleep for.
### (5) Number of times each philosopher must eat
This argument is optional. If all philosophers have eaten the amount of times they must eat, the simulation stops

## Resources
### References
In order to write this project I first needed an understanding of threads and mutexes.
The main resource for this was the course **Unix Threads in C** by **CodeVault**: *www.youtube.com/@CodeVault* This course explains the differences between threads and processes, the need and use of mutexes, as well as going into detail about condition variables, semaphores and other thread-related concepts that go beyond the scope of this project. 
Some other references were more specific to this project, like this guide: https://42-cursus.gitbook.io/guide/3-rank-03/philosophers

### AI usage
Claude and Gemini AI were used in different points in this project.
- It detected the need for a custom ft_sleep function to make usleep() more precise.
- It helped with discovering potential problems and edge cases that I was not able to come up with during my own tests: For instance the need for a write mutex.
- It gave me code reviews and suggested improvements.
- It gave me tests to check the simmulation was working properly.
- It helped me sometimes with debugging. 
