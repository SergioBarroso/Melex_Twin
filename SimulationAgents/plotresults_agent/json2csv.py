import pandas as pd
file_name = "vel"

df = pd.read_json (file_name+".json")
df.to_csv (file_name+".csv", index = None)
