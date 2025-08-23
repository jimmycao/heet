from functools import wraps
from time import perf_counter, sleep

def log_timecost(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        """just a wrapper"""
        start = perf_counter()
        func(*args, *kwargs)
        end = perf_counter()
        print(f"time_cost(s): {end-start}")
    return wrapper

@log_timecost
def say_hi(name: str):
    """say hi func"""
    sleep(1)
    print(f"Hi, {name}")

if __name__ == "__main__":
    name = "jimmy"
    say_hi(name)
    print(f"{say_hi.__name__}")
    print(f"{say_hi.__doc__}")