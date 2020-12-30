from lib.logger import Logger
from lib.agentConfigHandler import AgentConfigHandler
from lib.seleniumBroker import SeleniumBroker
from task import Task



class JobAlert(Task):
    def __init__(self,config=None):
        self.__config()
        self.logger = Logger()
        if (config==None):
            self.configHandler = AgentConfigHandler("./agents/jobs")
        else:
            self.configHandler = AgentConfigHandler("./agents/jobs",config)
        self.seleniumBroker= SeleniumBroker()
        
    def execute(self):
        for config in  self.configHandler.getJobsConfig():
            self.seleniumBroker.getSearchOutput(config)
        self.logger.getLogger(__name__).debug('Job alert is executing')
        
    def __config(self):
        pass
    
    def action(self):
        pass
        