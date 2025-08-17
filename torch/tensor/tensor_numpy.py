import torch
import numpy as np

def test_numpy():
    t = torch.ones(5)
    print(f"t: {t}")
    n = t.numpy()
    print(f"n: {n}")

def test_numpy_add():
    t = torch.ones(5)
    print(f"t: {t}")
    n = t.numpy()
    print(f"n: {n}")

    t.add_(5)
    print(f"t: {t}")
    print(f"n: {n}")

def test_from_numpy():
    n = np.ones(5)
    t = torch.from_numpy(n)
    print(t)

    np.add(n, 1, out=n)
    print(f"t: {t}")
    print(f"n: {n}")

if __name__ == "__main__":
    # test_numpy()
    # test_numpy_add()
    test_from_numpy()