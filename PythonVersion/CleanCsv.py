import pandas as pd
import sys
import os

class CleanCsv():
    def __init__(self, filepath, options):
        print('reading csv...')
        self.df = pd.read_csv(filepath)
        print('done')
        self.options = options

    def clean(self):
        print('cleaning...')
        for option in self.options:
            if (option == 'dd'):
                print('dropping duplicates...')
                self.df = self.df.drop_duplicates()
                print('done')
            elif(option == 'dn'):
                print('dropping nans...')
                self.df = self.df.drop_duplicates()
                print('done')
            print('\n')
        print('done cleaning.')
        self.__save()

    def __save(self):
        print('saving csv...')
        self.df.to_csv('../cleaned_file.csv',index=False)
        print('done')

if (__name__ == '__main__'):
    if (len(sys.argv) < 3):
        if (len(sys.argv) < 2):
            print('no values args were provided!\nusage: \n    $ python3 CleanCsv.py <filepath> <options>\nuse -h for help')
        elif (sys.argv[1] == '-h' or sys.argv[1] == '--help'):
            print('options: \n\t"dd": drop duplicates\n\t"dn": drop rows including nan')
        else:
            print('no values args were provided!\nusage: \n    $ python3 CleanCsv.py <filepath> <options>\nuse -h for help')
        exit()
    filepath = sys.argv[1]
    options = sys.argv[2:]
    cleaner = CleanCsv(filepath, options)
    cleaner.clean()