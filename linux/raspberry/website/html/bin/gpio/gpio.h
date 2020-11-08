#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define PIN_MUTE 17
#define PIN_ENABLE 27
#define PIN_POWER 22

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1
