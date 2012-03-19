/*
 * cpu_usage_curve.c - controls the system task manager CPU usage curve
 */
#include <windows.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1415926
#define MAX_AMP     100

int main()
{
    long long int current_time;
    long long int start_time = GetTickCount();
    long long int busy;
    int i = 0;

    while (1) {
        while (GetTickCount() - start_time < 100) {
            busy = (sin((2 * PI) * i / 200) + 1) * MAX_AMP;
            current_time = GetTickCount();
            while (GetTickCount() - current_time < busy) {
            }
            Sleep(2* MAX_AMP - busy);
        }
        i++;
        if (i >= 200) {
            i = 0;
        }
        start_time = GetTickCount();
    }

    return 0;
}
