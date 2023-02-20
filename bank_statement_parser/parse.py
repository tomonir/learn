
import argparse
from lib.postbank import PostbankParser









def main():
    parser = argparse.ArgumentParser(description='A simple script to get command-line arguments')
    parser.add_argument('-n', '--bankname', type=str, help='Name of the Bank')
    parser.add_argument('-p', '--folder_path', type=str, help='Folder path')
    args = parser.parse_args()

    obj_parser = None
    folder_path = ""
    if args.bankname:
        if (args.bankname== 'postbank'):
           obj_parser = PostbankParser()
    if args.folder_path:
        folder_path = args.folder_path

    
    if (obj_parser != None):
        obj_parser.parse(folder_path)
    else:
        print ("No parser found for the bank!")
        exit()

if __name__ == '__main__':
    main()