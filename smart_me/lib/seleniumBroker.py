from lib.logger import Logger
class SeleniumBroker:
    def __init__(self):
        self.logger = Logger()
    
    def getSearchOutput(self,config):
        print config