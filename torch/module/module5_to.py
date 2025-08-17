import random

import torch
import torch.nn as nn

class MyModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(10, 5)
        self.fc2 = nn.Linear(5, 1)

    def forward(self, x):
        x = self.fc1(x)
        x = torch.relu(x)
        x = self.fc2(x)
        return x

def test_to():
    model = MyModel()
    """
    device（可选）:目标设备：torch.device('cpu')、torch.device('cuda')、torch.device('cuda:0')（指定 GPU 索引）
    dtype（可选）:目标数据类型：torch.float32、torch.float16（半精度）、torch.bfloat16 等
    non_blocking（默认为 False）:是否异步传输数据（通常用于 CPU→GPU 传输，需配合DataLoader 的 pin_memory=True）
    """
    # 检查 GPU 可用性
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

    # 数据也需同步迁移！
    input_data1 = torch.randn(3, 10)
    input_data1 = input_data1.to(device, dtype=torch.float32)
    model.to(device)
    # model.to(input_data1)
    output1 = model(input_data1)
    print(output1)

    # # 通过张量指定设备和类型
    input_data2 = torch.randn(3, 10, device='cpu', dtype=torch.float16)
    model.to(device=device, dtype=torch.float16, non_blocking=False)
    output2 = model(input_data2)  # 自动匹配设备和 dtype
    print(output2)

    model.train()

    # save
    state_dict = model.state_dict(prefix="chj2_", keep_vars=False)
    print(state_dict)
    torch.save(model.state_dict(), "model9.pth")


if __name__ == "__main__":
    test_to()

