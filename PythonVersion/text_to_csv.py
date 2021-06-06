from tqdm import tqdm
import pandas as pd

file = open("../TeleDB_light.txt", "r")
print('opened file')

lines = file.readlines()
print('read lines')
file.close()
out_df = pd.DataFrame(columns =  ['number_id','telegram_id','phone'])
print(lines[0])
print(lines[1])
print(lines[2])
print(lines[3])
print(lines[-4])
print(lines[-3])
print(lines[-2])
print(lines[-1])
print(len(lines))

# for i in tqdm(range(1,len(lines)-2)):
#     x = lines[i].split()
#     num_id = x[1]
#     num_id = num_id[:-1]
#     if (len(x[3]) == 3):
#         tele_id = 'N/A'
#     else:
#         tele_id = x[3]
#         tele_id = tele_id[1:-2]
#     phone_no = x[5]
#     phone_no = phone_no[1:-2]
#     out_df = out_df.append({'number_id':num_id,'telegram_id':tele_id, 'phone' : phone_no},ignore_index=True)

# out_df.to_csv('./teledb.csv')