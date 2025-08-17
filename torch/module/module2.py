import torch
import torch.nn as nn

class MyModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Sequential()
        self.conv.add_module("conv_1", nn.Conv1d(in_channels=3, out_channels=9, kernel_size=5))
        self.conv.add_module("pool_1", nn.MaxPool1d(kernel_size = 2))
        self.conv.add_module("relu_1", nn.ReLU())

        self.dense = nn.Sequential()
        self.dense.add_module("flatten", nn.Flatten())
        self.dense.add_module("linear", nn.Linear(200, 1))

    def forward(self, x):
        x = self.conv(x)
        y = self.dense(x)
        return y

def test_children():
    net = MyModel()

    i = 0
    for child in net.children():
        i += 1
        print(child, "\n")
    print("child number:", i)

def test_named_children():
    net = MyModel()

    i = 0
    for name, child in net.named_children():
        i += 1
        print(f"{name}: {child}")
    print(f"child number:{i}")

def test_modules():
    net = MyModel()

    for module in net.modules():
        print(module)

def test_named_parameters():
    net = MyModel()

    for module in net.named_parameters():
    # for module in net.parameters():
        print(module)

if __name__ == "__main__":
    # test_children()
    # print("=" * 20)
    # test_named_children()
    # print("=" * 20)
    # test_modules()
    # print("=" * 20)
    test_named_parameters()


