import sys, getopt

from taskHandler import TaskHandler
from lib.logger import Logger


def main(argv):
    logger = Logger()
    try:
        opts, args = getopt.getopt(argv,"hi:c:t:",["itask=","oconfig=","trace="])
    except getopt.GetoptError:
        print 'main.py -t <task_name>'
        sys.exit(2)
        
    taskTobeExecute = None
    config          = None
    
         
    for opt, arg in opts:
        if opt == '-h':
            print 'main.py -t <task_name>'
            sys.exit()
        elif opt in ("-t", "--itask"):
            taskTobeExecute = arg     
            #logger.getLogger(__name__).debug('This is a debug message')
        elif opt in ("-c", "--cconfig"):
            config = arg     
        
        
    taskHandler = TaskHandler(taskTobeExecute,config)
    taskHandler.execute()   
        
            
            
            

if __name__ == "__main__":
   main(sys.argv[1:])