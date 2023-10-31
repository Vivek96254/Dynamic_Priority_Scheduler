# Dynamic_Priority_Scheduler

Consider a scheduling approach which is non pre-emptive similar to shortest job next in 
nature. The priority of each job is dependent on its estimated run time, and also the amount of 
time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents 
indefinite postponement. The jobs that have spent a long time waiting compete against those 
estimated to have short run times. The priority can be computed as :
Priority = 1+ Waiting time / Estimated run time
Write a program to implement such an algorithm. Ensure
1. The input is given dynamically at run time by the user
2. The priority of each process is visible after each unit of time
3. The gantt chart is shown as an output
4. Calculate individual waiting time and average waiting time

To address this problem, we’ll follow a systematic approach. First, we’ll prompt the user to input the number of processes. Next, we’ll create a data structure to store all the relevant information for each process, including details like arrival time, waiting time, priority, etc. We’ll initialize waiting times and execution status to their initial values.To keep track of the progress of the processes, we’ll set up a table that will display all the process data, aiding us in monitoring the entire process. Our main loop will calculate priorities for all the processes. We’ll select the first process to execute based on its arrival time, prioritizing the process that arrived first. Subsequently, we’ll continue selecting processes that entered the system while another process was being executed, based on their calculated priorities. After each process completes its execution, we’ll re-evaluate priorities and select the next process accordingly. If there are no processes ready to execute at a given time, that period will be considered as idle time. We’ll increment the clock time by a small value, such as 0.01 seconds, to simulate this idle time. We’ll continue this process until all the processes have been executed. Once complete, we’ll print a comprehensive table that includes all the details of each process. We’ll also generate a Gantt chart to display the order in which the processes were executed. Finally, we’ll calculate and print the average waiting time to provide an overall performance metric for the executed processes. 
