from typing import List, Tuple

class Solution1:
    def highest_load_servers(self, server_num: int, messages: List[Tuple[int, int]]) -> List[int]:
        sorted_msgs = sorted(messages, key=lambda x: x[0])
        print(sorted_msgs)

        server_available_time = [0] * server_num
        server_total_load = [0] * server_num

        next_sid: int = 0
        for start, duration in sorted_msgs:
            print(f"start:{start}, duration:{duration}")

            tried_times = 0
            while tried_times <= server_num:
                tried_times += 1
                next_sid = next_sid if next_sid < server_num else next_sid % server_num
                if server_available_time[next_sid] > start:
                    next_sid += 1
                else:
                    server_available_time[next_sid] += duration
                    server_total_load[next_sid] += duration
                    next_sid += 1
                    break

        result = []
        max_load = max(server_total_load)
        for idx, value in enumerate(server_total_load):
            if value == max_load:
                result.append(idx+1)
        return result


class Solution2:
    def highest_load_servers(self, server_num: int, messages: List[Tuple[int, int]]) -> List[int]:
        sorted_msgs = sorted(messages, key=lambda x: x[0])
        print(sorted_msgs)

        server_available_time = [0] * server_num
        server_total_load = [0] * server_num

        next_sid: int = 0
        for start, duration in sorted_msgs:
            print(f"start:{start}, duration:{duration}")

            for tried_num in range(0, server_num):
                next_sid += tried_num
                next_sid = next_sid if next_sid < server_num else next_sid % server_num
                if server_available_time[next_sid] <= start:
                    server_available_time[next_sid] += duration
                    server_total_load[next_sid] += duration
                    print(f"next_sid: {next_sid}, avaliable_time: {server_available_time[next_sid]}, load: {server_total_load[next_sid]}")
                    next_sid += 1
                    break

        result = []
        max_load = max(server_total_load)
        for idx, value in enumerate(server_total_load):
            if value == max_load:
                result.append(idx+1)

        return result

def test1():
    sn = Solution1()
    server_num = 3
    messages = [(1, 15), (2, 10), (12, 10), (5, 10), (6, 10), (30, 15), (32, 10)]
    result = sn.highest_load_servers(server_num, messages)
    print(result)

def test2():
    sn = Solution2()
    server_num = 3
    messages = [(1, 15), (2, 10), (12, 10), (5, 10), (6, 10), (30, 15), (32, 10)]
    result = sn.highest_load_servers(server_num, messages)
    print(result)

if __name__ == "__main__":
    # test1()
    test2()