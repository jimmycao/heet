import torch
import torch.nn as nn

class MyModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(2, 5)
        self.fc2 = nn.Linear(5, 2)

    def forward(self, x):
        x = self.fc1(x)
        x = self.fc2(x)
        return x

def test_save():
    model = MyModel()
    state_dict = model.state_dict(prefix="chj_", keep_vars=False)
    print(state_dict)
    torch.save(model.state_dict(), "model.pth")
    """
    state_dict(*, prefix: str = '', keep_vars: bool = False)，
    储存了模型所有可训练参数，包括权重、偏置、优化器等参数。
    prefix-添加到参数和缓冲区名称的前缀，用于构成 state_dict 中的键。默认值：''。
    keep_vars- 默认情况下，在状态字典中返回的 Tensor 与 autograd 分离。如果将其设置为 True，则不会执行分离。默认值：False。
    """
def test_load():
    model = MyModel()
    model.load_state_dict(torch.load("model.pth"))
    torch.save(model.state_dict(), "model3.pth")
    model.eval()  # 切换到推理模式

if __name__ == "__main__":
    # test_save()
    test_load()

