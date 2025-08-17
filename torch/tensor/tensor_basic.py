import torch
import numpy as np

def test_tensor_from_data():
    data = [[1, 2],[3, 4]]
    x_data = torch.tensor(data)
    print(x_data)

def test_tensor_from_np():
    data = [[1, 2], [3, 4]]
    np_array = np.array(data)
    x_np = torch.from_numpy(np_array)
    print(x_np)

def test_tensor_from_other():
    x_data = torch.tensor([[1, 2],[3, 4]])
    x_ones = torch.ones_like(x_data)  # retains the properties of x_data
    print(f"Ones Tensor: \n {x_ones} \n")

    x_rand = torch.rand_like(x_data, dtype=torch.float)  # overrides the datatype of x_data
    print(f"Random Tensor: \n {x_rand} \n")

def test_tensor_with_shape():
    shape = (2, 3,)
    rand_tensor = torch.rand(shape)
    ones_tensor = torch.ones(shape)
    zeros_tensor = torch.zeros(shape)

    print(f"Random Tensor: \n {rand_tensor} \n")
    print(f"Ones Tensor: \n {ones_tensor} \n")
    print(f"Zeros Tensor: \n {zeros_tensor}")

def test_tensor_attr():
    tensor = torch.rand(3, 4)

    print(f"Shape of tensor: {tensor.shape}")
    print(f"Datatype of tensor: {tensor.dtype}")
    print(f"Device tensor is stored on: {tensor.device}")

if __name__ == "__main__":
    # test_tensor_from_data()
    # test_tensor_from_np()
    # test_tensor_from_other()
    # test_tensor_with_shape()
    test_tensor_attr()