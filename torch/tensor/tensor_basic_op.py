import torch

def test_tensor_slice():
    tensor = torch.ones(4, 4)
    print(f"First row: {tensor[0]}")
    print(f"First column: {tensor[:, 0]}")
    print(f"Last column: {tensor[..., -1]}")
    tensor[:, 1] = 0
    print(tensor)

def test_tensor_cat_stack():
    tensor = torch.ones(4, 4)

    concated_tensor = torch.cat([tensor, tensor, tensor], dim=1)
    print(concated_tensor)

    stacked_tensor = torch.stack([tensor, tensor, tensor])
    print(stacked_tensor)

def test_tensor_matmul_mul():
    tensor = torch.ones(4, 4)

    y1 = tensor @ tensor.T
    print(y1)

    y2 = tensor.matmul(tensor.T)
    print(y2)

    y3 = torch.rand_like(y1)
    print(y3)
    torch.matmul(tensor, tensor.T, out=y3)
    print(y3)

def test_tensor_mul():
    tensor = torch.ones(4, 4)
    # This computes the element-wise product. z1, z2, z3 will have the same value
    z1 = tensor * tensor
    print(z1)
    z2 = tensor.mul(tensor)
    print(z2)
    z3 = torch.rand_like(tensor)
    torch.mul(tensor, tensor, out=z3)
    print(z3)

def test_tensor_sum():
    tensor = torch.ones(4, 4)
    agg = tensor.sum()
    print(agg)
    agg_item = agg.item()  # convert it to a Python numerical value using item()
    print(agg_item, type(agg_item))

def test_tensor_in_place():
    """
    In-place operations Operations that store the result into the operand are called in-place.
    They are denoted by a _ suffix. For example: x.copy_(y), x.t_(), will change x.

    In-place operations save some memory, but can be problematic when computing derivatives
    because of an immediate loss of history. Hence, their use is discouraged.
    """
    tensor = torch.ones(4, 4)
    tensor[:, 1] = 0
    print(tensor)
    tensor.add_(5)
    print(tensor)

if __name__ == "__main__":
    # test_tensor_slice()
    # test_tensor_cat_stack()
    # test_tensor_matmul_mul()
    # test_tensor_mul()
    # test_tensor_sum()
    test_tensor_in_place()
