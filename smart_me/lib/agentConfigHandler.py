import json
import os
from lib.logger import Logger

class AgentConfigHandler:
    def __init__(self,configFolderPath,configFilePath=None):
        self.logger = Logger()
        self.jobConfigList = []
        
        if (configFilePath == None):              
            self.__loadConfigFromAFolder(configFolderPath)
        else:
            self.__loadConfigFromAFile(configFilePath)    

    def __loadConfigFromAFile(self,configFilePath):
        try:
            with open(configFilePath, "r") as read_file:
                try:
                    config= json.load(read_file)
                except:
                    self.logger.getLogger(__name__).error('Inccorect Json file '+configFilePath)
                    return
                self.jobConfigList.append(config)
        except:
            self.logger.getLogger(__name__).error('File not found !! '+configFilePath)
            return
            
    def __loadConfigFromAFolder(self,configFolderPath):
        for r, d, f in os.walk(configFolderPath):
            for file in f:
                if '.json' in file:
                    with open(configFolderPath+"/"+file, "r") as read_file:
                        try:
                            config= json.load(read_file)
                        except:
                            self.logger.getLogger(__name__).error('Inccorect Json file '+configFolderPath+"/"+file)
                            continue
                        self.jobConfigList.append(config)
                        
    def getJobsConfig(self):
        return self.jobConfigList