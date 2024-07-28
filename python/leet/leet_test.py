import time

COUNT = 50 * 1000 * 1000

def countdown(n):
    while n > 0:
        n -= 1

if '__name__ == __main__':
    start = time.time()
    countdown(COUNT)
    end = time.time()
    print('timecost:', end-start)
