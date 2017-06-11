/**
 * @file cpuidle.c
 * @author wangguibao
 * @date 2017/06/08 15:06:18
 * @brief Periodicallly output system CPU IDLE percentage, by consecutively
 * reading /proc/stat fields.
 *
 * Idea from https://stackoverflow.com/questions/3017162/how-to-get-total-cpu-usage-in-linux-c
 *  
 **/
#include <stdio.h>
#include <unistd.h>

#define CPU_STAT_FIELDS 9   // 9 columns since 2.6.24

int read_proc_stat(unsigned long long *user_jiffies,
                unsigned long long *nice_jiffies,
                unsigned long long *system_jiffies,
                unsigned long long *idle_jiffies,
                unsigned long long *iowait_jiffies,
                unsigned long long *irq_jiffies,
                unsigned long long *softirq_jiffies)
{
    unsigned long long fields[CPU_STAT_FIELDS];

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1;
    }

    int nrecords = fscanf(fp,
                        "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",
                        &fields[0],
                        &fields[1],
                        &fields[2],
                        &fields[3],
                        &fields[4],
                        &fields[5],
                        &fields[6],
                        &fields[7],
                        &fields[8]);
    fclose(fp);

    if (nrecords != CPU_STAT_FIELDS) {
        return -1;
    }

    *user_jiffies = fields[0];
    *nice_jiffies = fields[1];
    *system_jiffies = fields[2];
    *idle_jiffies = fields[3];
    *iowait_jiffies = fields[4];
    *irq_jiffies = fields[5];
    *softirq_jiffies = fields[6];

    return 0;
}

int main()
{
    unsigned long long user_jiffies[2];
    unsigned long long nice_jiffies[2];
    unsigned long long system_jiffies[2];
    unsigned long long idle_jiffies[2];
    unsigned long long iowait_jiffies[2];
    unsigned long long irq_jiffies[2];
    unsigned long long softirq_jiffies[2];
    unsigned long long total_jiffies[2];
    double idle = 0.0;

    int ret = read_proc_stat(&user_jiffies[0],
                            &nice_jiffies[0],
                            &system_jiffies[0],
                            &idle_jiffies[0],
                            &iowait_jiffies[0],
                            &irq_jiffies[0],
                            &softirq_jiffies[0]);
    if (ret != 0) {
        fprintf(stderr, "Read /proc/stat fail\n");
        return -1;
    }
    total_jiffies[0] = user_jiffies[0]
                    + nice_jiffies[0]
                    + system_jiffies[0]
                    + idle_jiffies[0]
                    + iowait_jiffies[0]
                    + irq_jiffies[0]
                    + softirq_jiffies[0];

    while (1) {
        sleep(2);
        ret = read_proc_stat(&user_jiffies[1],
                            &nice_jiffies[1],
                            &system_jiffies[1],
                            &idle_jiffies[1],
                            &iowait_jiffies[1],
                            &irq_jiffies[1],
                            &softirq_jiffies[1]);
        if (ret != 0) {
            fprintf(stderr, "Read /proc/stat fail\n");
            return -1;
        }

        total_jiffies[1] = user_jiffies[1]
                                    + nice_jiffies[1]
                                    + system_jiffies[1]
                                    + idle_jiffies[1]
                                    + iowait_jiffies[1]
                                    + irq_jiffies[1]
                                    + softirq_jiffies[1];
        idle = (double)(idle_jiffies[1] - idle_jiffies[0])
                / (double)(total_jiffies[1] - total_jiffies[0]);
        idle = idle * 100.0;
        fprintf(stdout, "%.1f%%\n", idle);

        user_jiffies[0] = user_jiffies[1];
        nice_jiffies[0] = nice_jiffies[1];
        system_jiffies[0] = nice_jiffies[1];
        idle_jiffies[0] = idle_jiffies[1];
        iowait_jiffies[0] = iowait_jiffies[1];
        irq_jiffies[0] = irq_jiffies[1];
        softirq_jiffies[0] = softirq_jiffies[1];
        total_jiffies[0] = total_jiffies[1];
    }

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
