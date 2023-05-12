#include <stdarg.h>

double sum(int count, ...) {
    va_list args;
    double result = 0.0;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double max(int count, ...) {
    va_list args;
    double result, value;
    va_start(args, count);
    result = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        value = va_arg(args, double);
        if (value > result) {
            result = value;
        }
    }
    va_end(args);
    return result;
}

double min(int count, ...) {
    va_list args;
    double result, value;
    va_start(args, count);
    result = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        value = va_arg(args, double);
        if (value < result) {
            result = value;
        }
    }
    va_end(args);
    return result;
}

double average(int count, ...) {
    va_list args;
    double result = 0.0;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }
    va_end(args);
    return result / count;
}
