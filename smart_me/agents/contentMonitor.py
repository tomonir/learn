from lib.logger import Logger
from task import Task

class ContentMonitor(Task):
    def __init__(self):
        self.__config()
        self.logger = Logger()
        
    def execute(self):
        self.logger.getLogger(__name__).debug ("Content Monitor is executing")
        
    def __config(self):
        pass
    
    def action(self):
        pass
        