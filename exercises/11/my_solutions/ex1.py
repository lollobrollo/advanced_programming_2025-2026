#!/usr/bin/env python3

from math import sin


def step_counter(func):

    def wrapper(*args, **kwargs):
        og_gen = func(*args, **kwargs)
        counter = 0
        while True:
            counter += 1
            print(f"current step: {counter}")
            yield next(og_gen)

    return wrapper


@step_counter
def explicit_euler(u0, h):
    u = u0
    while True:
        u = u - h * sin(u)
        yield u


u0 = 1
h = 0.1
wrapped_gen = explicit_euler(u0, h)
for _ in range(10):
    print(f"  value: {next(wrapped_gen)}")