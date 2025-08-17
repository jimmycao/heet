from typing import Set

def test1():
    lst = [9, 1, 2, 5, 3, 4, 5, 4]
    lst = list(set(lst))
    print(lst)


def test2():
    lst = [9, 1, 2, 5, 3, 4, 5, 4]
    my_set = set(lst)
    my_set.add(0)
    my_set.remove(2)
    print(list(my_set))

if __name__ == "__main__":
    test1()
    test2()