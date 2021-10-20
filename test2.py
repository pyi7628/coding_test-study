import pandas as pd
import numpy as np
import S


df = pd.read_csv("p2_data.csv")
result = S.p2(df)
print(result)
