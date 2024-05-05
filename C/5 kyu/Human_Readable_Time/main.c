#include <stdio.h>

#define HOUR_SECONDS 3600
#define MINUTES_SECONDS 60

/**
 * Human Readable Time
 *
 * Write a function, which takes a non-negative integer (seconds) as input and returns the time in a human-readable format (HH:MM:SS)
 *
 * HH = hours, padded to 2 digits, range: 00 - 99
 * MM = minutes, padded to 2 digits, range: 00 - 59
 * SS = seconds, padded to 2 digits, range: 00 - 59
 * The maximum time never exceeds 359999 (99:59:59)
 *
 * You can find some examples in the test fixtures.
 */


void test(int input_seconds)
{
    int hours = input_seconds / HOUR_SECONDS;
    if (hours) {
        input_seconds -= HOUR_SECONDS * hours;
    }

    int minutes = input_seconds / MINUTES_SECONDS;
    if (minutes) {
        input_seconds -= MINUTES_SECONDS * minutes;
    }

    int seconds = input_seconds;

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
}

int main()
{
    test(7123);
    return 0;
}
