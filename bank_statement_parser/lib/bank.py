import abc

class Bank(abc.ABC):
    @abc.abstractmethod
    def parse(self,folder_path):
        pass