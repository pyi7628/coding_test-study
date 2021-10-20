import pandas as pd
import numpy as np


n = []
p = []
items = ["A", "B", "C", "D"]
groups = ["A", "AB", "AC", "BC",
          "CD", "ABC", "ACD", "BCD", "ABCD"]


def find_item_index(str):
    for i in range(len(items)):
        if items[i] == str:
            return i
    return -1


def find_group_index(str):
    if len(str) == 1:
        return 0
    for i in range(len(groups)):
        if groups[i] == str:
            return i
    return -1


def p2(k):
    n = k.values
    p = []
    for i in range(0, 4):
        a = (n[i, 1:5])
        b = a.tolist()
        p.append(b)

    input_arr = p

    for i in range(0, 4):
        for j in range(0, 4):
            if input_arr[i][j] == 1:
                input_arr[j][i] = 1
    print("input", input_arr)

    q = []
    index_size = len(groups)
    output_arr = [[0] * index_size for _ in range(index_size)]

    for item in items:
        q.append(item)

    while len(q) != 0:
        cur_group = q.pop(0)
        cur_group_idx = find_group_index(cur_group)

        for i in range(len(cur_group)):
            item_idx = find_item_index(cur_group[i])

            for j in range(len(input_arr[item_idx])):
                temp = cur_group
                next_group = ""

                if input_arr[item_idx][j] == 1:
                    temp += items[j]
                    l = list(temp)
                    l.sort()

                    for v in l:
                        next_group += v

                group_idx = find_group_index(next_group)

                if group_idx != -1 and output_arr[cur_group_idx][group_idx] == 0:
                    output_arr[cur_group_idx][group_idx] = 1
                    q.append(next_group)

    for i in range(len(output_arr)):
        print(output_arr[i])
    return output_arr
