import torch
import torch.nn as nn
import torch.nn.functional as F

@torch.no_grad()
def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)
        print(m.weight)

"""
apply(fn)：用于递归地对模块及子模块应用自定义函数。
常见的应用场景：权重初始化；参数训练，冻结；自定义操作；批量修改模块状态
"""
net = nn.Sequential(nn.Linear(2, 3), nn.Linear(3, 2))
net.apply(init_weights)
