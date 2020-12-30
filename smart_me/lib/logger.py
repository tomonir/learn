import logging
import logging.config

    
    
class Logger(object):
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            #print('Creating the object')
            cls._instance = super(Logger, cls).__new__(cls)
            # Put any initialization here.
            logging.config.fileConfig(fname='lib/logger.conf', disable_existing_loggers=False)
        return cls._instance
    
    def getLogger(self,caller_class):
        return logging.getLogger(caller_class)        
            