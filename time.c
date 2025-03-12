#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdio.h>
int main()
{
    struct tm* local;
    while(1)
    {
        time_t now = time(NULL);
        local = localtime(&now);
        if (local->tm_min > 10 && local->tm_sec > 10)
        {
            printf("%d/%d/%d %d:%d:%d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
                1900 + local->tm_year,
                local->tm_mon + 1,
                local->tm_mday,
                local->tm_hour,
                local->tm_min,
                local->tm_sec
            );
            Sleep(500);
        }
        else if (local->tm_min > 10 && local->tm_sec < 10)
        {
            printf("%d/%d/%d %d:%d:0%d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
                1900 + local->tm_year,
                local->tm_mon + 1,
                local->tm_mday,
                local->tm_hour,
                local->tm_min,
                local->tm_sec
            );
            Sleep(500);
        }
        else if (local->tm_min < 10 && local->tm_sec > 10)
        {
            printf("%d/%d/%d %d:0%d:%d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
                1900 + local->tm_year,
                local->tm_mon + 1,
                local->tm_mday,
                local->tm_hour,
                local->tm_min,
                local->tm_sec
            );
            Sleep(500);
        }
        else if (local->tm_min < 10 && local->tm_sec < 10)
        {
            printf("%d/%d/%d %d:0%d:0%d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
                1900 + local->tm_year,
                local->tm_mon + 1,
                local->tm_mday,
                local->tm_hour,
                local->tm_min,
                local->tm_sec
            );
            Sleep(500);
        }
        else
        {
            printf("%d/%d/%d %d:%d:%d\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
                1900 + local->tm_year,
                local->tm_mon + 1,
                local->tm_mday,
                local->tm_hour,
                local->tm_min,
                local->tm_sec
            );
            Sleep(500);
        }
    }
    return 0;
}