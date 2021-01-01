import pandas as pd

class Finder():
    def __init__(self,filepath='../teledb_cleaned.csv'):
        print('booting up...')
        self.df = pd.read_csv(filepath)
        print('ready to go!')

    def _print_index_of_chunk (self,chunk,index):
        print('---------------------')
        print('number_id: ' + str(chunk['number_id'].iloc[index]))
        print('tele_id: ' + str(chunk['tele_id'].iloc[index]))
        print('phone: +' + str(chunk['phone'].iloc[index]))
        print('---------------------')
    
    def _lower_case_column(self,column_name='tele_id'):
        df.loc[:,column_name] = df[column_name].map(lambda x: x.lower() if (isinstance(x,str) and len(x)!=0) else x)

    def _fill_Nan_with_not_availble(self,column_name='tele_id'):
        self.df['tele_id'] = self.df['tele_id'].fillna('N/A')

    def _save_df(self,filepath='./teledb_final.csv'):
        print('saving... do not kill process!')
        self.df.to_csv(filepath,index=False)

    def run(self):
        command = ''
        while (command != 'exit'):
            print('what do you want to search by?(to quit type "exit")')
            command = input('number_id    tele_id    phone: ').split()
            com = command[0].lower()
            if (com == 'exit'):
                print('goodbye!')
                exit()
            elif (com in ['number_id','tele_id','phone']):
                findby = input('now input the ' + com + ': ').strip()
                if (com == 'tele_id'):
                    findby = findby.lower()
                    chunk = self.df[self.df[com].str.find(findby) != -1]
                    chunk = chunk.dropna()
                else:
                    if (findby[0] == '+'):
                        findby = findby[1:]
                    findby = int(findby)
                    chunk = self.df[self.df[com] == findby]
                if (len(chunk) == 0):
                    print('sorry :( we did not find a match. maybe they changed the id')
                elif(len(chunk) == 1):
                    print('\nfound it! here he/she is:')
                    self._print_index_of_chunk(chunk,0)
                    ans = input('anything else?(Y/n)').strip().lower()
                    if (ans == 'n'):
                        print('goodbye!')
                        exit()
                else:
                    print('found more than one match!')
                    ans = input('print them all?(Y/n)').strip().lower()
                    if (ans == 'y'):
                        no_rep = []
                        for i in range(len(chunk)):
                            if (chunk['number_id'].iloc[i] not in no_rep):
                                no_rep.append(chunk['number_id'].iloc[i])
                                self._print_index_of_chunk(chunk,i)
            else:
                print('invalid command')

f = Finder()
f.run()