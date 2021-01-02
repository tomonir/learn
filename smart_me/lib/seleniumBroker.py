from lib.logger import Logger
import importlib

logger = Logger()


class Command(object):
    def __init__(self,fileds,url):
        self.fields = fileds
        self.url = url
    def process(self):
        pass
    
class textFiled(Command):
    def __init__(self,fields,url):
        super(self.__class__, self).__init__(fields,url)

    def process(self):
        print (self.fields)    
        
class search_button(Command):
    def __init__(self,fields,url):
        super(self.__class__, self).__init__(fields,url)
                    
    def process(self):
        print (self.fields)
          
class output(Command):
    def __init__(self,fields,url):
        super(self.__class__, self).__init__(fields,url)
                    
    def getOutput(self):
        return  (self.fields)



class SeleniumBroker:
    def __init__(self):
        pass
    
    def getSearchOutput(self,config):
        #print config
        url=config["url"]

        try:
            url=config["url"]
        except:
            logger.getLogger(__name__).error('url NOT FOUND!')
            return ""

        try:
            self.__prepareSearchSetup(config["search_setup"],url)
        except:
            logger.getLogger(__name__).debug('search_setup NOT FOUND!')
            
        try:
            self.__prepareAction(config["action"],url)
        except:
            logger.getLogger(__name__).debug('action NOT FOUND!')
            
        try:
            return self.__prepareOutput(config["search_output"],url)
        except:
            logger.getLogger(__name__).debug('search_output NOT FOUND!')
            return "" 
                               
               
    def __prepareSearchSetup(self,config,url):        
        for fileds  in config:
            for filed  in fileds:
                if (filed=="textFiled"):
                    textFiled(fileds,url).process()                    
                    
    def __prepareAction(self,fileds,url):
        search_button(fileds,url).process()
                    
                                                    
    def __prepareOutput(self,fileds,url):
        return output(fileds,url).getOutput()    