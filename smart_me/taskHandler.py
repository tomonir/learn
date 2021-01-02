from agents.jobalert import JobAlert
from agents.contentMonitor import ContentMonitor
   
class TaskHandler:
    def __init__(self,taskName,config=None):
               
        if (config == None):
            if (taskName == "JobAlert"):
                self.taskObject= JobAlert()
            elif (taskName == "ContentMonitor"):
                self.taskObject= ContentMonitor()
        else:
            if (taskName == "JobAlert"):
                self.taskObject= JobAlert(config)
            elif (taskName == "ContentMonitor"):
                self.taskObject= ContentMonitor(config)    
   
    def execute(self):
        self.taskObject.execute()    