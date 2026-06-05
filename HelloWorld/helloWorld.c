#include <vxWorks.h>
#include <stdio.h>
#include <taskLib.h>

void myTask(void)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Hello from VxWorks! Count: %d\n", i);
        taskDelay(60);   /* delay 1 second (60 ticks at 60Hz) */
    }
}

void startMyTask(void)
{
    taskSpawn(
        "tMyTask",       /* task name */
        100,             /* priority (0=highest, 255=lowest) */
        0,               /* options */
        4096,            /* stack size in bytes */
        (FUNCPTR)myTask, /* entry point */
        0,0,0,0,0,0,0,0,0,0 /* 10 arguments (unused) */
    );
}