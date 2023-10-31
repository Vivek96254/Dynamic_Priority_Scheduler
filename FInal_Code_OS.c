#include <stdio.h>
#include <float.h>

struct Process {
    int id;
    float arrival_time;
    float burst_time;
    float waiting_time;
    float priority;
    int executed;
};

void calculate_priority(struct Process processes[], int n, float total_waiting_time, float current_time) {
    int i;
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > 0 && processes[i].arrival_time <= current_time) {
            processes[i].priority = 1 + (current_time - processes[i].arrival_time + processes[i].waiting_time) / processes[i].burst_time;
        } else {
            processes[i].priority = -1; 
        }
    }
}

int main() {
    int num_processes, i;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];
    float total_waiting_time = 0;

    for (i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%f", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%f", &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].executed = 0;
    }

    printf("\nTable:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf(" Process | Arrival Time | Burst Time | Priority | Waiting Time | Execution\n");
    printf("--------------------------------------------------------------------------------\n");

    float current_time = 0;
    int executed = 0;
    int execution_sequence[num_processes];
    int sequence_index = 0;
    while (executed < num_processes) {
        calculate_priority(processes, num_processes, total_waiting_time, current_time);
        int next_process = -1;
        float highest_priority = -1;

        for (i = 0; i < num_processes; i++) {
            if (processes[i].priority > highest_priority && processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                highest_priority = processes[i].priority;
                next_process = i;
            }
        }

        if (next_process != -1) {
            processes[next_process].waiting_time += current_time - processes[next_process].arrival_time;
            printf("   P%d    |     %.2f     |    %.2f    |   %.2f   |    %.2f      |   %.2f-%.2f\n",
                   processes[next_process].id, processes[next_process].arrival_time,
                   processes[next_process].burst_time, processes[next_process].priority,
                   processes[next_process].waiting_time, current_time, current_time + processes[next_process].burst_time);
            current_time += processes[next_process].burst_time;
            executed++;

            processes[next_process].burst_time = 0;
            processes[next_process].executed = 1;

            
            execution_sequence[sequence_index] = processes[next_process].id;
            sequence_index++;
        } else {
            current_time += 0.01; 
        }
    }

    
    printf("\nGantt Chart:\n");
    printf("\n--------------------------\n");
    printf("| ");
    for (i = 0; i < num_processes; i++) {
        printf("P%d", execution_sequence[i]);
        if (i < num_processes - 1) {
            printf(" | ");
        }
    }
    printf(" |");
    printf("\n--------------------------");
	printf("\n");
    
    float total_waiting_time_sum = 0;
    for (i = 0; i < num_processes; i++) {
        total_waiting_time_sum += processes[i].waiting_time;
    }
    float average_waiting_time = total_waiting_time_sum / num_processes;

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);

    return 0;
}

